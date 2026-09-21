//
// Created by steviexx on 9/21/26.
//
#include "parserhelpers.h"

int exp_ensure_capacity(Export *export, size_t extra, int control)
{
    size_t needed;
    size_t capacity;

    switch (control) {
        case 0: {
            needed = export->memKey.length + extra;
            if (needed <= export->memKey.capacity) {
                return 0;
            }
            capacity = export->memKey.capacity ? export->memKey.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->memKey.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->memKey.data = tmp;
            export->memKey.capacity = capacity;
            return 0;
        }
        case 1: {
            needed = export->assoc.length + extra;
            if (needed <= export->assoc.capacity) {
                return 0;
            }
            capacity = export->assoc.capacity ? export->assoc.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->assoc.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->assoc.data = tmp;
            export->assoc.capacity = capacity;
            return 0;
            break;
        }
        case 2: {
            needed = export->associators.length + extra;
            if (needed <= export->associators.capacity) {
                return 0;
            }
            capacity = export->associators.capacity ? export->associators.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->associators.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->associators.data = tmp;
            export->associators.capacity = capacity;
            return 0;

            break;
        }
        case 3: {
            needed = export->encodedMorpheme.length + extra;
            if (needed <= export->encodedMorpheme.capacity) {
                return 0;
            }
            capacity = export->encodedMorpheme.capacity ? export->encodedMorpheme.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->encodedMorpheme.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->encodedMorpheme.data = tmp;
            export->encodedMorpheme.capacity = capacity;
            return 0;
            break;
        }
        default:
            return -1;
            break;
    }
}

// append_bytes is for appending raw bytes from the given input
int exp_append_bytes(Export *export, char *byte, size_t x, int control)
{
    if (exp_ensure_capacity(export, x, control) != 0) {
        return -1; // failure
    }
    switch (control) {
        case 0:
            memcpy(export->memKey.data + export->memKey.length, byte, x);
            export->memKey.length += x;
            return 0;
            break;
        case 1:
            memcpy(export->associators.data + export->associators.length, byte, x);
            export->associators.length += x;
            return 0;
            break;
        case 2:
            memcpy(export->assoc.data + export->assoc.length, byte, x);
            export->assoc.length += x;
            return 0;
            break;
        case 3:
            memcpy(export->encodedMorpheme.data + export->encodedMorpheme.length, byte, x);
            export->encodedMorpheme.length += x;
            return 0;
            break;
        default:
            perror("Default error");
            exit(EXIT_FAILURE);
    }
}

// This is an interface for passing a string to append bytes
int exp_append_string(Export *export, char *string, size_t x, int control) {
    return (exp_append_bytes(export, string, strlen(string), control));
}
// This is an interface for passing chars to append_bytes
int exp_append_char(Export *export, char c, int control) {
    return (exp_append_bytes(export, &c, 1),control);
}

// for builder
int builder_ensure_capacity(Builder *builderr, size_t extra, int control)
{
    size_t needed;
    size_t capacity;

    switch (control) {
        case 0: {
            needed = builderr->memKeyScratch.length + extra;
            if (needed <= builderr->memKeyScratch.capacity) {
                return 0;
            }
            capacity = builderr->memKeyScratch.capacity ? builderr->memKeyScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->memKeyScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->memKeyScratch.data = tmp;
            builderr->memKeyScratch.capacity = capacity;
            return 0;
        }
        case 1: {
            needed = builderr->assocScratch.length + extra;
            if (needed <= builderr->assocScratch.capacity) {
                return 0;
            }
            capacity = builderr->assocScratch.capacity ? builderr->assocScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->assocScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->assocScratch.data = tmp;
            builderr->assocScratch.capacity = capacity;
            return 0;
            break;
        }
        case 2: {
            needed = builderr->associatorScratch.length + extra;
            if (needed <= builderr->associatorScratch.capacity) {
                return 0;
            }
            capacity = builderr->associatorScratch.capacity ? builderr->associatorScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->associatorScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->associatorScratch.data = tmp;
            builderr->associatorScratch.capacity = capacity;
            return 0;

            break;
        }
        case 3: {
            needed = builderr->wC.length + extra;
            if (needed <= builderr->wC.capacity) {
                return 0;
            }
            capacity = builderr->wC.capacity ? builderr->wC.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->wC.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->wC.data = tmp;
            builderr->wC.capacity = capacity;
            return 0;
            break;
        }
        default:
            return -1;
            break;
    }
}

// append_bytes is for appending raw bytes from the given input
int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control)
{
    if (builder_ensure_capacity(builderr, x, control) != 0) {
        return -1; // failure
    }
    switch (control) {
        case 0:
            memcpy(builderr->memKeyScratch.data + builderr->memKeyScratch.length, byte, x);
            builderr->memKeyScratch.length += x;
            return 0;
            break;
        case 1:
            memcpy(builderr->associatorScratch.data + builderr->associatorScratch.length, byte, x);
            builderr->associatorScratch.length += x;
            return 0;
            break;
        case 2:
            memcpy(builderr->assocScratch.data + builderr->assocScratch.length, byte, x);
            builderr->assocScratch.length += x;
            return 0;
            break;
        case 3:
            memcpy(builderr->wC.data + builderr->wC.length, byte, x);
            builderr->wC.length += x;
            return 0;
            break;
        default:
            perror("Default error");
            exit(EXIT_FAILURE);
    }
}

// This is an interface for passing a string to append bytes
int builder_append_string(Builder *builderr, char *string, size_t x, int control) {
    return (builder_append_bytes(builderr, string, strlen(string), control));
}
// This is an interface for passing chars to append_bytes
int builder_append_char(Builder *builderr, char c, int control) {
    return (builder_append_bytes(builderr, &c, 1),control);
}
