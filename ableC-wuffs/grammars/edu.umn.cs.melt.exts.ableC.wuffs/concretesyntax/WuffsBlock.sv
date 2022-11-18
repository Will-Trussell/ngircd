grammar edu:umn:cs:melt:exts:ableC:wuffs:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast;

imports edu:umn:cs:melt:exts:ableC:wuffs:abstractsyntax';

marking terminal WuffsBegin_t 'WUFFS' ;
terminal WuffsBodyAndEnd_t /.*WUFFS_END/ ;

concrete production wuffs_c
top::Stmt_c ::= 'WUFFS' bodyAndEnd::WuffsBodyAndEnd_t
{
    local body::String = substring(bodyAndEnd.lexeme, 0, length(bodyAndEnd.lexeme) - 9 );
    local compiled::String = unsafePerformIO(compile_wuffs(body));
    
    forwards to case parser(compiled) of
        | --Success
        | _ -> error()
        end;
    --Need to pattern match on parser results (success or failure)
    --case __ of

}

-- Unsure if we want to pull code back into original c file or if we instead
-- want to leave it as separate helper file, including that in parse_helper.c
-- If left separate, would involve injecting some code into parse.c (not much)
-- Injection would be as follows:
{- 
    insert some PARSE_REQUEST function
    Inside that function, include several things:
        initialization of wuffs_parser__parser
        call to wuffs_parser__parser__parse()
            Pass as args to this the parser and the char * input buffer
        Calls to wuffs_parser__parser__get_prefix/cmd/args/argc
            These values then get passed to the VALIDATE functions already in parse.c
-}
function compile_wuffs
IO<String> ::= wuffs_code::String
{
    return do {
        write_file("parse.wuffs", wuffs_code);

        system("wuffs-c gen -parser_name parser < parse.wuffs > parse_helper.c");

        read_file("output_wuffs.c);
    }
}
