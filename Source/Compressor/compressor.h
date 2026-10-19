//
// Created by steviexx on 9/16/26.
//

#ifndef NEXUMNTL_COMPRESSOR_H
#define NEXUMNTL_COMPRESSOR_H
#include "../SymbolTable/SymbolTable.h"
#include "compressorhelpers.h"
#include "../Usrmor/usrmorhelpers.h"



extern Unencoded* unc_export(void);
extern Unencoded* unc_exp;
void compressor_collect(InputForm *form,int intype, int output);

#endif //NEXUMNTL_COMPRESSOR_H
