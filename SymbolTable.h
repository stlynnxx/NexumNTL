#ifndef AST_H
#define AST_H



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


typedef enum  {
    the = 0x01,
    ing = 0x02,
    and = 0x03,
    tion = 0x04,
    of = 0x05,
    ed = 0x06,
    to = 0x07,
    er = 0x08,
    in = 0x0B,
    re = 0x0C,
    is = 0x0E,
    ly = 0x0F,
    that = 0x10,
    ment = 0x11,
    ffor = 0x12,
    ness = 0x13,
    on = 0x14,
    able = 0x15,
    as = 0x16,
} free_morphemes;

// We should resize this later
extern const char firsts[40] = {'t','i','a','o','e','r','l','m','f','n'};
extern const char secondaries[80] = {
    'b', 'c', 'd', 'g', 'h', 'j', 'k', 'p', 'q', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};


#endif // AST_H