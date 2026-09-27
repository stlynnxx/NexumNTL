//
// Created by steviexx on 9/27/26.
//

#ifndef NEXUMNTL_COMPRESSORHELPERS_H

#include "compressor.h"

#include <ctype.h>

#include "../Parser/Parser.h"
#include "../Usrmor/usermorpheme.h"
#define NEXUMNTL_COMPRESSORHELPERS_H


inline int explore_dir(const char* dir_path, const char* extension,
                      char*** results, int* count);
inline Input* in_init();
#endif //NEXUMNTL_COMPRESSORHELPERS_H
