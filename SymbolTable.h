#ifndef AST_H
#define AST_H
#define THE '\x01'
#define ING '\x02'
#define AND '\x03'
#define TION '\x04'
#define OF '\x05'
#define ED '\x06'
#define TO '\x07'
#define ER '\x08'
#define IN '\x0B'
#define RE '\x0C'
#define IS '\x0E'

#include <stddef.h>


typedef enum {
    OPENBRACE = '{',
    CLOSEBRACE = '}',
    SEMICOLON = ';',
    NAMETOKEN = '\'',
    COMMA = ',',
    ASSOCIATOR = '@',
    LINEDELMITER = '\n',
    ENDOFFILE = 'NULL',
    COLON = ':',
    SPACE = ' ',
    }Symbols;

typedef struct {


}Encodings;

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