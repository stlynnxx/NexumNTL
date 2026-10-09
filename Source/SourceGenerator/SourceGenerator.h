//
// Created by steviexx on 3/11/26.
//

#ifndef SOURCEGENERATOR_H
#define SOURCEGENERATOR_H
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"
#include <stdbool.h>
typedef struct {
    DynamicBuffers memoryKey;
    int assocCount;
    DynamicBuffers associations;
    DynamicBuffers associators;
    DynamicBuffers memoryKeyBuffer;
    DynamicBuffers associationBuffer;
    DynamicBuffers associatorBuffer;
    DynamicBuffers filename;
} InputForm;

int nexc(FILE *fp, InputForm *form, Export *exp);
int terminal_input(FILE *fp, InputForm *form, int control);
int usrmor_input(FILE *fp, InputForm *form);
#endif //SOURCEGENERATOR_H