#ifndef AST_H
#define AST_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 256


# define Able "A0"
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

struct MemoryKey {
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

// These plus the following Values[] array are for holding the translated versions of morphemes and related info
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
    int letterCount;
} Key;
typedef struct {
    ValueType type;
    Key key;
    union {
        unsigned int hex;
        char *string;
    } datatype;
} Value;

char values_matrix[40][40] = {
    {"Able", "Al", "As", "At", "Ance", "ance", "And", "Ante", "ante", "Anti", "anti", "NULL"}, // A, 0
{"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // B, 1
{"Cede", "cede", "Cess", "cess", "Circum", "circum", "Clude", "clude", "NULL", "NULL", "NULL", "NULL"}, // C, 2
{"Dict", "NULL", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // D ,3
{"Ed", "ed", "Er", "er", "En", "en", "NULL","NULL","NULL","NULL","NULL","NULL"}, // E, 4
{"For_", "Form", "form", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // F, 5
{"Gress", "gress", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // G
{"He", "he", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // H
{"In", "in", "Ing", "ing", "Is", "is", "Inter", "inter", "Intra", "intra", "NULL","NULL"}, // I
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // J
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL",}, // K
{"Less", "less", "Ly", "ly","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // L
{"Magni", "magni", "Mark", "mark", "Ment", "ment", "Micro", "micro", "Milli", "milli", "Multi", "multi"}, // M
{"Ness", "ness", "Nd", "nd", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // N
{"Of", "of", "On", "on", "Or", "or", "NULL","NULL","NULL","NULL","NULL","NULL"}, // O
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // P
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // Q
{"Re", "re", "Retro", "retro","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // R
{"Super", "super","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // S
{"Th", "th", "That", "that", "The", "the", "Tion", "tion", "To","to", "NULL","NULL"}, // T
{"Un", "un", "Under", "under", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // U
{"Vert", "vert","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // V
{"With", "with", "NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // W
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // X
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"}, // Y
{"NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL","NULL"} // Z
};

int counts_matrix[20][20] = {
    {4,2,2,2,4,4,3,4,4,4,4,0},
    {0,0,0,0,0,0,0,0,0,0,0,0},
    {4,4,4,4,6,6,5,5,0,0,0,0},
    {4,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,0,0,0,0,0,0},
    {4,4,4,0,0,0,0,0,0,0,0,0},
    {5,5,0,0,0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,0,0,0,0,0},
    {2,2,3,3,2,2,5,5,5,5,0,0},
    {4,4,2,2,0,0,0,0,0,0,0,0},
    {5,5,4,4,4,4,5,5,5,5,5,5},
    {4,4,2,2,0,0,0,0,0,0,0,0},
    {2,2,2,2,2,2,0,0,0,0,0,0},
    {2,2,5,5,0,0,0,0,0,0,0,0},
    {5,5,0,0,0,0,0,0,0,0,0,0},
    {2,2,4,4,3,3,4,4,2,2,0,0},
    {2,2,5,5,0,0,0,0,0,0,0,0},
    {4,4,0,0,0,0,0,0,0,0,0,0},
    {4,4,0,0,0,0,0,0,0,0,0,0}
};
Value Values[] = {
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Able", .letterCount = 4}, .datatype.string = "A0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "able", .letterCount = 4}, .datatype.hex = 0x15},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .upperKey = "Al", .letterCount = 2}, .datatype.string = "A1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "al", .letterCount = 2}, .datatype.hex = 0x1F},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "As", .letterCount = 2}, .datatype.string = "A2"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "as", .letterCount = 2}, .datatype.hex = 0x16},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "At", .letterCount = 2}, .datatype.string = "A3"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "at", .letterCount = 2}, .datatype.hex = 0x1B},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Ance", .letterCount = 4}, .datatype.string = "A4"},
    {.type = VALUE_STRING,  .key = { .type = KEY_LOWER, .lowerKey = "ance", .letterCount = 4 }, .datatype.string = "A5"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "And", .letterCount = 3}, .datatype.string = "A6"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "and", .letterCount = 3}, .datatype.hex = 0x03},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Ante", .letterCount = 4}, .datatype.string = "A7"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ante", .letterCount = 4}, .datatype.string = "A8"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Anti", .letterCount = 4}, .datatype.string = "A9"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "anti", .letterCount = 4}, .datatype.string = "AX"},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Cede", .letterCount = 4}, .datatype.string = "C0"},
    {.type = VALUE_STRING, .key = {.type =  KEY_LOWER, .lowerKey = "cede", .letterCount = 4}, .datatype.string = "C1"},
    {.type = VALUE_STRING, .key = { .type = KEY_UPPER, .upperKey = "Cess", .letterCount = 4}, .datatype.string = "C2"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "cess", .letterCount = 4}, .datatype.string = "C3"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Circum", .letterCount = 6}, .datatype.string = "C4"},
    {.type = VALUE_STRING, .key = { .type= KEY_LOWER, .lowerKey = "circum", .letterCount = 6}, .datatype.string = "C5"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Clude", .letterCount = 5}, .datatype.string = "C6"},
    {.type = VALUE_STRING, .key = {. type= KEY_LOWER, .lowerKey = "clude", .letterCount = 5}, .datatype.string = "C7"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Dict", .letterCount = 4}, .datatype.string = "D0"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "dict", .letterCount = 4}, .datatype.string = "D1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ed", .letterCount = 2}, .datatype.string = "E0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ed", .letterCount = 2}, .datatype.hex = 0x06},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Er", .letterCount = 2}, .datatype.string = "E2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "er", .letterCount = 2}, .datatype.hex = 0x08},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "En", .letterCount = 2}, .datatype.string = "E1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "en", .letterCount = 2}, .datatype.hex = 0x1C},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "For_", .letterCount = 4}, .datatype.string = "F0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "for_", .letterCount = 4}, .datatype.hex = 0x12},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Form", .letterCount = 4}, .datatype.string = "F1"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "form", .letterCount = 4}, .datatype.string = "F2"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Gress", .letterCount = 5}, .datatype.string = "G0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "gress", .letterCount = 5}, .datatype.string = "G1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "He", .letterCount = 2}, .datatype.string = "H0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "he", .letterCount = 2}, .datatype.hex = 0x1A},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "In", .letterCount = 2}, .datatype.string = "I0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey =  "in", .letterCount = 2}, .datatype.hex = 0x0B},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ing", .letterCount = 3}, .datatype.string = "I1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ing", .letterCount = 3},.datatype.hex = 0x02},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Is", .letterCount = 2}, .datatype.string = "I2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "is", .letterCount = 2}, .datatype.hex = 0x0E},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Inter", .letterCount = 5}, .datatype.string = "I3"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "inter", .letterCount = 5}, .datatype.string = "I4"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Intra", .letterCount = 5}, .datatype.string = "I5"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "intra", .letterCount = 5}, .datatype.string = "I6"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "ject", .letterCount = 4}, .datatype.string = "J1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Less", .letterCount = 4}, .datatype.string = "L0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "less", .letterCount = 4}, .datatype.string = "L1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ly", .letterCount = 2}, .datatype.string = "L2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ly", .letterCount = 2}, .datatype.hex = 0x0F},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Magni", .letterCount = 5}, .datatype.string = "M0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "magni", .letterCount = 5}, .datatype.string = "M1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Mark", .letterCount = 4}, .datatype.string = "M2"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "mark", .letterCount = 4}, .datatype.string = "M3"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ment", .letterCount = 4}, .datatype.string = "M4"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "ment", .letterCount = 4}, .datatype.hex = 0x11},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Micro", .letterCount = 5}, .datatype.string = "M5"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "micro", .letterCount = 5}, .datatype.string = "M6"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Milli", .letterCount = 5}, .datatype.string = "M7"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "milli", .letterCount = 5}, .datatype.string = "M8"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Multi", .letterCount = 5}, .datatype.string = "M9"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "multi", .letterCount = 5}, .datatype.string = "MX"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Ness", .letterCount = 4}, .datatype.string = "N0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "ness", .letterCount = 4}, .datatype.hex = 0x1D},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Nd", .letterCount = 2}, .datatype.string = "N1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER,.lowerKey = "nd", .letterCount = 2}, .datatype.hex = 0x13},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Of", .letterCount = 2}, .datatype.string = "O0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "of", .letterCount = 2}, .datatype.hex = 0x05},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "On", .letterCount = 2}, .datatype.string = "O1"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "on", .letterCount = 2}, .datatype.hex = 0x14},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Or", .letterCount = 2}, .datatype.string = "O2"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "or", .letterCount = 2}, .datatype.hex = 0x1E},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Re", .letterCount = 2}, .datatype.string = "R0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "re", .letterCount = 2}, .datatype.hex = 0x0C},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Retro", .letterCount = 5}, .datatype.string = "R1"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "retro", .letterCount = 5}, .datatype.string = "R2"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Super", .letterCount = 5}, .datatype.string = "S0"},
    {.type = VALUE_STRING, .key = {.type = KEY_LOWER, .lowerKey = "super", .letterCount = 5}, .datatype.string = "S1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Th", .letterCount = 2}, .datatype.string = "T0"},
    {.type = VALUE_HEX, .key = {.type = KEY_LOWER, .lowerKey = "th", .letterCount = 2},  .datatype.hex = 0x07},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "That", .letterCount = 4}, .datatype.string = "T1"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "that", .letterCount = 4}, .datatype.hex = 0x04},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "The", .letterCount = 3}, .datatype.string = "T2"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "the", .letterCount = 3}, .datatype.hex = 0x19},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Tion", .letterCount = 4}, .datatype.string = "T3"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "tion", .letterCount = 4}, .datatype.hex = 0x01},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "To", .letterCount = 2}, .datatype.string = "T4"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "to", .letterCount = 2}, .datatype.hex = 0x10},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Un", .letterCount = 2}, .datatype.string = "U0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "un", .letterCount = 2}, .datatype.hex = 0x18},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "Under", .letterCount = 5}, .datatype.string = "U1"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "under", .letterCount = 5}, .datatype.string = "U2"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "Vert", .letterCount = 4}, .datatype.string = "V0"},
    {.type = VALUE_STRING, .key = { .type = KEY_LOWER, .lowerKey = "vert", .letterCount = 4}, .datatype.string = "V1"},
    {.type = VALUE_STRING, .key = {.type = KEY_UPPER, .upperKey = "With", .letterCount = 4}, .datatype.string = "W0"},
    {.type = VALUE_HEX, .key = { .type = KEY_LOWER, .lowerKey = "with", .letterCount = 4}, .datatype.hex = 0x17}
};



