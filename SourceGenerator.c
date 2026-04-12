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
    } InputForm;


// This is creating a file
void create(const char *path) {
    FILE *fp = fopen(path, "a");
    if (fp != NULL)
        fclose(fp);
}


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
// Begins the append process
void append(const char *path) {
    FILE *fp = fopen(path, "a");
    printf("Appending to: %s\n", path);
    if (fp == NULL)
        return;
    InputForm form = {0};
    openNexFile(fp, &form);
    fclose(fp);
}

void sgRun(const char *path) {
    if (nexcodeFlag == false) {
        create(path);
        append(path);
    }
    if (nexcodeFlag == true) {}
}

/*int main() {
    // bool inputBool = false;
    char entry[30];
    runner("Testing2.nex");

    return 0;
}*/
