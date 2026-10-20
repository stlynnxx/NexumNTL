//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"
#include "SGhelpers.h"
#include "../main.h"
int sg_routing(InputForm *form,int nexcodeFlag, int sourceFlag, int parser_check) {
    int usr_return;
    int term_return;
    FILE *output_file = fopen(form->output_filename.data, "a");
    if (output_file == NULL)
        return 1;
    if (nexcodeFlag == 0) {
        // This is for handling .nex
        switch (sourceFlag) {
            case 0:
                //  This is for input coming from the terminal
                // form will be freed as a result of the terminal_input call
                term_return = terminal_input(output_file, form, nexcodeFlag);
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
                usr_return = usrmor_input(output_file, form);
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
                term_return = terminal_input(output_file, form, nexcodeFlag);
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
                    usr_return = usrmor_input(output_file, form);
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
            nexc(output_file, form, exp);
        }
    }
    fclose(output_file);
    return 0;
}
void send_to_generator(Export *exp, FILE* export_file) {
    format_from_export(export_file,exp, exp->assocCount, 0);

}
void sgRun(InputForm *form,int nexcodeFlag, bool pCheck, int sourceFlag) {
    sg_routing(form, nexcodeFlag, sourceFlag, pCheck);
}