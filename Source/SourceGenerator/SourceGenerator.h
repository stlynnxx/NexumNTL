//
// Created by steviexx on 3/11/26.
//

#ifndef SOURCEGENERATOR_H
#define SOURCEGENERATOR_H
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"
#include <stdbool.h>

typedef struct {
    int assocCount;
    int found_i;
    int found_row;
    DynamicBuffers memoryKey;
    DynamicBuffers encoded_memoryKey;
    DynamicBuffers associations;
    DynamicBuffers encoded_associations;
    DynamicBuffers associators;
    DynamicBuffers encoded_associators;
    DynamicBuffers memoryKeyBuffer;
    DynamicBuffers associationBuffer;
    DynamicBuffers associatorBuffer;

    DynamicBuffers output_filename;
    DynamicBuffers input_filename;

    DynamicBuffers output_filepath;
    DynamicBuffers input_filepath;

    DynamicBuffers terminal_input;
} InputForm;

typedef enum {
    memoryKey = 0,
    associations = 1,
    associators = 2,
    memKeyBuffer = 3,
    associationBuffer = 4,
    associatorBuffer = 5,
    output_filename = 6,
} StructFlags;

inline int format_from_export(FILE *export_file, Export *export, int count, int mem_key_idx);
inline int nexc(FILE *fp, InputForm *form, Export *exp);
inline int terminal_input(FILE *export_file, InputForm *form, int control);
inline int usrmor_input(FILE *fp, InputForm *form);
inline int format(FILE *export_file, InputForm *form, int count);
#endif //SOURCEGENERATOR_H