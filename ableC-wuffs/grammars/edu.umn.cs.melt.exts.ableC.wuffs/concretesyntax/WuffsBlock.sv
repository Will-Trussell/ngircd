grammar edu:umn:cs:melt:exts:ableC:wuffs:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports silver:langutil only ast;

imports edu:umn:cs:melt:exts:ableC:wuffs:abstractsyntax';

marking terminal WuffsBegin_t 'WUFFS' ;
marking terminal WuffsEnd_t 'WUFFS_END' ;

concrete production wuffs_c
s::Stmt_c ::= w::WuffsBegin_t '{' {- What goes here? -} '}' e::WuffsEnd_t
{- 
    What goes between the Wuffs blocks? Do I need to define a new nonterminal? Or
    does the code simply need to be put into some variable/label and passed to the
    wuffsblock abstract production?

    Is it some sort of Expr_c or Stmt_c or other ableC concrete production?

    Probably should ask Nathan tomorrow (Sunday)
-}
{
  s.ast = wuffsblock( ); --Block contains the code in between WUFFS and WUFFS_END from the block.
}
