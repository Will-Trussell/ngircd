grammar edu:umn:cs:melt:exts:ableC:asyncIO:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports edu:umn:cs:melt:exts:ableC:asyncIO:abstractsyntax;
imports edu:umn:cs:melt:exts:ableC:closure:concretesyntax;
terminal Spawn_t 'spawn' lexer classes {Keyword};
terminal Await_t 'await' lexer classes {Keyword};

concrete production spawn_task_c
top::Stmt_c ::= 'spawn' cl::AssignExpr_c
{
  top.ast = <abstract production> (cl) ;
}

{- 
    Notes for what this extension should do:
    - Translate strings down to Nathan's API
    - Specifically, do the following:
      - Probably insert some setup code at the beginning
      - Translate "spawn <some task>" into "task_spawn(<task>)" in the API
      - Need somewhere to include the functions written by Nathan
        - Where do these functions go? Need to set up executor instance, etc
      - After spawning tasks, where we'd normally make a call to wait(), we
        can use the "await" keyword to wait for the task to finish. This is
        analagous to the "task_yield" call in Nathan's API?

-}
