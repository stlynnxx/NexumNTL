//
// Created by steviexx on 9/19/26.
//

#ifndef NEXUMNTL_USERMORPHEME_H
#define NEXUMNTL_USERMORPHEME_H
#include "../Parser/Parser.h"

typedef struct {
    DynamicBuffers morpheme;
    DynamicBuffers memoryKey;
    DynamicBuffers associator;
    DynamicBuffers association;
} Unencoded;


void usrmor_match(InputForm *form, Unencoded *unencoded, char firstLetter, int foundI, bool pCheck);
void usrmor_add_p(char *byte, int foundI);
void terminal_to_nexc_usrmor_add_p(InputForm *form, int foundI);
void usrmor_add(char *byte, int foundI);
#endif //NEXUMNTL_USERMORPHEME_H
