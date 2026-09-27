//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"
#include "SGhelpers.h"
int routing(InputForm *form,const char *path, int nexcodeFlag, int sourceFlag, int pCheck) {
    FILE *fp = fopen(path, "a");
    if (fp == NULL)
        return 1;
    if (nexcodeFlag == 0) {
        // This is for handling .nex
        terminal_input(fp, form);
    }
    else {
        // This is for handling .nexc
        switch (sourceFlag) {
            case 0:
                //  This is for input coming from the terminal
                terminal_input(fp, form);
                break;
            case 1:
                // This is for input coming from usermorpheme
                usrmor_input(fp, form);
                break;
            case 2:
                break;
            default:
        }
        if (pCheck) {
            Export *exp = get_parser_export();
            nexc(fp, form, exp);
        }
    }
    fclose(fp);
    return 0;
}




void sgRun(const char *path, int nexcodeFlag, int pCheck) {
    InputForm *form = input_init();
    // create(path); Create has been merged into append
    if (nexcodeFlag == 0) {
        routing(form,path, nexcodeFlag, 0, pCheck);
    }
    else if (nexcodeFlag == 1) {
        routing(path, nexcodeFlag, 1);
    }
    else {
        perror("sgrun failure");
        exit(-1);
    }
}