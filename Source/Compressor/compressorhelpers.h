//
// Created by steviexx on 9/27/26.
//
#ifndef NEXUMNTL_COMPRESSORHELPERS_H
#define NEXUMNTL_COMPRESSORHELPERS_H

#include "compressor.h"
#include <ctype.h>
#include "../Parser/Parser.h"
#include "../Usrmor/usermorpheme.h"


inline int explore_dir(const char* dir_path, const char* extension,
                      char*** results, int* count);
inline Input* in_init();
int comp_append_bytes(Unencoded *unencoded, Input *in);
int comp_from_file_append_bytes(ParserBuffers *pbuffers, FILE* in_file, int nex_code_flag);
#endif //NEXUMNTL_COMPRESSORHELPERS_H
