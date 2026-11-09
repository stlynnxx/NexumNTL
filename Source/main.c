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
 *      - This is loading a given user modified values matrix to be used in place of the default values matrix
 *      - Since we have an immutable range and mutable range, I think we can do it by taking it loaded in via
 *      file and taking everything in the mutable range and appending it into the mutable range for the C side
 *      matrix for that given run only.
 *
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
FILE* load_vocab_file(char vocab_path) {
    FILE* vocab_fp = fopen(&vocab_path, "w");
    return vocab_fp;
}

int run(int agency_opt, const char *morpheme, int *encoded_value, int agent_morpheme_opt, int agent_output_opt, char *output,
    size_t output_capacity, char vocab_file_name[256])
{



    /*
     * Globals for cleanup:
     * export_file
     * form
     * pbuffers
     */
    FILE *in_file;
    FILE *export_file;
    int get_filename_return;
    int matrix_parse_return;
    bool matrix_chk = false;
    char letter;
    size_t mutable_count = 0;
    size_t export_capacity = 2;
    char *export_morpheme = malloc(export_capacity);
    Symbols row;
    Options options;
    // Needs cleanup
    InputForm *form = new_input_form();
    // Needs cleanup
    ParserBuffers *pbuffers = pbuffers_init();
    InType intype;
    OutType outtype;
    FILE* vocab_fp;
    size_t length = strnlen(vocab_file_name, 256);
    int result = 0;
    char vocab_path[512];

    if (length >= 256) {
       perror("Vocab filename size error");
        return 0;
    }
    if (length <= 256) {
        result = snprintf(vocab_path, sizeof(vocab_path),
                      "%s/%s", VOCAB_DIR, vocab_file_name);
    }
    if (result < 0) {
        fprintf(stderr, "Path formatting error\n");
    }
    else if ((size_t)result >= sizeof(vocab_path)) {
        fprintf(stderr, "Vocabulary path too long\n");
    }
    else {
        printf("Path: %s\n", vocab_path);
    }

    switch (agency_opt)
    {
        case AGENT: {
            switch (agent_morpheme_opt)
            {
                case RAW_MORP: {
                    if (!morpheme || !morpheme[0]) {
                        return -1;
                    }
                    if (matrix_chk == false) {
                        // agent values matrix upload & append
                        // loads user values matrix into in_file
                        in_file = file_handler(form, 2);
                        // append to runtime matrix
                        matrix_parse_return = matrix_parse(form, in_file);
                        if (matrix_parse_return != 0) {
                            perror("Matrix parsing error");
                            exit(-1);
                        }
                        matrix_chk = true;
                        // preform operations
                        // clear mutable range (or persist with option to clear?)
                    }
                    // Places the raw morpheme into form->wC
                    // in_append_string(form, morpheme, strlen(morpheme), wC_flag);
                    letter = (char)toupper((unsigned char)morpheme[0]);
                    if (row_parse(letter, &row) != 1) {
                        return -1;
                    }
                    size_t rowCapacity = sizeof(valuesMatrix[row]) / sizeof(valuesMatrix[row][0]);
                    for (size_t i = MUTABLE_START; i < rowCapacity; i++) {
                        if (valuesMatrix[row][i] != NULL) {
                            mutable_count++;
                        }
                    }
                    size_t append_idx = MUTABLE_START + mutable_count;
                    char *copy = strdup(morpheme);
                    if (copy == NULL) {
                        return -1;
                    }
                    // raw morph lookup and append
                    // this is for if the morpheme is already present within the mutable range
                    bool found = false;
                    size_t found_idx = 0;
                    for (size_t i = MUTABLE_START; i < append_idx; i++) {
                        if (strcmp(valuesMatrix[row][i], morpheme) == 0) {
                            found = true;
                            found_idx = i;
                            break;
                        }
                    }
                    size_t needed = strlen(copy) + 1;
                    // write to memory for python access
                    if (!output || needed > output_capacity) {
                        if (found) {
                            free(copy);
                        }
                        return -1;
                    }
                    // appending to mutable range
                    if (!found) {
                        if (append_idx >= rowCapacity) {
                            free(copy);
                            return -1;
                        }
                        valuesMatrix[row][append_idx] = copy;
                        found_idx = append_idx;
                    }
                    memcpy(output, copy, needed);
                    if (found) {
                        free(copy);
                    }
                    return 0;
                    break;
                }
                case MATRIX_OPT: {
                    if (!morpheme || !encoded_value) {
                        return -1;
                    }
                    // agent values matrix upload & append
                    // loads user values matrix into in_file
                    in_file = file_handler(form, 2);
                    // append to runtime matrix
                    matrix_parse_return = matrix_parse(form, in_file);
                    if (matrix_parse_return != 0) {
                        perror("Matrix parsing error");
                        exit(-1);
                    }
                    matrix_chk = true;
                    // preform operations
                    // clear mutable range (or persist with option to clear?)
                    break;
                }
                case AGENT_FILE: {
                    if (agent_output_opt == NEX) {
                        outtype = NEX;
                    }
                    if (agent_morpheme_opt == NEXC) {
                        outtype = NEXC;
                    }
                    /* Cleanups for this path:
                             * in_file
                             * export_form
                             */
                    // setting input filename
                    get_filename_return = get_filename(form, outtype, INPUT_OPT);
                    // Here file_handler is scanning the given internal directory
                    // for the in_file and importing it
                    in_file = fopen("Data/Input_Files/Agent_Input", "r");
                    export_file = fopen("Data/Output_Files/Agent_Output", "w");
                    // This chains all the way to the cleanup function
                    comp_from_file_append_bytes(form, pbuffers, in_file,export_file, outtype);
                    fclose(in_file);
                    fclose(export_file);
                    break; // AGENT FILE BREAK
                }
                default:
                    break;
            }



            case ENGRAM_CREATE: {
                EngramAppendFlag engram_append_flag;
                // init engram_store
                EngramStore *store = engram_store_init();
                if (store == NULL) {
                    return EXIT_FAILURE;
                }
                Engram *engram = engram_helpers(store);
                if (!morpheme) {
                    perror("Empty Morpheme error");
                }
                vocab_fp = load_vocab_file(*vocab_path);
                // Parse vocab file
                vocab_file_parse(vocab_fp, engram);
                // Append to something like input
                // Build parent engram
                // build branch for each associator
                break;
            }
            break; // AGENT BREAK
        }
        case HUMAN_OPT:
        {
            // Input collection is a placeholder; this will eventually likely be moved to python
            intype = (InType)read_choice("Enter 0 or 1: ", 0, 1);
            // output replaces nex_code_flag
            outtype = (OutType)read_choice("Enter 0 or 1: ", 0, 1);
            // Setting output filename
            get_filename_return = get_filename(form, outtype, OUTPUT_OPT);
            export_file = file_handler(form,1);
            switch (intype)
            {
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
                    get_filename_return = get_filename(form, outtype, INPUT_OPT);
                    // Here file_handler is scanning the given internal directory
                    // for the in_file and importing it
                    in_file = file_handler(form,0);
                    // This chains all the way to the cleanup function
                    comp_from_file_append_bytes(form, pbuffers, in_file,export_file, outtype);
                    break;
                default:
                    break;

            }
            break;
        }
        default:
            break;
    }
  return 0;
}
