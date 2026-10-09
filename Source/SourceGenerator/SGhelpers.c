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

    form->associations.length = 0;
    form->associations.capacity = 0;

    form->memoryKey.length = 0;
    form->memoryKey.capacity = 0;

    form->memoryKeyBuffer.length = 0;
    form->memoryKeyBuffer.capacity = 0;

    form->associationBuffer.length = 0;
    form->associationBuffer.capacity = 0;

    form->associatorBuffer.length = 0;
    form->associatorBuffer.capacity = 0;

    form->filename.length = 0;
    form->filename.capacity = 0;

    form->associators.data = malloc(32);
    form->associations.data = malloc(32);
    form->memoryKey.data = malloc(32);
    form->memoryKeyBuffer.data = malloc(32);
    form->associationBuffer.data = malloc(32);
    form->associatorBuffer.data = malloc(32);
    form->filename.data = malloc(16);

    if (!form->associations.data || !form->associators.data || !form->memoryKey.data || !form->memoryKeyBuffer.data || !form->associationBuffer.data || !form->associatorBuffer) {
        perror("input_init failure");
        exit(-1);
    }
    return form;
}

int input_free(InputForm* form) {
    free(form->associators.data);
    free(form->associations.data);
    free(form->memoryKey.data);
    free(form->filename.data);
    free(form->memoryKeyBuffer.data);
    free(form->associationBuffer.data);
    free(form->associatorBuffer.data);
    free(form);
    form = NULL;
    return 0;
}

int in_ensure_capacity(InputForm *form, size_t extra, int control) {
    size_t needed;
    size_t capacity;
    char *tmp;
    switch (control) {
        case 0:
            needed = form->memoryKey.length + extra;
            if (needed <= form->memoryKey.capacity) {
                return 0;
            }
            capacity = form->memoryKey.capacity ? form->memoryKey.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->memoryKey.data, capacity);
            if (!tmp)
                return -1;

            form->memoryKey.data = tmp;
            form->memoryKey.capacity = capacity;
            return 0;
            break;

        case 1:
            needed = form->associations.length + extra;
            if (needed <= form->associations.capacity) {
                return 0;
            }
            capacity = form->associations.capacity ? form->associations.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->associations.data, capacity);
            if (!tmp)
                return -1;

            form->associations.data = tmp;
            form->associations.capacity = capacity;
            return 0;
            break;
        case 2:
            needed = form->associators.length + extra;
            if (needed <= form->associators.capacity) {
                return 0;
            }
            capacity = form->associators.capacity ? form->associators.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->associators.data, capacity);
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
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKey.data + form->memoryKey.length, byte, x);
            form->memoryKey.length += x;
            break;

        case 1:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associations.data + form->associations.length, byte, x);
            form->associations.length += x;
            break;
        case 2:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associators.data + form->associators.length, byte, x);
            form->associators.length += x;
            break;
        case 3:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKeyBuffer.data + form->memoryKey.length, byte, x);
            form->memoryKeyBuffer.length += x;
            break;
        case 4:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associationBuffer.data + form->associationBuffer.length, byte, x);
            form->associationBuffer.length += x;
            break;
        case 5:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associatorBuffer.data + form->associatorBuffer.length, byte, x);
            form->associatorBuffer.length += x;
            break;
        case 6:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->filename.data + form->filename.length, byte, x);
            form->filename.length += x;
            break;
        default:
            return -1;
            break;
    } // EOS
    return 0;
}

// This is an interface for passing a string to append bytes
int in_append_string(InputForm *form, char *string, size_t x, int control) {
    return (in_append_bytes(form, string, x, control));
}

// This is an interface for passing chars to append_bytes
int in_append_char(InputForm *form, char c, int control) {
    return (in_append_bytes(form, &c, 1, control));
}
void SG_line_parse(InputForm *form) {
    int associator_chk;
    char *workingChar;
    for (int i = 0; i < form->associators.length; i++)
    {
        *workingChar = form->associators.data[i];

        switch (*workingChar)
        {
            case NAMETOKEN:
                break;
            case ASSOCIATOR:
                associator_chk = 1;
                break;
            case SEMICOLON:
                break;
                // default will handle alphanumerics
            default:
                if isalnum(*workingChar) {
                    if (associator_chk != 1) {
                        i = form->associators.length;
                        break;
                    }
                    if (associator_chk == 1) {
                        if (*workingChar == COMMA) {
                            associator_chk = 0;
                        }
                        in_append_string(form, workingChar, sizeof(workingChar), 2);
                }
            }
                else
                {
                    if (*workingChar == COMMA)
                    {

                        break;
                    }
                }
                break;
        }
    }

}