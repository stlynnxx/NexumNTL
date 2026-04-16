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
    // Added
    al = 0x1F,
    as = 0x16,
    ance = 'A4',
    anti = 'A3',
    and = 0x03,
    able = 0x15,
    cede = 'c3',
    cess = 'c5',
    circum = 'C2',
    clude = 'c6',
    dict = 'd1',
    ed = 0x06,
    er = 0x08,
    for_ = 0x12,
    form = 'F1',
    ing = 0x02,
    is = 0x0E,
    in = 0x0B,
    less = 'le',
    ly = 0x0F,
    ment = 0x11,
    Ness = 'N0',
    ness = 0x13,
    of = 0x05,
    on = 0x14,
    re = 0x0C,
    super = 'S3',
    to = 0x07,
    tion = 0x04,
    the = 0x01,
    that = 0x10,
    under = 'U1',

    // Uppers
    Ante = 'A0',
    Anti = 'A1',
    Cede = 'C0',
    Circum = 'C1',
    Dict = 'D0',
    For_ = 'F!',
    Form = 'F0',
    Inter = 'I0',
    Intra = 'I1',
    Magni = 'M0',
    Micro = 'Mic',
    Milli = 'Mil',
    Multi = 'Mu',
    Pseudo = 'P2',
    Retro = 'Ret',
    Super = 'S2',
    Trans = 'T0',
    Under = 'U0',






    with = 0x17,
    un = 0x18,
    th = 0x19,
    he = 0x1A,
    at = 0x1B,
    en = 0x1C,
    nd = 0x1D,
    or = 0x1E,

    /*
    Cede = 'c0',
    cede = 'c3',
    Cess = 'c4',
    cess = 'c5',
    clude = 'c6',
    Dict = 'd0',
    dict = 'd1',
    Form = 'F0',
    form = 'F1',
    Gress = 'G0',
    gress = 'G2',


    Trans = 'T0',
    Script = 'S0',
    script = 'S1',
    Super = 'S2',
    super = 'S3',
    Struct = 'S4',
    struct_ = 'S5',
    Spect = 'S6',
    spect = 'S7',
    Tract = 'T0',
    tract = 'T1',
    Under = 'U0',
    under = 'U1',
    Ante = 'A0',
    Circum = 'C0',
    circum = 'C1',
    Inter = 'I0',
    Intra = 'I1',
    Ject = 'J0',
    ject = 'j3',
    Magni = 'M0',
    Mark = 'M1',
    mark = 'M2',
    Micro = 'Mic',
    Multi = 'Mu',

    Place = 'P0',
    place = 'P1',
    Pseudo = 'P2',
    Port = 'P3',
    port = 'P4',
    Pose = 'P5',
    pose = 'P6',
    Press = 'P7',
    press = 'P8',
    Retro = 'Ret',
    Sign = 'S0',
    sign = 's1',
    Milli = 'Mil',
    Vert = 'V0',
    vert = 'v1'
    */

} free_morphemes;


// We should resize this later
extern const char firsts[40] = {'t','i','a','o','e','r','l','m','f','n', 'u'};
extern const char secondaries[80] = {
    'b', 'c', 'd', 'g', 'h', 'j', 'k', 'p', 'q', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};


#endif // AST_H