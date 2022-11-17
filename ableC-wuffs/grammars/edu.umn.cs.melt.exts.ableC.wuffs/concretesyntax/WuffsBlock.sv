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


function compile_wuffs
IO<String> ::= wuffs_code::String
{
    return do {
        write_file("parse.wuffs", wuffs_code);

        system("wuffs parse.wuffs");

        read_file("output_wuffs.c);
    }
}
