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
} Export;

typedef struct {
    DynamicBuffers assocScratch;
    DynamicBuffers associatorScratch;
    DynamicBuffers memKeyScratch;
} Builder;
extern int match(int scratchgOneIdx, int flag, ParserBuffers *buf);
#endif //NEXUMNTL_PARSER_H