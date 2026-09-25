//
// Created by steviexx on 3/11/26.
//

#include "SourceGenerator.h"

#include <stdio.h>
#include <stdbool.h>

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
void format(FILE *fp, InputForm *form) {
     fprintf(fp, "%s\n", "");
     char memoryKeyPrefix[5] = "{'";
     char memoryKeySuffix[5] = "':{";
     fprintf(fp, "%s", memoryKeyPrefix);
     fprintf(fp,"%s", form->memoryKey);
     fprintf(fp, "%s", memoryKeySuffix);
     for (int i = 0; i < form->assocationCount; i++) {
        fprintf(fp, "%s", "'");
        fprintf(fp, "%s", form->associations[i]);
        fprintf(fp, "%s", "'");
         if (i != form->assocationCount - 1) {
             fprintf(fp, "%c", COMMA);
         }

    }
     fprintf(fp, "%s", "};");
}
// Step Two of the append process, opens the created file
// and collects input which gets placed into the input storage
void nex(FILE *fp, InputForm *form) {
    printf("Memory Key: \n");
    scanf("%199s", form->memoryKey);
    printf("Assocation Count: \n");
    scanf("%d", &form->assocationCount);
    printf("Assocations (seperate with spaces, and be sure to match your association count correctly.): \n");
    for (int i = 0; i < form->assocationCount && i < MAX_ASSOC; i++ )
    {
        scanf("%1999s", form->associations[i]);

    }
    format(fp, form);
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
            if (form->memoryKey[i] )
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
