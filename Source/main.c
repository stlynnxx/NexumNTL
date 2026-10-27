#include <stdio.h>
#include "main.h"

#include <dirent.h>

#include "mainhelpers.h"
#include "SourceGenerator/SGruninterface.h"
#include "Lexer/Lexer.h"
#include "SymbolTable/SymbolTable.h"
#include "SourceGenerator/SourceGenerator.h"
#include "Parser/Parser.h"
#include "Parser/parserhelpers.h"
#include "Compressor/compressor.h"
#include <limits.h>

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

static InputForm* new_input_form() {
    InputForm* input_form = input_init();
    return input_form;
}

void terminal_to_nexfile(InputForm *form, FILE* export_file,int intype) {
    // OutType replaces nex_code_flag
    switch (outType) {
        case NEX:
            sgRun(form, export_file,outType, false, intype);
            break;
        case NEXC:
            sgRun(form, export_file,outType, false, intype);
            break;
        default:
            perror("Invalid output type");
            break;
    }
}



int run() {
    /*
     * Globals for cleanup:
     * export_file
     * form
     * pbuffers
     */
    FILE *in_file;
    FILE *export_file;
    int get_filename_return;
    // Input collection is a placeholder; this will eventually likely be moved to python
    InType intype = (InType)read_choice("Enter 0 or 1: ", 0, 1);
    // output replaces nex_code_flag
    OutType output = (OutType)read_choice("Enter 0 or 1: ", 0, 1);
    Options options;
    // Needs cleanup
    InputForm *form = new_input_form();
    // Setting output filename
    get_filename_return = get_filename(form, output, OUTPUT_OPT);
    export_file = file_handler(form,1);
    // Needs cleanup
    ParserBuffers *pbuffers = pbuffers_init();
    switch (intype) {
        case TERMINAL_IN:
            // This is where terminal -> nex and terminal -> nexc go
            terminal_to_nexfile(form,export_file, intype);
            break;
        case FILE_IN:
            /* Cleanups for this path:
             * in_file
             * export_form
             */
            // setting input filename
            get_filename_return = get_filename(form, output, INPUT_OPT);
            // Here file_handler is scanning the given internal directory
            // for the in_file and importing it
            in_file = file_handler(form,0);
            // This chains all the way to the cleanup function
            comp_from_file_append_bytes(form, pbuffers, in_file,export_file, output);
            break;
        default:
            break;

    }
    // Terminal to Nexfile/Nexcfile
    // OutType Nex, Control 0
    terminal_to_nexfile(form, intype);
    // Terminal -> usrmor
    compressor_collect(form, intype, output);
    // inFile -> .nexc
    compressor_collect(form,intype,output);
    /* Nexfile parsing- append to matrix
     * This should look like loading the file, parsing line by line, and as we go
     * checking for matches and adding unmatched morphemes- let's try reusing as much
     * existing code as possible for this.
     */
    // This initiates the Lexer
    lRun();
    prun();


  return 0;
 }
