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
inline InputForm* in_init();
inline int comp_append_bytes(Unencoded *unencoded, InputForm *in);
inline int comp_from_file_append_bytes(InputForm *form,ParserBuffers *pbuffers, FILE* in_file, FILE* export_file,int output);
inline long comp_get_file_size(FILE *in_file);
inline FILE* init_export(InputForm *form);
inline void line_parse(Export *export,ParserBuffers *pbuffers, InputForm *form, FILE* export_file);
#endif //NEXUMNTL_COMPRESSORHELPERS_H
