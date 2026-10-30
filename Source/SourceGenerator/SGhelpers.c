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

    form->encoded_memoryKey.length = 0;
    form->encoded_memoryKey.capacity = 0;

    form->associationBuffer.length = 0;
    form->associationBuffer.capacity = 0;

    form->encoded_associations.length = 0;
    form->encoded_associations.capacity = 0;

    form->associatorBuffer.length = 0;
    form->associatorBuffer.capacity = 0;

    form->encoded_associators.length = 0;
    form->encoded_associators.capacity = 0;

    form->output_filename.length = 0;
    form->output_filename.capacity = 0;

    form->input_filename.length = 0;
    form->input_filename.capacity = 0;

    form->output_filepath.length = 0;
    form->output_filepath.capacity = 0;

    form->input_filepath.length = 0;
    form->input_filepath.capacity = 0;

    form->terminal_input.length = 0;
    form->terminal_input.capacity = 0;

    form->associators.data = malloc(32);
    form->associations.data = malloc(32);
    form->memoryKey.data = malloc(32);
    form->memoryKeyBuffer.data = malloc(32);
    form->associationBuffer.data = malloc(32);
    form->associatorBuffer.data = malloc(32);
    form->output_filename.data = malloc(16);
    form->input_filename.data = malloc(16);
    form->input_filepath.data = malloc(16);
    form->output_filepath.data = malloc(16);
    form->terminal_input.data = malloc(16);
    form->encoded_memoryKey.data = malloc(16);
    form->encoded_associations.data = malloc(16);
    form->encoded_associators.data = malloc(16);

    if (!form->associations.data || !form->associators.data || !form->memoryKey.data || !form->memoryKeyBuffer.data || !form->associationBuffer.data || !form->encoded_associations.data || !form->encoded_associators.data || !form->encoded_memoryKey.data) {
        perror("input_init failure");
        exit(-1);
    }
    return form;
}

int input_free(InputForm *form) {
    free(form->associators.data);
    free(form->associations.data);
    free(form->memoryKey.data);
    free(form->output_filename.data);
    free(form->input_filename.data);
    free(form->memoryKeyBuffer.data);
    free(form->associationBuffer.data);
    free(form->associatorBuffer.data);
    free(form->output_filepath.data);
    free(form->input_filepath.data);
    free(form->terminal_input.data);
    free(form->encoded_memoryKey.data);
    free(form->encoded_associations.data);
    free(form->encoded_associators.data);
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
        case 3:
            needed = form->memoryKeyBuffer.length + extra;
            if (needed <= form->memoryKeyBuffer.capacity) {
                return 0;
            }
            capacity = form->memoryKeyBuffer.capacity ? form->memoryKeyBuffer.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->memoryKeyBuffer.data, capacity);
            if (!tmp)
                return -1;

            form->memoryKeyBuffer.data = tmp;
            form->memoryKeyBuffer.capacity = capacity;
            return 0;
            break;
        case 4:
            needed = form->associationBuffer.length + extra;
            if (needed <= form->associators.capacity) {
                return 0;
            }
            capacity = form->associationBuffer.capacity ? form->associationBuffer.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->associationBuffer.data, capacity);
            if (!tmp)
                return -1;

            form->associationBuffer.data = tmp;
            form->associationBuffer.capacity = capacity;
            return 0;
            break;
        case 5:
            needed = form->associatorBuffer.length + extra;
            if (needed <= form->associators.capacity) {
                return 0;
            }
            capacity = form->associatorBuffer.capacity ? form->associatorBuffer.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->associatorBuffer.data, capacity);
            if (!tmp)
                return -1;

            form->associatorBuffer.data = tmp;
            form->associatorBuffer.capacity = capacity;
            return 0;
            break;
        case 6:
            needed = form->output_filename.length + extra;
            if (needed <= form->output_filename.capacity) {
                return 0;
            }
            capacity = form->output_filename.capacity ? form->output_filename.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->output_filename.data, capacity);
            if (!tmp)
                return -1;

            form->output_filename.data = tmp;
            form->output_filename.capacity = capacity;
            return 0;
            break;
        case 7:
            needed = form->input_filename.length + extra;
            if (needed <= form->input_filename.capacity) {
                return 0;
            }
            capacity = form->input_filename.capacity ? form->output_filename.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->input_filename.data, capacity);
            if (!tmp)
                return -1;

            form->input_filename.data = tmp;
            form->input_filename.capacity = capacity;
            return 0;
            break;
        case 8:
            needed = form->output_filepath.length + extra;
            if (needed <= form->output_filename.capacity) {
                return 0;
            }
            capacity = form->output_filepath.capacity ? form->output_filepath.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->output_filepath.data, capacity);
            if (!tmp)
                return -1;

            form->output_filepath.data = tmp;
            form->output_filepath.capacity = capacity;
            return 0;
            break;
        case 9:
            needed = form->input_filepath.length + extra;
            if (needed <= form->input_filename.capacity) {
                return 0;
            }
            capacity = form->input_filepath.capacity ? form->input_filepath.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->input_filepath.data, capacity);
            if (!tmp)
                return -1;

            form->input_filepath.data = tmp;
            form->input_filepath.capacity = capacity;
            return 0;
            break;
        case 10:
            needed = form->terminal_input.length + extra;
            if (needed <= form->input_filename.capacity) {
                return 0;
            }
            capacity = form->terminal_input.capacity ? form->terminal_input.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->terminal_input.data, capacity);
            if (!tmp)
                return -1;

            form->terminal_input.data = tmp;
            form->terminal_input.capacity = capacity;
            return 0;
            break;
        case 11:
            needed = form->encoded_memoryKey.length + extra;
            if (needed <= form->encoded_memoryKey.capacity) {
                return 0;
            }
            capacity = form->encoded_memoryKey.capacity ? form->encoded_memoryKey.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->encoded_memoryKey.data, capacity);
            if (!tmp)
                return -1;

            form->encoded_memoryKey.data = tmp;
            form->encoded_memoryKey.capacity = capacity;
            return 0;
            break;
        case 12:
            needed = form->encoded_associations.length + extra;
            if (needed <= form->encoded_associations.capacity) {
                return 0;
            }
            capacity = form->encoded_associations.capacity ? form->encoded_associations.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->encoded_associations.data, capacity);
            if (!tmp)
                return -1;

            form->encoded_associations.data = tmp;
            form->encoded_associations.capacity = capacity;
            return 0;
            break;
        case 13:
            needed = form->encoded_associators.length + extra;
            if (needed <= form->encoded_associators.capacity) {
                return 0;
            }
            capacity = form->encoded_associators.capacity ? form->encoded_associators.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            tmp = realloc(form->encoded_associators.data, capacity);
            if (!tmp)
                return -1;

            form->encoded_associators.data = tmp;
            form->encoded_associators.capacity = capacity;
            return 0;
            break;
        default:
            return -1;
            break;
    }
}

