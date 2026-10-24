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
    DynamicBuffers in_filename;
    DynamicBuffers out_filename;
    DynamicBuffers compArray;
    DynamicBuffers compBuffer;
    DynamicBuffers Buffers;
    DynamicBuffers line;
    DynamicBuffers writeTarget;
}ParserBuffers;

typedef struct {
    int assocCount;
    DynamicBuffers association;
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
inline Export* match(Export *export, InputForm *form, FILE* export_file,int flag, ParserBuffers *pbuffers);
inline void terminal_to_nexc_match(InputForm *form,FILE* export_file,int flag, char firstLetter);
inline void terminal_to_nexc_encode(InputForm *form, Export *export_form,FILE* export_file,int foundI, int row, int flag);
inline int infile_to_nexc_exp_append_bytes(Export *export, unsigned char *byte, size_t x, int control);
inline int infile_to_nexc_exp_append_string(Export *export,unsigned char *string, size_t x, int control);
Export* verify(Export *export, InputForm *form, FILE* export_file,ParserBuffers *pbuffers, int rowSiZe, int row, int flag);
#endif //PARSER_H