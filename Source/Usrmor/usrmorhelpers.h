//
// Created by steviexx on 9/24/26.
//

#ifndef NEXUMNTL_USRMORHELPERS_H
#define NEXUMNTL_USRMORHELPERS_H
#include "../Parser/Parser.h"
#include "../SymbolTable/SymbolTable.h"
#include "usermorpheme.h"

inline int usr_ensure_capacity(Unencoded *unencoded, size_t extra);
inline int usr_append_bytes(Unencoded *unencoded, InputForm *form, size_t x);
inline int usr_append_string(Unencoded *unencoded, char *byte, int foundI, size_t x);
inline int usr_append_char(Unencoded *unencoded, char c);
inline int unencoded_free(Unencoded* unencoded);
inline Unencoded* unencoded_init();
inline int terminalToNexcUsrAppendString(Unencoded *unencoded, InputForm *form);


#endif //NEXUMNTL_USRMORHELPERS_H
