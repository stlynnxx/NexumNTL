# include <stdio.h>
# include "Lexer.h"
# include "SymbolTable.h"
# include "SourceGenerator.h"
# include "Parser.h"




int main_run() {
    // This initiates the Source Generator
    sgRun("Testing2.nex", "Test.nexcode");
    // This initiates the Lexer
    lRun();
    prun();


  return 0;
 }
