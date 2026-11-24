//
// Created by steviexx on 9/27/26.
//
#include "../SymbolTable/SymbolTable.h"
#include "compressorhelpers.h"
#include "../Parser/parserhelpers.h"
#include "../Parser/Parser.h"
#include "../SourceGenerator/SGruninterface.h"
#include "../mainhelpers.h"
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

/*InputForm* in_init() {
    Input *in = malloc(sizeof(Input));
    in->buffer.capacity = 0;
    in->buffer.length = 0;
    in->terminalInput.length = 0;
    in->terminalInput.capacity = 0;
    in->buffer.Data = malloc(32);
    in->terminalInput.Data = malloc(32);
    if (!in->buffer.capacity || !in->buffer.Data || !in->buffer.length || !in->terminalInput.capacity || !in->terminalInput.Data || !in->terminalInput.length) {
        perror("in_init error");
        exit(-1);
    }
    return in;
}*/

VocabForm* vocab_form_init() {
    VocabForm *vocab_form = malloc(sizeof(VocabForm));

    vocab_form->parent_morpheme.length = 0;
    vocab_form->parent_morpheme.capacity = 0;
    vocab_form->parent_morpheme.data = malloc(8);

    vocab_form->association.length = 0;
    vocab_form->association.capacity = 0;
    vocab_form->association.data = malloc(8);

    vocab_form->associator.length = 0;
    vocab_form->associator.capacity = 0;
    vocab_form->associator.data = malloc(8);

    return vocab_form;
}
int comp_ensure_capacity(InputForm *form, size_t extra) {
    size_t needed = form->terminalInput.length + extra;
    if (needed <= form->terminalInput.capacity) {
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

long get_file_size(FILE *in_file) {
    fseek(in_file, 0, SEEK_END);
    long size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET); // Reset pointer
    return size;
}

int carryover_associator(
    VocabForm *vocab_form,
    const char *associator
) {
    if (vocab_form == NULL || associator == NULL) {
        return -1;
    }

    size_t length = strlen(associator);

    // Allocate the replacement before touching the existing buffer.
    if (length == SIZE_MAX) {
        return -1;
    }

    char *copy = malloc(length + 1);

    if (copy == NULL) {
        return -1;
    }

    memcpy(copy, associator, length + 1);

    // Replace the parent morpheme only after allocation succeeds.
    free(vocab_form->parent_morpheme.data);

    vocab_form->parent_morpheme.data = copy;
    vocab_form->parent_morpheme.length = length;
    vocab_form->parent_morpheme.capacity = length + 1;

    return 0;
}

char generate_ID(VocabForm *vocab_form, int control) {
    InputForm *engram_input_form = input_init();
    size_t val_length = 0;
    switch (control) {
        case Engram_Association: {
            const char *value = valuesSearch(vocab_form->association.data);
            if (value != NULL)
            {
                val_length = strlen(value);
            }
            return *value;
            break;
        }
        case Engram_Associator: {
            const char *value = valuesSearch(vocab_form->associator.data);
            if (value != NULL)
            {
                val_length = strlen(value);
            }
            return *value;
            break;
        }
        case Engram_Memkey: {
            const char *value = valuesSearch(vocab_form->parent_morpheme.data);
            if (value != NULL)
            {
                val_length = strlen(value);
            }
            return *value;
            break;
        }
        default: {
            break;
        }

    }

}


void vocab_file_parse(FILE* vocab_file, Engram *engram) {
    if (vocab_file == NULL || engram == NULL) {
        return;
    }

    Row row = {0};
    row_init(&row);

    VocabForm *vocab_form = vocab_form_init();
    if (vocab_form == NULL) {
        fprintf(stderr, "Failed to initialize vocabulary form.\n");
        return;
    }

    int open_brace_check_one = FALSE;
    int open_brace_check_two = FALSE;
    int semicolon_check = FALSE;
    int memkey_check = FALSE;
    int colon_check = FALSE;
    int association_check = FALSE;
    int bank_enter_check = FALSE;
    int associator_count = 0;
    int association_count = 0;
    int associator_check = FALSE;
    int name_token_check_one = FALSE;
    int name_token_check_two = FALSE;
    int comma_check = FALSE;
    int close_brace_check = FALSE;
    int line_complpete = FALSE;
    int workingChar;

    while ((workingChar = fgetc(vocab_file)) != EOF)
    {
        switch (workingChar) {
            case OPENBRACE:
                open_brace_check_one = TRUE;
                if (colon_check == TRUE) {
                    open_brace_check_two = TRUE;
                    colon_check = UNSET;
                }
                break;
            case NAMETOKEN:
                if (open_brace_check_one == TRUE) {
                    name_token_check_one = TRUE;
                }
                if (memkey_check == TRUE) {
                    name_token_check_two = TRUE;
                    name_token_check_one = UNSET;
                    // vocab_append_string(vocab_form, ",", Engram_Memkey);
                    if (vocab_append_string(
                        vocab_form,
                        ",",
                        Engram_Association
                        ) != 0) {
                        fprintf(stderr, "Failed to append association.\n");
                        }
                    memkey_check = UNSET;
                    open_brace_check_one = UNSET;

                }
                if (comma_check == TRUE || open_brace_check_two == TRUE) {
                    association_check = TRUE;
                    comma_check = UNSET;
                }
                break;
            case COLON:
                colon_check = TRUE;
                break;
            case ASSOCIATOR:
                if (comma_check == TRUE || open_brace_check_one == TRUE) {
                    associator_check = TRUE;
                    associator_count++;
                    comma_check = UNSET;
                }
                break;
            case SEMICOLON:
                if (close_brace_check == TRUE) {
                    semicolon_check = TRUE;
                }
                break;
            case COMMA:
                comma_check = TRUE;
                if (association_check == TRUE) {
                    if (vocab_append_string(
                       vocab_form,
                       ",",
                       Engram_Association
                       ) != 0) {
                        fprintf(stderr, "Failed to append association.\n");
                       }
                    if (associator_check == UNSET || associator_check == FALSE) {
                        association_check = FALSE;
                    }
                }
                association_check = UNSET;
                associator_check = UNSET;
                break;
            case CLOSEBRACE:
                close_brace_check = TRUE;
                if (open_brace_check_two == TRUE) {
                    if (vocab_form->association.data != NULL) {
                        engram_append(
                            vocab_form->association.data,
                            engram,
                            Engram_Association
                        );
                    }
                    open_brace_check_two = FALSE;
                }
                comma_check = UNSET;
                break;
                // default will handle alphanumerics
            default:
                if (isalnum((unsigned char)workingChar)) {
                    if (name_token_check_one == TRUE && (name_token_check_two == UNSET || name_token_check_two == FALSE)) {
                        memkey_check = TRUE;
                    }
                    char character[2] = {
                        (char)workingChar,
                        '\0'
                    };
                    if (associator_check == TRUE) {

                        if (vocab_append_string(
                            vocab_form,
                            character,
                            Engram_Associator
                            ) != 0) {
                            fprintf(stderr, "Failed to append associator.\n");
                       }
                        // This is generating the ID; we still need somewhere to save it to
                        generate_ID(vocab_form, Engram_Associator);
                    }
                    else if (association_check == TRUE) {
                        if (vocab_append_string(
                            vocab_form,
                            character,
                            Engram_Association) != 0) {
                            fprintf(stderr, "Failed to append association.\n");
                       }
                        // This is generating the ID; we still need somewhere to save it to
                        generate_ID(vocab_form, Engram_Association);

                    }
                    // Memkey
                    else if (name_token_check_one == TRUE) {
                        if (vocab_append_string(
                            vocab_form,
                            character,
                       Engram_Memkey) != 0) {
                            fprintf(stderr, "Failed to append association.\n");
                       }
                        // This is generating the ID; we still need somewhere to save it to
                        generate_ID(vocab_form, Engram_Memkey);
                    }
                }
                break;
        } // End of switch


    } // end of while

}

void line_parse(Export *export,ParserBuffers *pbuffers, InputForm *form, FILE* export_file) {
    int control;
    char *workingChar;
    bool open_brace_check = UNSET;
    bool open_brace_check_two = UNSET;
    bool semicolon_check = UNSET;
    bool association_check = UNSET;
    int association_count = 0;
    bool associator_check = UNSET;
    bool name_token_one_check = UNSET;
    bool name_token_two_check = UNSET;
    bool comma_check = UNSET;
    bool close_brace_check = UNSET;

    for (int i = 0; i < pbuffers->line.length; i++)
    {
        *workingChar = pbuffers->line.data[i];

        switch (*workingChar) {
            case OPENBRACE:
                open_brace_check = TRUE;
                control = 0;
                if (semicolon_check == TRUE && open_brace_check == TRUE) {
                    open_brace_check_two = 1;
                    control = 1;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case NAMETOKEN:
                if (name_token_one_check && name_token_two_check == FALSE && open_brace_check == FALSE) {
                    name_token_one_check = TRUE;
                    control = 0;
                }
                if (name_token_one_check == TRUE && name_token_two_check == FALSE && open_brace_check == TRUE) {
                    name_token_two_check = TRUE;
                    control = 0;
                }
                if (name_token_one_check == TRUE && name_token_two_check == TRUE && semicolon_check == TRUE) {
                    name_token_two_check = FALSE;
                    control = 1;
                }
                if (comma_check == TRUE && associator_check == TRUE) {
                    associator_check = FALSE;
                    control = 1;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case ASSOCIATOR:
                associator_check = TRUE;
                if (associator_check == TRUE) {
                    association_count++;
                    control = 2;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case SEMICOLON:
                semicolon_check = TRUE;
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case COMMA:
                if (name_token_one_check && name_token_two_check == TRUE && open_brace_check_two == TRUE) {
                    comma_check = TRUE;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case CLOSEBRACE:
                close_brace_check = TRUE;
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
                // default will handle alphanumerics
            default:
                while (isalnum(workingChar)) {
                if (semicolon_check) {
                    association_check = TRUE;
                    association_count++;
                }
                in_append_string(form,workingChar,sizeof(workingChar),control);
            }
                if (!isalnum(workingChar) && association_check == TRUE) {
                    name_token_two_check = TRUE;
                }
                export->assocCount = form->assocCount + association_count;
                break;
        }
    }
}

void input_form_line_parse(InputForm *form, FILE* export_file) {
    int control;
    char *workingChar;
    bool open_brace_check = false;
    bool open_brace_check_two = false;
    bool semicolon_check = false;
    bool association_check = false;
    int association_count = 0;
    bool associator_check = false;
    int associator_count = 0;
    bool name_token_one_check = false;
    bool name_token_two_check = false;
    bool comma_check = false;
    bool close_brace_check = false;

    for (int i = 0; i < pbuffers->line.length; i++)
    {
        *workingChar = pbuffers->line.data[i];

        switch (*workingChar) {
            case OPENBRACE:
                open_brace_check = false;
                control = 0;
                if (semicolon_check == true && open_brace_check == true) {
                    open_brace_check_two = 1;
                    control = 1;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case NAMETOKEN:
                if (name_token_one_check && name_token_two_check == false && open_brace_check == true) {
                    name_token_one_check = true;
                    control = 0;
                }
                if (name_token_one_check == true && name_token_two_check == false && open_brace_check == true) {
                    name_token_two_check = true;
                    control = 0;
                }
                if (name_token_one_check == true && name_token_two_check == true && semicolon_check == true) {
                    name_token_two_check = false;
                    control = 1;
                }
                if (comma_check == true && associator_check == true) {
                    associator_check = false;
                    control = 1;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case ASSOCIATOR:
                associator_check = true;
                if (associator_check == true) {
                    association_count++;
                    control = 2;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case SEMICOLON:
                semicolon_check = true;
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case COMMA:
                if (name_token_one_check && name_token_two_check == true && open_brace_check_two == true) {
                    comma_check = true;
                }
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
            case CLOSEBRACE:
                close_brace_check = true;
                in_append_bytes(form, workingChar, sizeof(*workingChar), control);
                break;
                // default will handle alphanumerics
            default:
                while (isalnum(workingChar)) {
                if (semicolon_check) {
                    association_check = true;
                    association_count++;
                }
                in_append_string(form,workingChar,sizeof(workingChar),control);
            }
                if (!isalnum(workingChar) && association_check == true) {
                    name_token_two_check = true;
                }
                export->assocCount = form->assocCount + association_count;
                break;
        }
    }
}

int pbuffer_line_clear(ParserBuffers *pbuffers) {
    if (!pbuffers->line.length || !pbuffers->line.data) {return -1;}
    pbuffers->line.length = 0;
    pbuffers->line.data = 0;
    return 0;
}

void append_file_to_buffers(Export* export,FILE* in_file, ParserBuffers *pbuffers, InputForm *form, size_t file_size)
    {
    FILE* export_file;
    for (int i = 0; i <= file_size; i++)
    {
        char *workingChar;
        bool name_token_find;
        int found_start;
        int first_char = 0;
        // Appending a single line from the file to pbuffers->line
        while ((*workingChar = fgetc(in_file)) != SEMICOLON) {
            pbuff_append_char(pbuffers, *workingChar, 3);

            /*
            if (!found_start && *workingChar == OPENBRACE || CLOSEBRACE) {
                found_start = 1;
                pbuff_append_string(pbuffers,workingChar,sizeof(workingChar),3);
                continue;
            }
            if (found_start && *workingChar == NAMETOKEN) {
                name_token_find = true;

            }
            if (found_start && *workingChar != SEMICOLON && found_start == 1) {
                first_char = 1;
                pbuff_append_string(pbuffers,workingChar,sizeof(workingChar),3);
                continue;
            }
            if (found_start && *workingChar == SEMICOLON && first_char == 1) {
                pbuff_append_string(pbuffers,workingChar,sizeof(workingChar),3);
                pbuff_append_string(pbuffers, "\0", sizeof("/0"),3);
                break;
            }*/
        }
        if (*workingChar == SEMICOLON) {
            pbuff_append_char(pbuffers, *workingChar, 3);
        }
        line_parse(export,pbuffers, form, export_file);
        pbuffer_line_clear(pbuffers);

        // fclose(in_file);
        // free(in_file);
    }

}

FILE* init_export(InputForm *form) {
    FILE *export_file = fopen(form->output_filename.data, "w");
}

int comp_open_file(InputForm *form,FILE* in_file,FILE* export_file,ParserBuffers *pbuffers, int output) {
    size_t file_size = get_file_size(in_file);
    Export *export_form = export_form_init();
    if (!in_file) {
        perror("comp_open_file error");
        return -1;
    }
    // calls line parse and appends file contents to pbuffers
    append_file_to_buffers(export_form,in_file, pbuffers, form, file_size);
    // match, verify, encode, and appending to export_form
    export_form = match(export_form,form,export_file,output,pbuffers);
    // sending export and export file to the source generator
    send_to_generator(export_form,export_file);
    in_file_to_nexc_cleanup(in_file,export_form,form);
}

int comp_from_file_append_bytes(InputForm *form,ParserBuffers *pbuffers, FILE* in_file, FILE* export_file,int output) {
    //  We are appending the file to pbuffers
    int cofr;
    cofr = comp_open_file(form,in_file,export_file, pbuffers, output);
    if (cofr == -1) {
        exit(-1);
    }
    return 1;
}
// append_bytes is for appending raw bytes from the given input
int comp_append_bytes(Unencoded *unencoded, Input *in) {
    size_t x = in->terminalInput.length;
    if (vocab_ensure_capacity(in, x) != 0) {
        return -1; // failure
    }
    memcpy(unencoded->morpheme.data+ unencoded->morpheme.length, in->terminalInput.data, x);
    in->terminalInput.length += x;
    return 0;
}

int values_append_string(Unencoded *unencoded, Input *in) {
    return (comp_append_bytes(unencoded, in));
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


int vocab_form_free(VocabForm *vocab_form) {
    free(vocab_form->parent_morpheme.data);
    free(vocab_form->association.data);
    free(vocab_form->associator.data);
    free(vocab_form);
    return 0;
}

int vocab_ensure_capacity(
    VocabForm *vocab_form,
    size_t extra,
    int control_flag
) {
    if (vocab_form == NULL) {
        return -1;
    }

    DynamicBuffers *buffer = NULL;

    switch (control_flag) {
        case Engram_Memkey:
            buffer = &vocab_form->parent_morpheme;
            break;

        case Engram_Association:
            buffer = &vocab_form->association;
            break;

        case Engram_Associator:
            buffer = &vocab_form->associator;
            break;

        default:
            return -1;
    }

    // Prevent overflow when calculating required capacity.
    if (buffer->length == SIZE_MAX ||
        extra > SIZE_MAX - buffer->length - 1) {
        return -1;
        }

    // Include one byte for the null terminator.
    size_t needed = buffer->length + extra + 1;

    if (needed <= buffer->capacity) {
        return 0;
    }

    size_t capacity = buffer->capacity ? buffer->capacity : 16;

    while (capacity < needed) {
        if (capacity > SIZE_MAX / 2) {
            capacity = needed;
            break;
        }

        capacity *= 2;
    }

    char *tmp = realloc(buffer->data, capacity);

    if (tmp == NULL) {
        return -1;
    }

    buffer->data = tmp;
    buffer->capacity = capacity;

    return 0;
}

int vocab_append_bytes(
    VocabForm *vocab_form,
    const void *bytes,
    size_t length,
    int control_flag
) {
    if (vocab_form == NULL || (bytes == NULL && length > 0)) {
        return -1;
    }

    DynamicBuffers *buffer = NULL;

    switch (control_flag) {
        case Engram_Memkey:
            buffer = &vocab_form->parent_morpheme;
            break;

        case Engram_Association:
            buffer = &vocab_form->association;
            break;

        case Engram_Associator:
            buffer = &vocab_form->associator;
            break;

        default:
            return -1;
    }

    if (vocab_ensure_capacity(vocab_form, length, control_flag) != 0) {
        return -1;
    }

    if (length > 0) {
        memcpy(buffer->data + buffer->length, bytes, length);
    }

    buffer->length += length;

    // Keep the buffer usable as a C string.
    buffer->data[buffer->length] = '\0';

    return 0;
}

int vocab_append_string(VocabForm *vocab_form, char *string, int control_flag) {
    return (vocab_append_bytes(vocab_form, string, control_flag));
}