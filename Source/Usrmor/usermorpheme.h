//
// Created by steviexx on 9/19/26.
//

#ifndef NEXUMNTL_USERMORPHEME_H
#define NEXUMNTL_USERMORPHEME_H
#include "../Parser/Parser.h"

typedef struct {
    DynamicBuffers morpheme;
} Unencoded;



void usrmor_add_p(Export *export, ParserBuffers *pbuffers, int foundI);
#endif //NEXUMNTL_USERMORPHEME_H
