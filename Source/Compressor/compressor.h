//
// Created by steviexx on 9/16/26.
//

#ifndef NEXUMNTL_COMPRESSOR_H
#define NEXUMNTL_COMPRESSOR_H
#include "../SymbolTable/SymbolTable.h"
#include "compressorhelpers.h"
#include "../Usrmor/usrmorhelpers.h"


typedef struct {
    DynamicBuffers buffer;
    DynamicBuffers terminalInput;
} Input;
extern Unencoded* unc_export(void);
extern Unencoded* unc_exp;
void compressor_collect(int control, int nex_code_flag);

#endif //NEXUMNTL_COMPRESSOR_H
