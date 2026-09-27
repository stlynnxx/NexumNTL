//
// Created by steviexx on 9/16/26.
//

#include "compressor.h"

#include <ctype.h>

#include "../Parser/Parser.h"
#include "../Usrmor/usermorpheme.h"


void input_collect(Input *input) {
    // this will need to get the input from python, get it translated into nexcode from NTL,
    // and then append it into the input buff
}

// FILE *inFile = fopen("../data/usrmor_upload/", "r");

void collect(int control) {
    char** files;
    int count;
    Input *in = in_init();
    if (control == 0) {
        // input coming from inFile
        if (explore_dir("data", ".nex", &files, &count) > 0) {
            for (int i = 0; i < count; i++) {
                char filepath[4096];
                snprintf(filepath, sizeof(filepath), "data/%s", files[i]);
                FILE* inFile = fopen(filepath, "r");
                fclose(inFile);
                free(files[i]);
            }
            free(files);
        }

    }
    if (control == 1) {
        // input coming from terminal
        printf("Enter term: ");
        scanf("%s", in->terminalInput.data);

    }
}