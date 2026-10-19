#include <stdio.h>
#include "main.h"
#include "SourceGenerator/SGruninterface.h"
#include "Lexer/Lexer.h"
#include "SymbolTable/SymbolTable.h"
#include "SourceGenerator/SourceGenerator.h"
#include "Parser/Parser.h"
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


void set_filepath(InputForm *form, int source)

{
    const char *prefix;
    const char *name;
    size_t name_len;

    switch (source) {
        case OUTPUT_OPT:
            prefix   = "./data/Output_Files/";
            name     = form->output_filename.data;
            name_len = form->output_filename.length;
            break;

        case INPUT_OPT:
            prefix   = "./data/Input_Files";
            name     = form->input_filename.data;
            name_len = form->input_filename.length;
            break;

        default:
            fprintf(stderr, "set_filepath: invalid source %d\n", source);
            exit(-1);
    }

    if (name == NULL) {
        fprintf(stderr, "set_filepath: filename is NULL\n");
        exit(-1);
    }

    const size_t prefix_len = strlen(prefix);

    if (prefix_len + name_len >= PATH_MAX) {
        fprintf(stderr, "set_filepath: path too long (%zu + %zu >= %d)\n",
                prefix_len, name_len, PATH_MAX);
    }

    char path[PATH_MAX];

    memcpy(path, prefix, prefix_len);
    memcpy(path + prefix_len, name, name_len);
    path[prefix_len + name_len] = '\0';
    switch (source) {
        case OUTPUT_OPT:
            in_append_string(form, path, prefix_len + name_len, 8);
            break;
        case INPUT_OPT:
            in_append_string(form, path, prefix_len + name_len, 9);
    }
}

static InputForm* get_output_filename(int output, int opt) {
    InputForm *form = new_input_form();
    // NAME_MAX - 4 is to allow as much room as possible without stepping on the extension,
    // with the longest possible extension being .nexc
    static char unfinished_filename[NAME_MAX - 4];
    size_t unfinished_size;
    // +4 to get us back up to NAME_MAX
    static char finished_filename[sizeof(unfinished_filename) + 4];
    size_t finished_size = sizeof(finished_filename);
    size_t filepath_size;
    size_t filename_size;
    printf("Enter file name, without extension: ");
    scanf("%s", unfinished_filename);
    // filename_size = sizeof(unfinished_filename);
    char filepath[PATH_MAX + filename_size];
    const char *extension = (output == NEX) ? ".nex" : ".nexc";
    strcat(unfinished_filename, extension);
    unfinished_size = sizeof(unfinished_filename);
    strncat(finished_filename, unfinished_filename, finished_size);
    finished_filename[sizeof(finished_filename) - 1] = '\0';
    // sets output filename in form as finished_filename
    in_append_string(form, finished_filename, sizeof(finished_filename) - 1, 6);
    set_filepath(form, opt);
    return form;
}

void get_infile_name(InputForm *form, int opt) {

}

void terminal_to_nexfile(InputForm *form, int intype) {
    // OutType replaces nex_code_flag
    switch (outType) {
        case NEX:
            sgRun(form, outType, false, intype);
            break;
        case NEXC:
            sgRun(form, outType, false, intype);
            break;
        default:
            perror("Invalid output type");
            break;
    }
}


static int read_choice(const char *prompt, int lo, int hi) {
    int value;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= lo && value <= hi) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            return value;
        }
        fprintf(stderr, "Invalid input — enter %d or %d.\n", lo, hi);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}

int run() {
    // Input collection is a placeholder; this will eventually likely be moved to python
    //
    InType intype = (InType)read_choice("Enter 0 or 1: ", 0, 1);
    // replaces nex_code_flag
    OutType output = (OutType)read_choice("Enter 0 or 1: ", 0, 1);
    Options options;
    InputForm *form = get_output_filename(output, OUTPUT_OPT);
    switch (intype) {
        case TERMINAL_IN:
            terminal_to_nexfile(form, intype);
            break;
        case FILE_IN:
            get_infile_name(form, INPUT_OPT);
            compressor_collect(form, intype, output);
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
