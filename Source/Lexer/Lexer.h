//
// Created by steviexx on 2/28/26.
//

#ifndef LEXER_H
#define LEXER_H

#include "../SymbolTable/SymbolTable.h"
#include <stddef.h>



typedef struct {
    DynamicBuffers memoryKey;
    int assocationCount;
    DynamicBuffers associations;
    DynamicBuffers workingAssociators;
    int tracker;
} Organizer;


void lRun();
#define MAX_ASSOC 200
#define MAX_ASSOC_LEN 200
#define ROW 20
#define COLUMN 20

typedef struct {
    DynamicBuffers mainArray;
    // We may end up coming back in here and creating a second array to handle nexcode passes
} MemoryFileLoad;

#endif //NEXUMNTL_LEXER_H