//
// Created by steviexx on 9/25/26.
//

#include "SGruninterface.h"
#include "SGhelpers.h"
#include "../main.h"
int sg_routing(InputForm *form,FILE* export_file,int output, int in_type, int parser_check) {
    int usr_return;
    int term_return;
    // FILE *output_file = fopen(form->output_filename.data, "a");
    if (export_file == NULL)
        return 1;
    // output 0 is nex, 1 is nexc
    // in_type 0 is terminal, 1 is inFile
    if (output == 0) {
        // This is for handling .nex
        switch (in_type) {
            // terminal -> nex
            case 0:
                // form will be freed as a result of the terminal_input call
                term_return = terminal_input(export_file, form, output);
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
                usr_return = usrmor_input(export_file, form);
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
    // output = 1
    else {
        // This is for handling .nexc
        switch (in_type) {
            // terminal -> nexc
            case 0:
                // form will be freed as a result of the terminal_input call
                term_return = terminal_input(export_file, form, output);
                if (term_return == -1) {
                    printf("terminal input failure");
                    exit(-1);
                }
                else {
                }
                break;
            case 1:
                // This is for input coming from usermorpheme
                // form is freed as a result of usrmor_input
                if (parser_check == 0) {
                    usr_return = usrmor_input(export_file, form);
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
            nexc(export_file, form, exp);
        }
    }
    fclose(export_file);
    return 0;
}
void send_to_generator(Export *exp, FILE* export_file) {
    format_from_export(export_file,exp, exp->assocCount, 0);

}
void sgRun(InputForm *form,FILE* export_file,int nexcodeFlag, bool pCheck, int sourceFlag) {
    sg_routing(form, export_file,nexcodeFlag, sourceFlag, pCheck);
}