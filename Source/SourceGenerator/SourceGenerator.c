//
// Created by steviexx on 3/11/26.
//

#include "SourceGenerator.h"

#include <stdio.h>
#include <stdbool.h>
#include "SGhelpers.h"
#include "../Lexer/Lexer.h"
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"
#include "../Parser/parserhelpers.h"


// Input storage






// This is what is actually being appended to the file
void format(FILE *fp, InputForm *form, int count, int mem_key_idx) {
     fprintf(fp, "%s\n", "");
     char memoryKeyPrefix[5] = "{'";
     char memoryKeySuffix[5] = "':{";
     fprintf(fp, "%s", memoryKeyPrefix);
     fprintf(fp,"%s", form->memoryKey.data[mem_key_idx]);
     fprintf(fp, "%s", memoryKeySuffix);
     for (int i = 0; i < count; i++) {
        fprintf(fp, "%s", "'");
        fprintf(fp, "%s", form->associations.data[i]);
        fprintf(fp, "%s", "'");
         if (i != form->assocCount - 1) {
             fprintf(fp, "%c", COMMA);
         }

    }
     fprintf(fp, "%s", "};");
    // free form
}
// Step Two of the append process, opens the created file
// and collects input which gets placed into the input storage
int terminal_input(FILE *fp, InputForm *form, int control) {
    // .nex
    if (control == 0) {
        printf("Memory Key: \n");
        scanf("%s", form->memoryKeyBuffer.data);
        in_append_string(form, form->memoryKeyBuffer.data, form->memoryKeyBuffer.length, 0);
        printf("Assocation Count: \n");
        scanf("%d", form->assocCount);
        printf("Assocations (seperate with spaces, and be sure to match your association count correctly.): \n");
        for (int i = 0; i < form->assocCount; i++ )
        {
            scanf("%s", &form->associationBuffer.data[i]);
            in_append_string(form, &form->associationBuffer.data[i], form->associationBuffer.length, 1);

        }
        format(fp, form, form->assocCount, 0);
        return 0;
    }
    // .nexc
    if (control == 1) {
        Export* exp = exp_init();
        printf("Memory Key: \n");
        scanf("%s", form->memoryKeyBuffer.data);
        // hand over to parser match
        exp_append_string(exp, form->memoryKeyBuffer.data, form->memoryKeyBuffer.length, 4);
        terminalToNexcMatch(exp, 4, exp->memoryKeyScratch.data[0]);
        printf("Assocation Count: \n");
        scanf("%d", form->assocCount);
        printf("Assocations (seperate with spaces, and be sure to match your association count correctly.): \n");
        for (int i = 0; i < form->assocCount; i++ )
        {
            scanf("%s", &form->associations.data[i]);
            exp_append_string(exp, &form->associations.data[i], form->associations.length, 5);

        }
        format(fp, form, form->assocCount, 0);
        return 0;
    }
    else {
        return -1;
    }
}
int* count_set(InputForm *form, int *counts) {
    // this loads the size of each row into counts by the letter macro number- entry 0 is the size for A, entry 1 is the size of B, and so forth
    for (int i = 0; i <= 25; i++) {
        counts[i] = sizeof(valuesMatrix[i])/sizeof(valuesMatrix[i][0]);
    }

    for (int k = 0; k <= 25; k++) {
        for (int l = 0; l < counts[k]; l++) {
            in_append_string(form, valuesMatrix[k][l], sizeof(valuesMatrix[k][l]), 1);
        }
    }
    return counts;

}

int usrmor_input(FILE *fp, InputForm *form) {
    // This will need to take the updated values matrices themselves and translate them to .nex/.nexc
    //
    // this is assigning memory keys as first letters
    int *counts[30];
    char letters[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i <= 25; i++) {
        form->memoryKey.data[i] = letters[i];
    }

    *counts = count_set(form, *counts);
    format(fp, form, *counts[A],  A);
    free(form->associators.data);
    form->associators.data = NULL;
    for (int i = 1; i <= 25; i++) {
        form->associators.data = malloc(32);
        *counts = count_set(form, *counts);
        format(fp, form, *counts[i], i);
        free(form->associations.data);
        form->associations.data = NULL;
    }
    return 0;
}

int nexc(FILE *fp, InputForm *form, Export *exp) {
    // The following variables are establishing the sizes for the arrays within the struct
    size_t sizeAssoc = sizeof(exp->assoc) / sizeof(exp->assoc.data[0]);
    size_t sizeAssociators = sizeof(exp->associators) / sizeof(exp->associators.data[0]);
    size_t sizeMemKeys = sizeof(exp->memKey) / sizeof(exp->memKey.data[0]);
    // Control Vars
    bool mem = false;
    // Here we are looping through the arrays individually
    for (int i = 0; i < sizeAssoc; i++) {
        if (i == 0) {

            exp->memKey.data[i] = NAMETOKEN;
            mem = true;
        }
        if (i > 0) {
            if (form->memoryKey.data[i] )
            form->memoryKey[i] = exp->memKey.data[i];
        }
    }
    for (int i = 0; i < sizeAssociators; i++) {
        form->associators[i] = exp->associators.data[i];
    }
    for (int i = 0; i < sizeMemKeys; i++) {
        form->memoryKey[i] = exp->memKey.data[i];
    }
    if (mem == true) {
        return 1;
    }
    if (mem == false) {
        return 0;
    }
}





/*int main() {
    // bool inputBool = false;
    char entry[30];
    runner("Testing2.nex");

    return 0;
}*/
