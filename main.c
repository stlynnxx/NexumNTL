# include <stdio.h>
# include "Lexer.h"
# include "SymbolTable.h"
# include "SourceGenerator.h"




int main() {
    // This initiates the Source Generator
    sgRun("Testing2.nex");
    // This initiates the Lexer
    catalyst();

  return 0;
 }
