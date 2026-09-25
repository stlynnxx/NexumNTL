//
// Created by steviexx on 9/21/26.
//

#ifndef NEXUMNTL_PARSERHELPERS_H
#define NEXUMNTL_PARSERHELPERS_H
#include "../SymbolTable/SymbolTable.h"
#include "Parser.h"
inline int builder_append_string(Builder *builderr, char *string, size_t x, int control);
inline int builder_append_char(Builder *builderr, char c, int control);
inline int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control);
inline Builder* build_init();
inline ParserBuffers* pbuffers_init();
inline Export* exp_init();

#endif //NEXUMNTL_PARSERHELPERS_H
