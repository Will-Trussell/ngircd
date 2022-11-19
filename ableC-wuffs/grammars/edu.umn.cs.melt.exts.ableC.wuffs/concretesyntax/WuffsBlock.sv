grammar edu:umn:cs:melt:exts:ableC:wuffs:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast;

imports edu:umn:cs:melt:exts:ableC:wuffs:abstractsyntax;
import edu:umn:cs:melt:ableC:host;

marking terminal WuffsBegin_t 'WUFFS' ;
terminal WuffsBodyAndEnd_t /.*WUFFS_END/ ;

concrete production wuffs_c
top::Stmt_c ::= 'WUFFS' bodyAndEnd::WuffsBodyAndEnd_t
{
    local body::String = substring(bodyAndEnd.lexeme, 0, length(bodyAndEnd.lexeme) - 9 );
    local compiled::String = unsafePerformIO(compile_wuffs(body));
    
    forwards to case ableCParser(compiled) of
        | parseSucceeded(_) -> 
            ableC_Expr {
                REQUEST req;
                Init_Request (&req);
                
                ngt_Trim_Str( Request );

                if Conf_ScrubCTCP && ScrubCTCP(Request))
                    return true;

                wuffs_base__status status;
                wuffs_parser__parser *p = wuffs_parser__parser__alloc();
                if (!p) {
                    return false;
                }
                wuffs_base__io_buffer iobuf =
                    wuffs_base__ptr_u8__reader((uint8_t*)Request,strlen(Request),true);
                status = wuffs_parser__parser__parse(p, &iobuf);
                if (!wuffs_base__status__is_ok(&status)) {
                    printf("parse: %s\n", wuffs_base_status__message(&status));
                    return Conn_WriteStr(Idx, "ERROR: parsing failed");
                }

                req.prefix = wuffs_parser__parser__get_prefix();
                req.command = wuffs_parser__parser__get_cmd();
                req.argv = wuffs_parser__parser__get_args();
                req.argc = wuffs_parser__parser__get_argc();

                if (!Validate_Prefix(Idx, &req, &closed))
                    return !closed;
                if (!Validate_Command(Idx, &req, &closed))
                    return !closed;
                if (!Validate_Args(Idx, &req, &closed))
                    return !closed;

                return Handle_Request(Idx, &req);
            }

        | _ -> error("Failed to compile wuffs code")
        end;

}

function compile_wuffs
IO<String> ::= wuffs_code::String
{
    return do {
        write_file("parse.wuffs", wuffs_code);

        system("wuffs-c gen -parser_name parser < parse.wuffs > parse_helper.c");
    }
}
