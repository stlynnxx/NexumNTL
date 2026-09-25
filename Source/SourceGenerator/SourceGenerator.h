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
    DynamicBuffers assocationCount;
    DynamicBuffers associations;
    DynamicBuffers associators;
} InputForm;

int nexc(FILE *fp, InputForm *form, Export *exp);
void nex(FILE *fp, InputForm *form);

#endif //SOURCEGENERATOR_H