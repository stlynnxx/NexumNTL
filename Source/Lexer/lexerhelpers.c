//
// Created by steviexx on 9/24/26.
//
#include <stddef.h>
#include "lexerhelpers.h"

#include "Lexer.h"
#include "../SymbolTable/SymbolTable.h"

int ensure_capacity(DynamicBuffers *buf, size_t extra) {
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
int append_bytes(DynamicBuffers *buf, char *byte, size_t x) {
    if (ensure_capacity(buf, x) != 0) {
        return -1; // failure
    }
    memcpy(buf->data + buf->length, byte, x);
    buf->length += x;
    return 0;
}
// This is an interface for passing a string to append bytes
int append_string(DynamicBuffers *buf, char *string, size_t x) {
    return (append_bytes(buf, string, strlen(string)));
}
// This is an interface for passing chars to append_bytes
int append_char(DynamicBuffers *buf, char c) {
    return (append_bytes(buf, &c, 1));
}

Organizer* breakdown_init() {
    Organizer *brk = malloc(sizeof(Organizer));
    brk->associations.length = 0;
    brk->associations.capacity = 0;
    brk->memoryKey.length = 0;
    brk->memoryKey.capacity = 0;
    brk->memoryKey.data = malloc(32);
    brk->associations.data = malloc(64);
    brk->workingAssociators.data = malloc(32);
    if (!brk->memoryKey.data || !brk->associations.data || !brk->workingAssociators.data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    return brk;
}
void breakdown_free(Organizer *brk) {
    free(brk->memoryKey.data);
    free(brk->associations.data);
    free(brk->workingAssociators.data);
}

void load_init(MemoryFileLoad *load) {
    load->mainArray.data = malloc(32);
    if (!load->mainArray.length) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    load->mainArray.length = 0;
    load->mainArray.capacity = 32;
}
void load_free(MemoryFileLoad *load) {
    free(load->mainArray.data);
}
