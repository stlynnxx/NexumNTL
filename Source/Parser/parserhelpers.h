//
// Created by steviexx on 10/1/26.
//

#ifndef NEXUMNTL_PHELPERS_H
#define NEXUMNTL_PHELPERS_H

#include "Parser.h"


inline int builder_append_string(Builder *builderr, char *string, size_t x, int control);
inline int builder_append_char(Builder *builderr, char c, int control);
inline int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control);
inline Builder* build_init();
inline ParserBuffers* pbuffers_init();
inline Export* exp_init();
inline int exp_ensure_capacity(Export *export, size_t extra, int control);
inline int exp_append_bytes(Export *export, char *byte, size_t x, int control);
inline int exp_append_string(Export *export, char *string, size_t x, int control);
inline int pbuff_append_string(ParserBuffers *pbuffers, char *string, size_t x, int control);




#endif //NEXUMNTL_PHELPERS_H
