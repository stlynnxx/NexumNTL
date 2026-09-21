//
// Created by steviexx on 3/31/26.
//

#ifndef PARSER_H
#include "../SymbolTable/SymbolTable.h"
#include <stddef.h>
#define PARSER_H

int prun();


typedef struct {
    DynamicBuffers compArray;
    DynamicBuffers compBuffer;
    DynamicBuffers Buffers;
} ParserBuffers;

typedef struct {
    DynamicBuffers assoc;
    DynamicBuffers associators;
    DynamicBuffers memKey;
    DynamicBuffers encodedMorpheme;
} Export;

typedef struct {
    DynamicBuffers assocScratch;
    DynamicBuffers associatorScratch;
    DynamicBuffers memKeyScratch;
} Builder;
int p_ensure_capacity(Export *export, size_t extra, int control);
int p_append_bytes(Export *export, char *byte, size_t x, int control);
int p_append_string(Export *export, char *string, size_t x, int control);
int p_append_char(Export *export, char c, int control);

#endif //NEXUMNTL_PARSER_H