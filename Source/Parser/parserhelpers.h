//
// Created by steviexx on 9/21/26.
//

#ifndef NEXUMNTL_PARSERHELPERS_H
#define NEXUMNTL_PARSERHELPERS_H
#include "../SymbolTable/SymbolTable.h"
#include "Parser.h"
int builder_append_string(Builder *builderr, char *string, size_t x, int control);
int builder_append_char(Builder *builderr, char c, int control);
int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control);
Builder* build_init();
ParserBuffers* pbuffers_init();
Export* exp_init();

#endif //NEXUMNTL_PARSERHELPERS_H
