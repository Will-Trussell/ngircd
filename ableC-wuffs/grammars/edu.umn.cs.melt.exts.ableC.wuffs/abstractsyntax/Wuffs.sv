grammar edu:umn:cs:melt:exts:ableC:wuffs:abstractsyntax;

imports edu:umn:cs:melt:ableC:abstractsyntax:host;

abstract production wuffs_block
top::Stmt ::= wuffs_code::String
{
    top.pp = wuffs_compiled( wuffs_code );
}

function wuffs_compiled
Stmt ::= wuffs_code::String
{
    {- 
      Need some way to load the provided Wuffs code into a separate file
      Process is as follows:
      1. Load wuffs code into some parse.wuffs file
      2. Compile that wuffs code into transpiled C code
        This compilation could be using command line or a makefile?
      3. Pull transpiled C code out of whatever file it comes from
      4. Put C code back into the original xc/c file

      Alternative process:
      1. Load wuffs code into some parse.wuffs file
      2. Compile
      3. Call out to wuffs file from original xc/c file
        Probably requires inserting calls manually into xc/c files
        Maybe have to find transpiled function names? Not sure if wuffs maintains
         function names or not
    -}
}
