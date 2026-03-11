#include "SymbolTable.h"

const char startFileToken[5]   = "{\t";
const char *openBraceToken   = "{";
const char *closeBraceToken  = "}";
const char *nameToken        = "'";
const char namesToken[3]       = "', ";
const char *comma               = "'";
const char *associatorToken  = "@";
const char *endLineToken     = ";";
const char endDataToken[5]     = "}\t";
const char endOfFile[3] = "\0";

const char alphas[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int alphasLength = sizeof(alphas) / sizeof(alphas[0]);
const char endAssociationsToken[2] = "'}";
const char *colon = ":";
const char *space = " ";
const char openingSeq[5] = ": {";

/*
struct MemoryKey
    {
        int x;
        // char associationBank[20];
        struct associatonBank{
            char associationsList[200];
            struct associator {
                struct MemoryKey *associatonBank;

            } associator;

        } associatonBank;

    } MemoryKey;
*/