int counts[] = {
    4,2,2,2,4,3,4,4,4,4,6,5,4,2,2,2,4,4,5,2,2,3,5,5,2,4,4,2,5,4,
    4,5,5,5,4,2
};

size_t uppersSize = sizeof(*upperKeys) / sizeof(*upperKeys[0]);
size_t lowersSize = sizeof(*lowerKeys) / sizeof(*lowerKeys[0]);
size_t countsSize = sizeof(*counts) / sizeof(counts[0]);

typedef union {
    int hexVal;
    char *string;
} Vals;

typedef struct Entry {
    char *key;
    /*
    char *value;
    int *hexValue;
    */
    Vals values;
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
void insert(HashTable *table,const char *key,const char *value, const int *hexVal) {
    unsigned int idx = hash(key);
    Entry *entry = malloc(sizeof(Entry));
    entry->key = strdup(key);
    entry->values.string = strdup(value);
    entry->values.hexVal = *hexVal;
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

size_t vSize = sizeof(Values) / sizeof(Values[0]);
const char *getKeyString(Value *v)
{
    if (v->key.type == KEY_UPPER) {
        return v->key.upperKey;
    }
    else if (v->key.type == KEY_LOWER) {
        return v->key.lowerKey;
    }
    else if (v->datatype.hex) {
        return v->datatype.hex;
    }
    else if (v->datatype.string) {
        return v->datatype.string;
    }
}


// Usage
int useHashTable() {
    HashTable table = {0}; // initializes all buckets to 0



    for (int ii = 0; ii < vSize; ii++) {
        insert(&table,)
    }
    // Uppers loop
    for (int i = 0; i < uppersSize; i++) {
        insert(&table, upperKeys[i], upperValues[i]);
    }
    // Lowers loop
    for (int j = 0; j < lowersSize; j++) {
        if (Values[j].datatype.string) {
            insert(&table, lowerKeys[j], Values[j].datatype.string);
        }
        if (Values[j].datatype.hex) {
            insert(&table, lowerKeys[j],);
        }}
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