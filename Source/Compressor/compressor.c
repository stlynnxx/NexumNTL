//
// Created by steviexx on 9/16/26.
//

#include "compressor.h"
#include <ctype.h>
#include "../Parser/Parser.h"
#include "../Parser/parserhelpers.h"
#include "../Usrmor/usermorpheme.h"


void input_collect(Input *input) {
    // this will need to get the input from python, get it translated into nexcode from NTL,
    // and then append it into the input buff
}

// FILE *inFile = fopen("../data/usrmor_upload/", "r");
Unencoded* unc_export(void) {
    return unc_exp;
}

void compressor_collect(InputForm *form,int intype, int output) {
    char** files;
    int count;
    ParserBuffers *pbuffers = pbuffers_init();
    FILE *inFile;
    char in_filepath[4096];
    // Control 0 is from file, 1 is from terminal
    if (intype == 0) {
        if (output == 0) {
            // THIS IS FOR THE INPUT FILE BEING IN .NEX
            printf("Enter output filename, press enter to reuse input filename: ");
            scanf("%s", form->output_filepath.data);
            pbuff_append_string(pbuffers, form->output_filepath.data, form->output_filepath.length, 6);
            if (explore_dir("data/Export", ".nex", &files, &count) > 0) {
                for (int i = 0; i < count; i++) {
                    snprintf(in_filepath, sizeof(in_filepath), "data/%s", files[i]);
                    inFile = fopen(in_filepath, "r");
                    free(files[i]);
                }
                if (!form->output_filepath.data[0]) {
                    pbuff_append_string(pbuffers, in_filepath, sizeof(in_filepath), 6);
                }
                free(files);
            }
        }
        // THIS IS FOR THE INUPT FILE BEING IN .NEXC - WILL LIKELY BE REMOVED
        if (output == 1) {
            if (explore_dir("data", ".nexc", &files, &count) > 0) {
                for (int i = 0; i < count; i++) {
                    char filepath[4096];
                    snprintf(filepath, sizeof(filepath), "data/%s", files[i]);
                    inFile = fopen(filepath, "r");
                    free(files[i]);
                }
                free(files);
            }
        }
        // Writing inFile to the appropriate spot in pbuffers
        comp_from_file_append_bytes(form, pbuffers, inFile, output);
    }

    if (intype == 1) {
        bool pCheck = false;
        // input coming from terminal
        printf("Enter term: ");
        scanf("%s", form->terminal_input.data);
        Unencoded *unencoded = unencoded_init();
        comp_append_bytes(unencoded, form);
        *unc_exp = *unencoded;
        usrmor_match(form,unencoded, unencoded->morpheme.data[0], pCheck);

    }
}