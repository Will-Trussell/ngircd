grammar edu:umn:cs:melt:exts:ableC:asyncIO:concretesyntax;

imports edu:umn:cs:melt:ableC:concretesyntax;
imports edu:umn:cs:melt:exts:ableC:asyncIO:abstractsyntax;
imports edu:umn:cs:melt:exts:ableC:closure:concretesyntax;

marking terminal Spawn_t 'spawn' lexer classes {Keyword};
marking terminal Await_t 'await' lexer classes {Keyword};

concrete production spawn_task_c
top::Expr_c ::= 'spawn' cl::AssignExpr_c
--Check closure, see what nonterminal is for cl
{
  forwards to ableC_expr {
    --AbleC closure code
    --Check to see if we have antiquote for blockItemList (ask Lucas)
    --Ask Lucas about potentially adding new terminal for antiquotation
    task_spawn(lambda () -> void { $blockItemList(cl) })

    --Creates either eventfd or pipe (in task_spawn code)
  }
}

concrete production await_task_c
top::Expr_c ::= 'await' t::PrimaryExpr_c --Possibly a different kind of Expr
{
  forwards to ableC_expr {

    wait_helper_func($Expr(t))
    --Write something using pipes/eventfds to communicate across tasks
    --Reads from pipe once task finishes, read bytes, discard
    --Need helper function, takes in pipe/eventfd, does the read, then closes it
    --Helper funcs probably go somehwere in io.c (probably replace most of file)
  }
}

-- Delete functions from io.h, also clear out io.c
-- Follow compiler errors for refactoring
-- One potential issue: interaction with openSSL ?

{- 
  TODO:
  Tear out functions from io.c
  Replace with functions relating to extension
  Remove function declarations from io.h, replace with new functions
    (Like wait_helper, etc)
  Try to build, track down compiler errors, hope
-}

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
