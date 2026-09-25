//
// Created by steviexx on 9/24/26.
//

#ifndef NEXUMNTL_LEXERHELPERS_H
#define NEXUMNTL_LEXERHELPERS_H
#include "Lexer.h"
#include "../SymbolTable/SymbolTable.h"


int ensure_capacity(DynamicBuffers *buf, size_t extra);
int append_bytes(DynamicBuffers *buf, char *byte, size_t x);
int append_string(DynamicBuffers *buf, char *string, size_t x);
int append_char(DynamicBuffers *buf, char c);
Organizer* breakdown_init();
void breakdown_free(Organizer *brk);
void load_free(MemoryFileLoad *load);
void load_init(MemoryFileLoad *load);




#endif //NEXUMNTL_LEXERHELPERS_H
