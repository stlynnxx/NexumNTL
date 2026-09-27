//
// Created by steviexx on 9/26/26.
//

#include "SGhelpers.h"
#include "../SymbolTable/SymbolTable.h"
#include "SourceGenerator.h"

InputForm* input_init() {
    InputForm* form = malloc(sizeof(InputForm));
    form->associators.length = 0;
    form->associators.capacity = 0;
    form->assocationCount.length = 0 ;
    form->assocationCount.capacity = 0;
    form->associations.length = 0;
    form->associations.capacity = 0;
    form->memoryKey.length = 0;
    form->memoryKey.capacity = 0;
    form->associators.data = malloc(32);
    form->assocationCount.data = malloc(32);
    form->associations.data = malloc(32);
    form->memoryKey.data = malloc(32);
    if (!form->assocationCount.data || !form->associations.data || !form->associators.data || !form->memoryKey.data) {
        perror("input_init failure");
        exit(-1);
    }
    return form;
}

int input_free(InputForm* form) {
    free(form->associators.data);
    free(form->associations.data);
    free(form->assocationCount.data);
    free(form->memoryKey.data);
    free(form);
    form = NULL;
    return 0;
}

int in_ensure_capacity(InputForm *form, size_t extra, int control) {
    switch (control) {
        case 0:
            size_t needed = form->memoryKey.length + extra;
            if (needed <= form->memoryKey.capacity) {
                return 0;
            }
            size_t capacity = form->memoryKey.capacity ? form->memoryKey.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(form->memoryKey.data, capacity);
            if (!tmp)
                return -1;

            form->memoryKey.data = tmp;
            form->memoryKey.capacity = capacity;
            return 0;
            break;
        case 1:
            size_t needed = form->assocationCount.length + extra;
            if (needed <= form->assocationCount.capacity) {
                return 0;
            }
            size_t capacity = form->assocationCount.capacity ? form->assocationCount.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(form->memoryKey.data, capacity);
            if (!tmp)
                return -1;

            form->memoryKey.data = tmp;
            form->memoryKey.capacity = capacity;
            return 0;
            break;
        case 2:
            size_t needed = form->associations.length + extra;
            if (needed <= form->associations.capacity) {
                return 0;
            }
            size_t capacity = form->associations.capacity ? form->associations.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(form->associations.data, capacity);
            if (!tmp)
                return -1;

            form->associations.data = tmp;
            form->associations.capacity = capacity;
            return 0;
            break;
        case 3:
            size_t needed = form->associators.length + extra;
            if (needed <= form->associators.capacity) {
                return 0;
            }
            size_t capacity = form->associators.capacity ? form->associators.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(form->associators.data, capacity);
            if (!tmp)
                return -1;

            form->associators.data = tmp;
            form->associators.capacity = capacity;
            return 0;
            break;
        default:
            return -1;
            break;
    }
}
// append_bytes is for appending raw bytes from the given input
int in_append_bytes(InputForm *form, char *byte, size_t x, int control) {
    switch (control) {
        case 0:
            if (in_ensure_capacity(*form, x) != 0) {
                return -1;
            }
            memcpy(form->memoryKey.data + form->memoryKey.length, byte, x);
            form->memoryKey.length += x;
            break;
        case 1:
            if (in_ensure_capacity(form->assocationCount.data, x) != 0) {
                return -1;
            }
            memcpy(form->assocationCount.data + form->assocationCount.length, byte, x);
            form->assocationCount.length += x;
            break;
        case 2:
            if (in_ensure_capacity(form->associations.data, x) != 0) {
                return -1;
            }
            memcpy(form->associations.data + form->associations.length, byte, x);
            form->associations.length += x;
            break;
        case 3:
            if (in_ensure_capacity(form->associators.data, x) != 0) {
                return -1;
            }
            memcpy(form->associators.data + form->associators.length, byte, x);
            form->associators.length += x;
            break;
        default:
            return -1;
            break;
    } // EOS
    return 0;
}
// This is an interface for passing a string to append bytes
int in_append_string(DynamicBuffers *buf, char *string, size_t x, int control) {
    return (in_append_bytes(buf, string, strlen(string)), control);
}
// This is an interface for passing chars to append_bytes
int in_append_char(DynamicBuffers *buf, char c, int control) {
    return (in_append_bytes(buf, &c, 1), control);
}