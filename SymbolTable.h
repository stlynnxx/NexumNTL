#ifndef AST_H
#define AST_H


typedef enum {
    OPENBRACE = '{',
    CLOSEBRACE = '}',
    SEMICOLON = ';',
    NAMETOKEN = '\'',
    COMMA = ',',
    ASSOCIATOR = '@',
    LINEDELMITER = '\n',
    ENDOFFILE = '\0',
    COLON = ':',
    SPACE = ' ',
    }Symbols;

extern const char alphas[];
extern const int alphasLength;
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