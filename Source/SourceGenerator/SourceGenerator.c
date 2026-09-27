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


// Input storage



// This is creating a file
// I've built create into append instead of keeping it it's own function but
// have for the time being left this in here commented out
/* void create(const char *path) {
    FILE *fp = fopen(path, "a");
    if (fp != NULL)
        fclose(fp);
}*/



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
         if (i != form->assocationCount - 1) {
             fprintf(fp, "%c", COMMA);
         }

    }
     fprintf(fp, "%s", "};");
}
// Step Two of the append process, opens the created file
// and collects input which gets placed into the input storage
int terminal_input(FILE *fp, InputForm *form) {
    printf("Memory Key: \n");
    scanf("%s", form->memoryKey.data);
    printf("Assocation Count: \n");
    scanf("%d", form->assocationCount);
    printf("Assocations (seperate with spaces, and be sure to match your association count correctly.): \n");
    for (int i = 0; i < form->assocationCount; i++ )
    {
        scanf("%s", form->associations.data[i]);

    }
    format(fp, form, form->assocationCount, 0);
    return 0;
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
