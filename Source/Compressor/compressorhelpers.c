//
// Created by steviexx on 9/27/26.
//

#include "compressorhelpers.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

Input* in_init() {
    Input *in = malloc(sizeof(Input));
    in->buffer.capacity = 0;
    in->buffer.length = 0;
    in->terminalInput.length = 0;
    in->terminalInput.capacity = 0;
    in->buffer.data = malloc(32);
    in->terminalInput.data = malloc(32);
    if (!in->buffer.capacity || !in->buffer.data || !in->buffer.length || !in->terminalInput.capacity || !in->terminalInput.data || !in->terminalInput.length) {
        perror("in_init error");
        exit(-1);
    }
    return in;
}

int comp_ensure_capacity(Input *in, size_t extra) {
    size_t needed = in->terminalInput.length + extra;
    if (needed <= in->terminalInput.capacity) {
        return 0;
    }
    size_t capacity = in->terminalInput.capacity ? in->terminalInput.capacity : 16;
    while (needed > capacity) {
        capacity *= 2;
    }
    char *tmp = realloc(in->terminalInput.data, capacity);
    if (!tmp)
        return -1;

    in->terminalInput.data = tmp;
    in->terminalInput.capacity = capacity;
    return 0;
}

// append_bytes is for appending raw bytes from the given input
int comp_append_bytes(Input *in, char *byte, size_t x) {
    if (comp_ensure_capacity(in, x) != 0) {
        return -1; // failure
    }
    memcpy(in->terminalInput.data + in->terminalInput.length, byte, x);
    in->terminalInput.length += x;
    return 0;
}
// This is an interface for passing a string to append bytes
int comp_append_string(Input *in, Unencoded *unencoded, int foundI, size_t x) {
    return (comp_append_bytes(in, unencoded->morpheme.data[foundI], strlen(unencoded->morpheme.data[foundI])));
}
// This is an interface for passing chars to append_bytes
int usr_append_char(Unencoded *unencoded, char c) {
    return (comp_append_bytes(unencoded, &c, 1));
}


int explore_dir(const char* dir_path, const char* extension,
                      char*** results, int* count) {
    DIR* dir = opendir(dir_path);
    if (!dir) {
        perror("opendir");
        return -1;
    }

    *results = NULL;
    *count = 0;
    int capacity = 0;

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        size_t len = strlen(entry->d_name);
        size_t ext_len = strlen(extension);

        if (len > ext_len &&
            strcmp(entry->d_name + len - ext_len, extension) == 0) {

            // Grow array if needed
            if (*count >= capacity) {
                capacity = capacity ? capacity * 2 : 8;
                char** temp = realloc(*results, capacity * sizeof(char*));
                if (!temp) {
                    closedir(dir);
                    return -1;
                }
                *results = temp;
            }

            (*results)[*count] = strdup(entry->d_name);
            (*count)++;
            }
    }

    closedir(dir);
    return *count;
}
