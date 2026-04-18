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
    al = 0x1F, // Added
    as = 0x16, // Added
    at = 0x1B, // Added
    ance = 'A5', // Added
    ante = 'A7', // Added
    anti = 'A11', // Added
    and = 0x03, // Added
    able = 0x15, // Added
    cede = 'C1', // Added
    cess = 'C3', // Added
    circum = 'C5', // Added
    clude = 'C7', // Added
    dict = 'd1', // Added
    ed = 0x06, // Added
    er = 0x08, // Added
    en = 0x1C, // Added
    for_ = 0x12, //Added
    form = 'F1', // Added
    gress = 'G1', // Added
    he = 0x1A, // Added
    ing = 0x02, // Added
    is = 0x0E, // Added
    in = 0x0B,
    inter = 'I1',
    intra = 'I3',
    ject = 'J1',
    less = 'le',
    ly = 0x0F,
    magni = 'M1',
    mark = 'M3',
    ment = 0x11,
    milli = 'M7',
    micro = 'M5',
    multi = 'M9',
    nd = 0x1D,
    Ness = 'N0',
    ness = 0x13,
    of = 0x05,
    on = 0x14,
    or = 0x1E,
    re = 0x0C,
    super = 'S3',
    to = 0x07,
    tion = 0x04,
    th = 0x19,
    the = 0x01,
    that = 0x10,
    un = 0x18,
    under = 'U2',
    vert = 'V1',
    with = 0x17,

    // Uppers
    Able = 'A0',
    Al = 'A1',
    As = 'A2',
    At = 'A3',
    Ance = 'A4',
    And = 'A6',
    Ante = 'A8',
    Anti = 'AX', // is is representing 10 here
    Cede = 'C0',
    Cess = 'C2',
    Circum = 'C4',
    Clude = 'C6',
    Dict = 'D0',
    Ed = 'E0',
    En = 'E1',
    Er = 'E2',
    For_ = 'F!',
    Form = 'F0',
    Gress = 'G0',
    He = 'H0',
    In = 'I0',
    Ing = 'I1',
    Inter = 'I2',
    Intra = 'I3',
    Is = 'I4',
    Ject = 'J0',
    Magni = 'M0',
    Mark = 'M2',
    Micro = 'M4',
    Milli = 'M6',
    Multi = 'M8',
    Nd = 'N0',
    Of = '01',
    On = '02',
    Or = '03',
    Pseudo = 'P2',
    Retro = 'Ret',
    Super = 'S2',
    Th = 'T0',
    Trans = 'T1',
    Un = 'U0',
    Under = 'U1',
    Vert = 'V0',
    With = 'W0',















    /*
    Cede = 'c0',
    cede = 'c1',
    Cess = 'c2',
    cess = 'c3',
    Circum = 'C4',
    circum = 'C5',
    clude = 'c6',
    Dict = 'd0',
    dict = 'd1',
    Form = 'F0',
    form = 'F1',
    Gress = 'G0',
    gress = 'G1',


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

    Inter = 'I0',
    Intra = 'I1',
    Ject = 'J0',
    ject = 'j3',
    Magni = 'M0',
    magni = 'M1',
    Mark = 'M2',
    mark = 'M3',
    Micro = 'M4',
    micro = 'M5',
    Milli = 'M6',
    milli = 'M7',
    Multi = 'M8',
    multi = 'M9'

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