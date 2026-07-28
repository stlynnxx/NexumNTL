//
// Created by steviexx on 3/11/26.
//

#include "SourceGenerator.h"

#include <stdio.h>
#include <stdbool.h>

#include "Lexer.h"
#include "SymbolTable.h"
#include "Parser.h"
#define MAX_ASSOC 50
#define MAX_ASSOC_LEN 200

// Input storage
typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[MAX_ASSOC][MAX_ASSOC_LEN];
    char associators[];
    } InputForm;


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
     char memoryKeyPrefix[20] = "{'";
     char memoryKeySuffix[20] = "':{";
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
void openNexFile(FILE *fp, InputForm *form) {
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
void readBytes(FILE *fp, InputForm *form, Export *exp) {
    // The following variables are establishing the sizes for the arrays within the struct
    int sizeAssoc = sizeof(exp->assoc) / sizeof(exp->assoc[0]);
    int sizeAssociators = sizeof(exp->associators) / sizeof(exp->associators[0]);
    int sizeMemKeys = sizeof(exp->memKey) / sizeof(exp->memKey[0]);
    // Control Vars
    bool memNameFlag = false;
    // Here we are looping through the arrays individually
    for (int i = 0; i < sizeAssoc; i++) {
        if (i == 0) {
            exp->memKey[i] = NAMETOKEN;
            memNameFlag = true;
        }
        if (i > 0) {
            if (form->memoryKey[i] )
            form->memoryKey[i] = exp->memKey[i];
        }
    }
    for (int i = 0; i < sizeAssociators; i++) {
        form->associators[i] = exp->associators[i];
    }
    for (int i = 0; i < sizeMemKeys; i++) {
        form->memoryKey[i] = exp->memKey[i];
    }
}
// Begins the append process
int append(const char *path) {
    Export *exp;
    FILE *fp = fopen(path, "a");
    printf("Appending to: %s\n", path);
    if (fp == NULL)
        return 1;
    InputForm form = {0};
    if (nexcodeFlag == false) {
        openNexFile(fp, &form);
    }
    else {
        readBytes(fp, &form, exp);
    }
    fclose(fp);
    return 0;
}

int sgRun(const char *path) {
    // create(path); Create has been merged into append
    append(path);
    return 0;
}

/*int main() {
    // bool inputBool = false;
    char entry[30];
    runner("Testing2.nex");

    return 0;
}*/
