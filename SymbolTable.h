#ifndef AST_H
#define AST_H




#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 256

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
    able = 0x15,
    al = 0x1F, // Added
    as = 0x16, // Added
    at = 0x1B, // Added
    ance = 'A5', // Added
    ante = 'A7', // Added
    anti = 'A11', // Added
    and = 0x03, // Added
    cede = 'C1', // Added
    cess = 'C3', // Added
    circum = 'C5', // Added
    clude = 'C7', // Added
    dict = 'd1', // Added
    ed = 0x06, // Added
    er = 0x08, // Added
    en = 0x1C, // Added
    for_ = 0x12, //Added
    form = 'F2', // Added
    gress = 'G1', // Added
    he = 0x1A, // Added
    ing = 0x02, // Added
    is = 0x0E, // Added
    in = 0x0B, // Added
    inter = 'I1', // Added
    intra = 'I3', // Added
    ject = 'J1',  // Added
    less = 'L1', // Added
    ly = 0x0F, // // Added
    magni = 'M1', // Added
    mark = 'M3', // Added
    ment = 0x11, // Added
    milli = 'M7', // Added
    micro = 'M6', // Added
    multi = 'M8', // Added
    nd = 0x1D, // Added
     // Added
    ness = 0x13, // Added
    of = 0x05, // Added
    on = 0x14, // Added
    or = 0x1E, // Added
    re = 0x0C, // Added
    retro = 'R3', // Added
    super = 'S3', // Added
    to = 0x07, // Added
    tion = 0x04, // Added
    th = 0x19, // Added
    the = 0x01, // Added
    that = 0x10, // Added
    un = 0x18, // Added
    under = 'U2', // Added
    vert = 'V1', // Added
    with = 0x17, // Added

    // Uppers
    Able = 'A0',
    Al = 'A1',
    As = 'A2',
    At = 'A3',
    Ance = 'A4',
    And = 'A6',
    Ante = 'A8',
    Anti = 'AX', // X is representing 10 here
    Cede = 'C0',
    Cess = 'C2',
    Circum = 'C4',
    Clude = 'C6',
    Dict = 'D0',
    Ed = 'E0',
    En = 'E1',
    Er = 'E2',
    For_ = 'F0',
    Form = 'F1',
    Gress = 'G0',
    He = 'H0',
    In = 'I0',
    Ing = 'I1',
    Inter = 'I2',
    Intra = 'I3',
    Is = 'I4',
    Ject = 'J0',
    Less = 'L0',
    Ly = 'L2',
    Magni = 'M0',
    Mark = 'M2',
    Ment = 'M4',
    Micro = 'M5',
    Milli = 'M7',
    Multi = 'M9',
    Ness = 'N0',
    Nd = 'N1',
    Of = 'O0',
    On = 'O1',
    Or = 'O2',
    Pseudo = 'P2',
    Re = 'R0',
    Retro = 'R2',
    Super = 'S2',
    Th = 'T0',
    That = 'T1',
    The = 'T2',
    To = 'T3',
    Trans = 'T4',
    Un = 'U0',
    Under = 'U1',
    Vert = 'V0',
    With = 'W0',


} free_morphemes;


