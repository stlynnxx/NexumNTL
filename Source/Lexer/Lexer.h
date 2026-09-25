//
// Created by steviexx on 2/28/26.
//

#ifndef LEXER_H
#define LEXER_H

#include "../SymbolTable/SymbolTable.h"
#include <stddef.h>

typedef struct {
    DynamicBuffers mainArray;
    // We may end up coming back in here and creating a second array to handle nexcode passes
} MemoryFileLoad;

typedef struct {
    DynamicBuffers memoryKey;
    int assocationCount;
    DynamicBuffers associations;
    DynamicBuffers workingAssociators;
    int tracker;
} Organizer;

inline void lRun();



#endif //NEXUMNTL_LEXER_H