//
// Created by steviexx on 9/24/26.
//

#ifndef NEXUMNTL_USRMORHELPERS_H
#define NEXUMNTL_USRMORHELPERS_H
#include "../Parser/Parser.h"
#include "../SymbolTable/SymbolTable.h"
#include "usermorpheme.h"

int unc_ensure_capacity(Unencoded *unencoded, size_t extra);
int unc_append_bytes(Unencoded *unencoded, char *byte, size_t x);
int unc_append_string(Unencoded *unencoded, ParserBuffers *pbuff, int foundI, size_t x);
int unc_append_char(Unencoded *unencoded, char c);
int unencoded_free(Unencoded* unencoded);
Unencoded* unencoded_init();


#endif //NEXUMNTL_USRMORHELPERS_H
