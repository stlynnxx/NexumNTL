#ifndef SymbolTable_H
#define SymbolTable_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 256

typedef struct {
    char *data;
    size_t length;
    size_t capacity;
} DynamicBuffers;

typedef enum {
    OPENBRACE = '{',
    CLOSEBRACE = '}',
    SEMICOLON = ';',
    NAMETOKEN = '\'',
    COMMA = ',',
    ASSOCIATOR = '@',
    LINEDELMITER = '\n',
    ENDOFFILE = '0',
    COLON = ':',
    SPACE = ' ',
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6,
    H = 7,
    I = 8,
    J = 9,
    K = 10,
    L = 11,
    M = 12,
    N = 13,
    O = 14,
    P = 15,
    Q = 16,
    R = 17,
    S = 18,
    T = 19,
    U = 20,
    V = 21,
    W = 22,
    X = 23,
    Y = 24,
    Z = 25,
} Symbols;

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

// These structs are the buffer for the matrix; only columns need to be expanded.
typedef struct {
    DynamicBuffers *cols;
    size_t count;
    size_t capacity;
} Row;

typedef struct {
    Row row[26];
} Table;
char *valuesMatrix[26][14];
char *encodedMatrix[26][14];
int hexMatrix[40][40];
int countsMatrix[26][14];
char firsts[40];
char secondaries[80];
inline void seed_table(Table *table);
inline int row_init(Row *row);
inline int row_set(Row *row, size_t col, const char *value);
#endif // SymbolTable_H