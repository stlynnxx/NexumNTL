//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"
#include "SGhelpers.h"
int routing(InputForm *form,const char *path, int nexcodeFlag, int sourceFlag, int pCheck) {
    int usr_return;
    int term_return;
    FILE *fp = fopen(path, "a");
    if (fp == NULL)
        return 1;
    if (nexcodeFlag == 0) {
        // This is for handling .nex
        switch (sourceFlag) {
            case 0:
                //  This is for input coming from the terminal
                // form will be freed as a result of the terminal_input call
                term_return = terminal_input(fp, form);
                if (term_return == -1) {
                    printf("terminal input failure");
                    exit(-1);
                }
                else {
                    printf("Success!");
                }
                break;
            case 1:
                // This is for input coming from usermorpheme
                // form is freed as a result of usrmor_input
                usr_return = usrmor_input(fp, form);
                if (usr_return == -1) {
                    perror("sgrun failure");
                    exit(-1);
                }
                else {
                    printf("SG run success!");
                }
                break;
            case 2:
                break;
            default:
                break;
        }
    }
    else {
        // This is for handling .nexc
        switch (sourceFlag) {
            case 0:
                //  This is for input coming from the terminal
                // form will be freed as a result of the terminal_input call
                term_return = terminal_input(fp, form);
                if (term_return == -1) {
                    printf("terminal input failure");
                    exit(-1);
                }
                else {
                    printf("Success!");
                }
                break;
            case 1:
                // This is for input coming from usermorpheme
                // form is freed as a result of usrmor_input
                usr_return = usrmor_input(fp, form);
                if (usr_return == -1) {
                    perror("sgrun failure");
                    exit(-1);
                }
                else {
                    printf("SG run success!");
                }
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




void sgRun(const char *path, int nexcodeFlag, int pCheck, int sourceFlag) {
    InputForm *form = input_init();
    // create(path); Create has been merged into append
    if (nexcodeFlag == 0) {
        routing(form,path, nexcodeFlag, sourceFlag, pCheck);
    }
    else if (nexcodeFlag == 1) {
        routing(path, nexcodeFlag, 1);
    }
    else {
        perror("sgrun failure");
        exit(-1);
    }
}