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
Value Values[] = {
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Able"}, .datatype.string = "A0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "able"}, .datatype.hex = 0x15},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .upperKey = "Al"}, .datatype.string = "A1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "al"}, .datatype.hex = 0x1F},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "As"}, .datatype.string = "A2"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "as"}, .datatype.hex = 0x16},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "At"}, .datatype.string = "A3"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "at"}, .datatype.hex = 0x1B},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Ance"}, .datatype.string = "A4"},
    {.type = VALUE_STRING,  .key = { .type = KEY_LOWER, .lowerKey = "ance" }, .datatype.string = "A5"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "And"}, .datatype.string = "A6"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "and"}, .datatype.hex = 0x03},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Ante"}, .datatype.string = "A8"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ante"}, .datatype.string = "A7"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Anti"}, .datatype.string = "AX"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "anti"}, .datatype.string = "A11"},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Cede"}, .datatype.string = "C0"},
    {.type = VALUE_STRING, .key = {.type =  KEY_LOWER, .lowerKey = "cede"}, .datatype.string = "C1"},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Cess"}, .datatype.string = "C2"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "cess"}, .datatype.string = "C3"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Circum"}, .datatype.string = "C4"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "circum"}, .datatype.string = "C5"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Clude"}, .datatype.string = "C6"},
    {.type = VALUE_STRING, .key = {. type= KEY_LOWER, .lowerKey = "clude"}, .datatype.string = "C7"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Dict"}, .datatype.string = "D0"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "dict"}, .datatype.string = "D1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ed"}, .datatype.string = "E0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ed"}, .datatype.hex = 0x06},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Er"}, .datatype.string = "E2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "er"}, .datatype.hex = 0x08},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "En"}, .datatype.string = "E1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "en"}, .datatype.hex = 0x1C},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "For_"}, .datatype.string = "F0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "for_"}, .datatype.hex = 0x12},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Form"}, .datatype.string = "F1"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "form"}, .datatype.string = "F2"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Gress"}, .datatype.string = "G0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "gress"}, .datatype.string = "G1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "He"}, .datatype.string = "H0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "he"}, .datatype.hex = 0x1A},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "In"}, .datatype.string = "I0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey =  "in"}, .datatype.hex = 0x0B},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ing"}, .datatype.string = "I1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ing"},.datatype.hex = 0x02},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Is"}, .datatype.string = "I2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "is"}, .datatype.hex = 0x0E},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Inter"}, .datatype.string = "I3"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "inter"}, .datatype.string = "I4"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Intra"}, .datatype.string = "I5"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "intra"}, .datatype.string = "I6"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ject"}, .datatype.string = "J1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Less"}, .datatype.string = "L0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "less"}, .datatype.string = "L1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ly"}, .datatype.string = "L2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ly"}, .datatype.hex = 0x0F},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Magni"}, .datatype.string = "M0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "magni"}, .datatype.string = "M1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Mark"}, .datatype.string = "M2"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "mark"}, .datatype.string = "M3"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ment"}, .datatype.string = "M4"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ment"}, .datatype.hex = 0x11},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Micro"}, .datatype.string = "M5"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "micro"}, .datatype.string = "M6"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Milli"}, .datatype.string = "M7"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "milli"}, .datatype.string = "M8"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Multi"}, .datatype.string = "M9"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "multi"}, .datatype.string = "MX"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ness"}, .datatype.string = "N0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ness"}, .datatype.hex = 0x1D},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Nd"}, .datatype.string = "N1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER,.lowerKey = "nd"}, .datatype.hex = 0x13},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Of"}, .datatype.string = "O0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "of"}, .datatype.hex = 0x05},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "On"}, .datatype.string = "O1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "on"}, .datatype.hex = 0x14},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Or"}, .datatype.string = "O2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "or"}, .datatype.hex = 0x1E},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Re"}, .datatype.string = "R0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "re"}, .datatype.hex = 0x0C},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Retro"}, .datatype.string = "R1"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "retro"}, .datatype.string = "R2"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Super"}, .datatype.string = "S0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "super"}, .datatype.string = "S1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Th"}, .datatype.string = "T0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "th"},  .datatype.hex = 0x07},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "That"}, .datatype.string = "T1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "that"}, .datatype.hex = 0x04},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "The"}, .datatype.string = "T2"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "the"}, .datatype.hex = 0x19},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Tion"}, .datatype.string = "T3"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "tion"}, .datatype.hex = 0x01},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "To"}, .datatype.string = "T4"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "to"}, .datatype.hex = 0x10},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Un"}, .datatype.string = "U0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "un"}, .datatype.hex = 0x18},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "under"}, .datatype.string = "U1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Vert"}, .datatype.string = "V0"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "vert"}, .datatype.string = "V1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "With"}, .datatype.string = "W0"},
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
        insert(&table, lowerKeys[j], Values[j]);
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