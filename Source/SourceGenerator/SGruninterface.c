//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"

int routing(const char *path, int nexcodeFlag, int sourceFlag, int pCheck) {
    FILE *fp = fopen(path, "a");
    printf("Appending to: %s\n", path);
    if (fp == NULL)
        return 1;
    InputForm form = {0};
    if (nexcodeFlag == 0) {
        // This is for handling .nex
        nex(fp, &form);
    }
    else {
        // This is for handling .nexc
        switch (sourceFlag) {
            case 0:
                //  This is for input coming from the terminal
                break;
            case 1:
                // This is for input coming from usermorpheme
                break;
            case 2:
                break;
            default:
        }
        if (pCheck) {
            Export *exp = get_parser_export();
            nexc(fp, &form, exp);
        }
    }
    fclose(fp);
    return 0;
}




void sgRun(const char *path, int nexcodeFlag, int pCheck) {
    // create(path); Create has been merged into append
    if (nexcodeFlag == 0) {
        routing(path, nexcodeFlag, 0);
    }
    else if (nexcodeFlag == 1) {
        routing(path, nexcodeFlag, 1);
    }
    else {
        perror("sgrun failure");
        exit(-1);
    }
}