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

void compressor_collect(int control, int nex_code_flag) {
    char** files;
    int count;
    Input *in = in_init();
    FILE* inFile;
    // Control 0 is from file, 1 is from terminal
    // nex_code_flag 0 is .nex, 1 is .nexc
    if (control == 0) {
        if (nex_code_flag == 0) {
        // input coming from inFile,.nex
            if (explore_dir("data", ".nex", &files, &count) > 0) {
                for (int i = 0; i < count; i++) {
                    char filepath[4096];
                    snprintf(filepath, sizeof(filepath), "data/%s", files[i]);
                    inFile = fopen(filepath, "r");
                    free(files[i]);
                }
                free(files);
            }
        }
        // input coming from inFile, .nexc
        if (nex_code_flag == 1) {
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
        ParserBuffers *pbuffers = pbuffers_init();
        comp_from_file_append_bytes(pbuffers, inFile, nex_code_flag);
    }

    if (control == 1) {
        bool pCheck = false;
        // input coming from terminal
        printf("Enter term: ");
        scanf("%s", in->terminalInput.data);
        Unencoded *unencoded = unencoded_init();
        comp_append_bytes(unencoded, in);
        *unc_exp = *unencoded;
        usrmor_match(unencoded, unencoded->morpheme.data[0], pCheck);

    }
}