char *upperKeys[] = {
    "Able", "Al", "As", "At", "Ance", "And", "Ante", "Anti", "Cede", "Cess",
    "Circum", "Clude", "Dict", "Ed", "En", "Er", "For_", "Form", "Gress", "He",
    "In", "Ing", "Inter", "Intra", "Is", "Ject", "Less", "Ly", "Magni", "Mark", "Ment",
    "Micro", "Milli", "Multi", "Ness", "Nd"
};
char *upperValues[] = {
    "A0", "A1", "A2", "A3", "A4", "A6", "A8", "AX",
    "C0", "C2", "C4", "C6", "D0", "E0", "E1", "E2",
    "F0", "F1", "G0", "H0", "I0", "I1", "I2", "I3",
    "I4", "J0", "L0", "L2", "M0", "M2", "M4", "M5",
    "M7", "M9", "N0", "N1", "O0", "O1", "O2", "P2",
    "R0", "R2", "S2", "T0", "T1", "T2", "T3", "T4",
    "U0", "U1", "V0", "W0"
};
char *lowerKeys[] = {
    "able", "al", "As", "At", "ance", "and", "ante", "anti", "cede", "cess",
    "circum", "clude", "dict", "ed", "en", "er", "for_", "form", "gress", "he",
    "in", "ing", "inter", "intra", "is", "ject", "less", "ly", "magni", "mark",
    "ment", "micro", "milli", "multi", "ness", "nd"
};
typedef enum {
    VALUE_HEX,
    VALUE_STRING,
} ValueType;
typedef enum {
    KEY_UPPER,
    KEY_LOWER
} Keytype;
typedef struct {
    Keytype type;
    union {
        const char *lowerKey;
        const char *upperKey;
    };
} Key;
typedef struct {
    ValueType type;
    Key key;
    union {
        unsigned int hex;
        char *string;
    } datatype;
} Value;
Value lowerValues[] = {
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "able"}, .datatype.hex = 0x15},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "al"}, .datatype.hex = 0x1F},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "as"}, .datatype.hex = 0x16},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "at"}, .datatype.hex = 0x1B},
    {.type = VALUE_STRING,  .key = { .type = KEY_LOWER, .lowerKey = "ance" }, .datatype.string = "A5"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ante"}, .datatype.string = "A7"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "anti"}, .datatype.string = "A11"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "and"}, .datatype.hex = 0x03},
    {.type = VALUE_STRING, .key = {.type =  KEY_LOWER, .lowerKey = "cede"}, .datatype.string = "C1"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "cess"}, .datatype.string = "C3"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "circum"}, .datatype.string = "C5"},
    {.type = VALUE_STRING, .key = {. type= KEY_LOWER, .lowerKey = "clude"}, .datatype.string = "C7"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "dict"}, .datatype.string = "D1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ed"}, .datatype.hex = 0x06},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "er"}, .datatype.hex = 0x08},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "en"}, .datatype.hex = 0x1C},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "for_"}, .datatype.hex = 0x12},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "form"}, .datatype.string = "F2"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "gress"}, .datatype.string = "G1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "he"}, .datatype.hex = 0x1A},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ing"},.datatype.hex = 0x02},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "is"}, .datatype.hex = 0x0E},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey =  "in"}, .datatype.hex = 0x0B},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "inter"}, .datatype.string = "I1"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "intra"}, .datatype.string = "I3"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ject"}, .datatype.string = "J1"},
    {.type= VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "less"}, .datatype.string = "L1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ly"}, .datatype.hex = 0x0F},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "magni"}, .datatype.string = "M1"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "mark"}, .datatype.string = "M3"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ment"}, .datatype.hex = 0x11},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "milli"}, .datatype.string = "M6"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "micro"}, .datatype.string = "M7"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "multi"}, .datatype.string = "M8"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "nd"}, .datatype.hex = 0x1D},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER,.lowerKey = "ness"}, .datatype.hex = 0x13},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "of"}, .datatype.hex = 0x05},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "on"}, .datatype.hex = 0x14},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "or"}, .datatype.hex = 0x1E},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "re"}, .datatype.hex = 0x0C},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "retro"}, .datatype.string = "R3"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "super"}, .datatype.string = "S3"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "to"},  .datatype.hex = 0x07},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "tion"}, .datatype.hex = 0x04},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "th"}, .datatype.hex = 0x19},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "the"}, .datatype.hex = 0x01},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "that"}, .datatype.hex = 0x10},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "un"}, .datatype.hex = 0x18},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "under"}, .datatype.string = "U2"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "vert"}, .datatype.string = "V1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "with"}, .datatype.hex = 0x17}
};


int counts[] = {
    4,2,2,2,4,3,4,4,4,4,6,5,4,2,2,2,4,4,5,2,2,3,5,5,2,4,4,2,5,4,
    4,5,5,5,4,2
};

size_t uppersSize = sizeof(*upperKeys) / sizeof(*upperKeys[0]);
size_t lowersSize = sizeof(*lowerKeys) / sizeof(*lowerKeys[0]);
size_t countsSize = sizeof(*counts) / sizeof(counts[0]);

typedef struct Entry {
    char *key;
    char *value;
    struct Entry *next; // collision chaining
} Entry;

typedef struct {
    Entry *buckets[TABLE_SIZE];
} HashTable;

// Hash function
unsigned int hash(const char *key) {
    unsigned int h = 0;
    while (*key) {
        h = (h * 31) + *key++;
    }
    return h % TABLE_SIZE;
}

// Insert a pair
void insert(HashTable *table,const char *key,const char *value) {
    unsigned int idx = hash(key);
    Entry *entry = malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->value = strdup(value);
    entry->next = table->buckets[idx];
    table->buckets[idx] = entry;
}
// Lookup by key
char *lookup(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    Entry *entry = table->buckets[idx];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            return entry->value;

        }
        entry = entry->next;
    }
    return NULL; // not found
}
// Usage
int useHashTable() {
    HashTable table = {0}; // initializes all buckets to 0

    // Uppers loop
    for (int i = 0; i < uppersSize; i++) {
        insert(&table, upperKeys[i], upperValues[i]);
    }
    // Lowers loop
    for (int j = 0; j < lowersSize; j++) {
        insert(&table, lowerKeys[j], lowerValues[j]);
    }
    // Counts loop
    for (int k = 0; k < countsSize; k++) {}

    /* Example inserts
    insert(&table, "under", "U0");
    insert(&table, "re", "RO");*/

    /* Example lookups
     * lookup(&table, "under");
     */
}



typedef struct {
    char *word[];
} Words;
typedef struct {
    int counts[];
} Counts;


// We should resize this later
extern const char firsts[40] = {'t','i','a','o','e','r','l','m','f','n', 'u'};
extern const char secondaries[80] = {
    'b', 'c', 'd', 'g', 'h', 'j', 'k', 'p', 'q', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};


#endif // AST_H