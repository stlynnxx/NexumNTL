//
// Created by steviexx on 9/24/26.
//

#include "usrmorhelpers.h"


Unencoded* unencoded_init() {
    Unencoded* unencoded = (Unencoded*)malloc(sizeof(Unencoded));
    unencoded->morpheme.length = 0;
    unencoded->morpheme.capacity = 0;
    unencoded->morpheme.data = malloc(16);
    if (!unencoded->morpheme.data || !unencoded->morpheme.capacity || !unencoded->morpheme.data) {
        perror("malloc failure");
        exit(-1);
    }
    return unencoded;
}

int unencoded_free(Unencoded* unencoded) {
    free(unencoded->morpheme.data);
    free(unencoded);
    unencoded = NULL;
    return 0;
}


int usr_ensure_capacity(Unencoded *unencoded, size_t extra) {
    size_t needed = unencoded->morpheme.length + extra;
    if (needed <= unencoded->morpheme.capacity) {
        return 0;
    }
    size_t capacity = unencoded->morpheme.capacity ? unencoded->morpheme.capacity : 16;
    while (needed > capacity) {
        capacity *= 2;
    }
    char *tmp = realloc(unencoded->morpheme.data, capacity);
    if (!tmp)
        return -1;

    unencoded->morpheme.data = tmp;
    unencoded->morpheme.capacity = capacity;
    return 0;
}

// append_bytes is for appending raw bytes from the given input
int usr_append_bytes(Unencoded *unencoded, char *byte, size_t x) {
    if (usr_ensure_capacity(unencoded, x) != 0) {
        return -1; // failure
    }
    memcpy(unencoded->morpheme.data + unencoded->morpheme.length, byte, x);
    unencoded->morpheme.length += x;
    return 0;
}
// This is an interface for passing a string to append bytes
int terminalToNexcUsrAppendString(Unencoded *unencoded, Export *exp, int foundI, size_t x) {
    return (usr_append_bytes(unencoded, exp,  sizeof(exp)));
}
int usr_append_string(Unencoded *unencoded, char *byte, int foundI, size_t x) {
    return (usr_append_bytes(unencoded, byte,  sizeof(byte)));
}
// This is an interface for passing chars to append_bytes
int usr_append_char(Unencoded *unencoded, char c) {
    return (usr_append_bytes(unencoded, &c, 1));
}