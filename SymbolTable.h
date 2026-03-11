#ifndef AST_H
#define AST_H

extern const char startFileToken[];
extern const char *openBraceToken;
extern const char *closeBraceToken;
extern const char *nameToken;
extern const char namesToken[];
extern const char *comma;
extern const char *associatorToken;
extern const char *endLineToken;
extern const char endFileToken[];
extern const char alphas[];
extern const int alphasLength;
extern const char endAssociationsToken[];
extern const char *colon;
extern const char *space;
extern const char openingSeq[];
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

};


#endif // AST_H