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

#endif //NEXUMNTL_PARSER_H