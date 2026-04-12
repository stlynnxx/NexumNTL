# include <stdio.h>
# include "Lexer.h"
# include "SymbolTable.h"
# include "SourceGenerator.h"




int prun() {
    // This initiates the Source Generator
    sgRun("Testing2.nex");
    // This initiates the Lexer
    lRun();
    prun();


  return 0;
 }