// append_bytes is for appending raw bytes from the given input

int unsigned_char_in_append_bytes(InputForm *form, unsigned char *encoded, size_t x, int control) {
    switch (control) {
        case 0:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKey.data + form->memoryKey.length, encoded, x);
            form->memoryKey.length += x;
            break;

        case 1:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associations.data + form->associations.length, encoded, x);
            form->associations.length += x;
            break;
        case 2:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associators.data + form->associators.length, encoded, x);
            form->associators.length += x;
            break;
        case 3:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKeyBuffer.data + form->memoryKeyBuffer.length, encoded, x);
            form->memoryKeyBuffer.length += x;
            break;
        case 4:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associationBuffer.data + form->associationBuffer.length, encoded, x);
            form->associationBuffer.length += x;
            break;
        case 5:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associatorBuffer.data + form->associatorBuffer.length, encoded, x);
            form->associatorBuffer.length += x;
            break;
        case 6:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->output_filename.data + form->output_filename.length, encoded, x);
            form->output_filename.length += x;
            break;
        case 7:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->input_filename.data + form->input_filename.length, encoded, x);
            form->input_filename.length += x;
            break;
        case 8:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->output_filepath.data + form->output_filepath.length, encoded, x);
            form->output_filepath.length += x;
            break;
        case 9:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->input_filepath.data + form->input_filepath.length, encoded, x);
            form->input_filename.length += x;
            break;
        case 10:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->terminal_input.data + form->terminal_input.length, encoded, x);
            form->terminal_input.length += x;
            break;
        case 11:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->encoded_memoryKey.data + form->encoded_memoryKey.length, encoded, x);
            form->encoded_memoryKey.length += x;
            break;
        case 12:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->encoded_associations.data + form->encoded_associations.length, encoded, x);
            form->encoded_associations.length += x;
            break;
        case 13:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->encoded_associators.data + form->encoded_associators.length, encoded, x);
            form->encoded_associators.length += x;
            break;
        default:
            return -1;
            break;
    } // EOS
    return 0;
}

//
int in_append_bytes(InputForm *form, char *byte, size_t x, int control) {
   switch (control) {
        case 0:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKey.data + form->memoryKey.length, byte + COMMA, x);
            form->memoryKey.length += x;
            break;

        case 1:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associations.data + form->associations.length, byte + COMMA, x);
            form->associations.length += x;
            break;
        case 2:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associators.data + form->associators.length, byte + COMMA, x);
            form->associators.length += x;
            break;
        case 3:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->memoryKeyBuffer.data + form->memoryKey.length, byte + COMMA, x);
            form->memoryKeyBuffer.length += x;
            break;
        case 4:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associationBuffer.data + form->associationBuffer.length, byte + COMMA, x);
            form->associationBuffer.length += x;
            break;
        case 5:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->associatorBuffer.data + form->associatorBuffer.length, byte + COMMA, x);
            form->associatorBuffer.length += x;
            break;
        case 6:
            if (in_ensure_capacity(&*form, x, control) != 0) {
                return -1;
            }
            memcpy(form->output_filename.data + form->output_filename.length, byte + COMMA, x);
            form->output_filename.length += x;
            break;
       case 7:
           if (in_ensure_capacity(&*form, x, control) != 0) {
               return -1;
           }
           memcpy(form->input_filename.data + form->input_filename.length, byte + COMMA, x);
           form->input_filename.length += x;
           break;
       case 8:
           if (in_ensure_capacity(&*form, x, control) != 0) {
               return -1;
           }
           memcpy(form->output_filepath.data + form->output_filepath.length, byte + COMMA, x);
           form->output_filepath.length += x;
           break;
       case 9:
           if (in_ensure_capacity(&*form, x, control) != 0) {
               return -1;
           }
           memcpy(form->input_filepath.data + form->input_filepath.length, byte + COMMA, x);
           form->input_filepath.length += x;
           break;
       case 10:
           if (in_ensure_capacity(&*form, x, control) != 0) {
               return -1;
           }
           memcpy(form->terminal_input.data + form->terminal_input.length, byte + COMMA, x);
           form->terminal_input.length += x;
           break;
       default:
            return -1;
            break;
    } // EOS
    return 0;
}

int unsigned_char_in_append_string(InputForm  *form, unsigned char *encodedString, size_t x, int control) {
    return (unsigned_char_in_append_bytes(form, encodedString, x, control));
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