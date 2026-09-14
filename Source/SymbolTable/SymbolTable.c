#include "SymbolTable.h"

char *valuesMatrix[26][14] = {
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

char *encodedMatrix[26][14] = {
    {"A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "AX", "A11", "NULL"}, // A
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // B
    {"C0", "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "NULL", "NULL", "NULL", "NULL"}, // C
    {"D0", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // D
    {"E0", "E1", "E2", "E3", "E4", "E5", "E6", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // E
    {"F0", "F1", "F2", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // F
    {"G0", "G1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // G
    {"H0", "H1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // H
    {"I0", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "NULL", "NULL"}, // I
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // J
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // K
    {"L0", "L1", "L2", "L3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // L
    {"M0", "M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "MX", "M11"}, // M
    {"N0", "N1", "N2", "N3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // N
    {"O0", "O1", "O2", "O3", "O4", "O5", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // O
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // P
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // Q
    {"R0", "R1", "R2", "R3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // R
    {"S0", "S1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // S
    {"T0", "T1", "T2", "T3", "T4", "T5", "T6", "T7", "T8", "T9", "NULL", "NULL"}, // T
    {"U0", "U1", "U2", "U3", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // U
    {"V0", "V1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // V
    {"W0", "W1", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // W
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // X
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"}, // Y
    {"NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL", "NULL"} // Z

};
int hexMatrix[40][40] = {
    {0x15},

};

int countsMatrix[26][14] = {
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
char firsts[40] = {'t','i','a','o','e','r','l','m','f','n', 'u'};
char secondaries[80] = {
    'b', 'c', 'd', 'g', 'h', 'j', 'k', 'p', 'q', 's', 'u', 'v', 'w', 'x', 'y', 'z'
};

// Helper functions
void seed_table(Table *table) {
    for (int r = 0; r < 26; r++) {
        for (int c = 0; c < table->row[r].count; c++) {
            const char *v = valuesMatrix[r][c];
            if (!v || strcmp(v, "NULL") == 0) continue;
            row_set(&table->row[r], c, v);
        }
    }
}

int row_init(Row *row)
{
    row->cols = calloc(16, sizeof(DynamicBuffers));
    if (!row->cols) return -1;
    row->count    = 0;
    row->capacity = 16;
    return 0;
}

int row_set(Row *row, size_t col, const char *value) {
    if (col >= row->capacity) {
        size_t new_capacity = row->capacity ? row->capacity * 2 : 16;
        DynamicBuffers *tmp = realloc(row->cols, sizeof(DynamicBuffers) * new_capacity);
        if (!tmp) return (-1);
        memset(row->cols, 0, sizeof(DynamicBuffers) * new_capacity);
        memset(tmp + row->capacity, 0,
            (new_capacity - row->capacity) * sizeof(DynamicBuffers));

        row->cols     = tmp;
        row->capacity = new_capacity;
    } // end if
    if (col >= row->count) {
        row->count = col + 1;
    }
    DynamicBuffers *cell = &row->cols[col];
    if (cell->data) free(cell->data);
    size_t len = strlen(value);
    cell-> data = malloc(len + 1);
    if (!cell->data) return (-1);
    memcpy(cell->data, value, len + 1);
    cell->length = cell->capacity = len;
    return 0;
}

int values_ensure_capacity(DynamicBuffers *buf, size_t extra) {
    size_t needed = buf->length + extra;
    if (needed <= buf->capacity) {
        return 0;
    }
    size_t capacity = buf->capacity ? buf->capacity : 16;
    while (needed > capacity) {
        capacity *= 2;
    }
    char *tmp = realloc(buf->data, capacity);
    if (!tmp)
        return -1;

    buf->data = tmp;
    buf->capacity = capacity;
    return 0;
}

// append_bytes is for appending raw bytes from the given input
int values_append_bytes(DynamicBuffers *buf, const char *byte, size_t x) {
    if (values_ensure_capacity(buf, x) != 0) {
        return -1; // failure
    }
    memcpy(buf->data + buf->length, byte, x);
    buf->length += x;
    return 0;
}

// This is an interface for passing a string to append bytes
int values_append_string(DynamicBuffers *buf, const char *string) {
    return (values_append_bytes(buf, string, strlen(string)));
}

// This is an interface for passing chars to append_bytes
int values_append_char(DynamicBuffers *buf, char c) {
    return (values_append_bytes(buf, &c, 1));
}
void encode_usrmor(DynamicBuffers *buf, Table table, const char morph[]) {
    char firstChar = morph[0];
    // I think from here we will need to check the length of the
    // row corrosponding with firstChar and then add one to it and use that
    // index to finish our encoded morpheme which will end up being firstChar + index
    size_t rowCheck = table.row[firstChar].count;
    char checkChar = (char)rowCheck;
    strcat(firstChar, checkChar);


void usrmor_chk(DynamicBuffers *buf, const char morph[]) {
    size_t morphLen = sizeof(morph) / sizeof(morph[0]);
    switch (morphLen) {
        case 0:
            perror("Empty morpheme");
            exit(EXIT_FAILURE);
            break;
        case 1:
            perror("Char error- please append more than a single char");
            exit(EXIT_FAILURE);
            break;
        case 2:

            break;

    }
}
// This is for adding morphemes to the valuesMatrix
// Pass routeFlag as 0 for appending bytes, 1 for appending a char, and 2 for appending a string
int add_morph(DynamicBuffers *buf, const char *morph, int routeFlag) {
    switch (routeFlag) {
        case 0:
            values_append_bytes(buf, morph, (strlen(morph) + 1));
            break;
        case 1:
            values_append_char(buf, morph[0]);
            break;
        case 2:
            values_append_string(buf, morph);
            break;
        default:
            return -1;
            break;
    }
}