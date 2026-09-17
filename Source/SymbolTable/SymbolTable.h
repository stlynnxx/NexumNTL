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
extern char *valuesMatrix[26][14];
extern char *encodedMatrix[26][14];
extern int hexMatrix[40][40];
extern int countsMatrix[26][14];
extern char firsts[40];
extern char secondaries[80];
void seed_table(Table *table);
int row_init(Row *row);
int row_set(Row *row, size_t col, const char *value);
extern int append_bytes(DynamicBuffers *buf, char *data, size_t length);
extern int append_string(DynamicBuffers *buf, char *data, size_t length);
extern int append_char(DynamicBuffers *buf, char c);
extern int ensure_capacity();


#endif // SymbolTable_H