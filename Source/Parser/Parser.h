//
// Created by steviexx on 3/31/26.
//

#ifndef PARSER_H

#define PARSER_H
#include "../SymbolTable/SymbolTable.h"
#include "parserhelpers.h"
#include "Parser.h"
#include "../Lexer/Lexer.h"
#include "../SourceGenerator/SourceGenerator.h"
#include "../SymbolTable/SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <stddef.h>
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
    DynamicBuffers wC;
} Builder;
int exp_ensure_capacity(Export *export, size_t extra, int control);
int exp_append_bytes(Export *export, char *byte, size_t x, int control);
int exp_append_string(Export *export, char *string, size_t x, int control);
int exp_append_char(Export *export, char c, int control);

#endif //NEXUMNTL_PARSER_H