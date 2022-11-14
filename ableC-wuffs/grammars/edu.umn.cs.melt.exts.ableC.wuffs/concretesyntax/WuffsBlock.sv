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

    top.ast = wuffs_block( body );
}
