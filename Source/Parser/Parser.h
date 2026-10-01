//
// Created by steviexx on 3/31/26.
//

#ifndef PARSER_H

#define PARSER_H
#include "../SymbolTable/SymbolTable.h"

#include "Parser.h"
#include "../Lexer/Lexer.h"
#include "../SourceGenerator/SourceGenerator.h"
#include "../SymbolTable/SymbolTable.h"
#include "../Lexer/lexerhelpers.h"
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
    DynamicBuffers line;
}ParserBuffers;

typedef struct {
    DynamicBuffers assoc;
    DynamicBuffers associators;
    DynamicBuffers memKey;
    DynamicBuffers encodedMorpheme;

    DynamicBuffers memoryKeyScratch;
    DynamicBuffers associationScratch;
    DynamicBuffers associatorScratch;

} Export;
extern Export *parser_export;
typedef struct {
    DynamicBuffers assocScratch;
    DynamicBuffers associatorScratch;
    DynamicBuffers memKeyScratch;
    DynamicBuffers wC;
} Builder;

inline Export* get_parser_export(void);
Export* match(Export *exp, int flag, ParserBuffers *pbuffers);
void terminalToNexcMatch(Export *exp,int flag, char firstLetter);


#endif //PARSER_H