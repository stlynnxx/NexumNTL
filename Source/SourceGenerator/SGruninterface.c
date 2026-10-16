//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"
#include "SGhelpers.h"
int routing(InputForm *form,int nexcodeFlag, int sourceFlag, int parser_check) {
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
                term_return = terminal_input(fp, form, nexcodeFlag);
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
                term_return = terminal_input(fp, form, nexcodeFlag);
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
                if (parser_check == 0) {
                    usr_return = usrmor_input(fp, form);
                    if (usr_return == -1) {
                        perror("sgrun failure");
                        exit(-1);
                    }
                    else {
                        printf("SG run success!");
                    }
                }
                if (parser_check == 1) {}
                    break;

            default:
                break;
        }
        if (pCheck) {
            Export *exp = get_parser_export();
            nexc(fp, form, exp);
        }
    }
    fclose(fp);
    return 0;
}
void infile_to_nexc_sg_run(InputForm *in, const char *path, int nex_code_flag) {
    routing(in, path, nex_code_flag, 1, 1;
}
void sgRun(InputForm *form, int nexcodeFlag, bool pCheck, int sourceFlag) {
    routing(form, nexcodeFlag, sourceFlag, pCheck);
}