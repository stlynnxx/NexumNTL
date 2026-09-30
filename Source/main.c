# include <stdio.h>
#include "SourceGenerator/SGruninterface.h"
#include "Lexer/Lexer.h"
#include "SymbolTable/SymbolTable.h"
#include "SourceGenerator/SourceGenerator.h"
#include "Parser/Parser.h"
#include "Compressor/compressor.h"

/*
 *Input will be coming in in multiple manners.
 *
 *  Agentic Inputs
 *  Terminal -> nexfile/nexcfile (classic source generation)
 *  Terminal -> usrmor
 *  Nexfile parsing -> append to valuesMatrix
 *
 *  Agentic Inputs
 *  - Agentic Values Matrix Loading
 *  - Morpheme compressing and appending to agentic valuesMatrix
 */

void terminal_to_nexfile() {
    char filepath[4096];
    int nex_code_flag;
    printf("Enter file path for save location: ");
    scanf("%s", filepath);
    printf(".nex or .nexc? (0 for .nex/1 for .nexc)");
    scanf("%s", &nex_code_flag);
    if (nex_code_flag > 1 || nex_code_flag < 0) {
        perror("Incorrect choice");
        exit(-1);
    }
    sgRun(filepath, nex_code_flag, false, 0);
}


int run() {
    // Terminal to Nexfile/Nexcfile
    terminal_to_nexfile();
    // Terminal -> usrmor
    compressor_collect(1);
    // This initiates the Lexer
    lRun();
    prun();


  return 0;
 }
