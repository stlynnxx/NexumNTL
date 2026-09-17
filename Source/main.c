# include <stdio.h>
#include "Lexer/Lexer.h"
#include "SymbolTable/SymbolTable.h"
#include "SourceGenerator/SourceGenerator.h"
#include "Parser/Parser.h"




int main_run() {
    // This initiates the Source Generator
    sgRun("Testing2.nex", false);
    // This initiates the Lexer
    lRun();
    prun();


  return 0;
 }
