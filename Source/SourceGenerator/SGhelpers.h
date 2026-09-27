//
// Created by steviexx on 9/26/26.
//

#ifndef NEXUMNTL_SGHELPERS_H
#define NEXUMNTL_SGHELPERS_H
#include "SourceGenerator.h"


inline int input_free(InputForm* form);
inline InputForm* input_init();
inline int in_ensure_capacity(InputForm *form, size_t extra, int control);
inline int in_append_bytes(InputForm *form, char *byte, size_t x, int control);
inline int in_append_string(InputForm *form, char *string, size_t x, int control);
inline int in_append_char(InputForm *form, char c, int control);



#endif //NEXUMNTL_SGHELPERS_H
