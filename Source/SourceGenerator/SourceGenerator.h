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

    DynamicBuffers output_filename;
    DynamicBuffers input_filename;

    DynamicBuffers output_filepath;
    DynamicBuffers input_filepath;

    DynamicBuffers terminal_input;
} InputForm;
inline int format_from_export(FILE *export_file, Export *export, int count, int mem_key_idx);
inline int nexc(FILE *fp, InputForm *form, Export *exp);
inline int terminal_input(FILE *fp, InputForm *form, int control);
inline int usrmor_input(FILE *fp, InputForm *form);
inline int format(FILE *fp, InputForm *form, int count, int mem_key_idx);
#endif //SOURCEGENERATOR_H