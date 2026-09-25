//
// Created by steviexx on 9/24/26.
//

#ifndef NEXUMNTL_LEXERHELPERS_H
#define NEXUMNTL_LEXERHELPERS_H
#include "Lexer.h"
#include "../SymbolTable/SymbolTable.h"


inline int ensure_capacity(DynamicBuffers *buf, size_t extra);
inline int append_bytes(DynamicBuffers *buf, char *byte, size_t x);
inline int append_string(DynamicBuffers *buf, char *string, size_t x);
inline int append_char(DynamicBuffers *buf, char c);
inline Organizer* breakdown_init();
inline void breakdown_free(Organizer *brk);
inline void load_free(MemoryFileLoad *load);
inline void load_init(MemoryFileLoad *load);
#endif //NEXUMNTL_LEXERHELPERS_H
