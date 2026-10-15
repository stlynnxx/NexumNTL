//
// Created by steviexx on 9/27/26.
//
#include "../SymbolTable/SymbolTable.h"
#include "compressorhelpers.h"
#include "../Parser/parserhelpers.h"
#include "../Parser/Parser.h"
#include "../SourceGenerator/SGruninterface.h"
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
    in->buffer.data = malloc(32);
    in->terminalInput.data = malloc(32);
    if (!in->buffer.capacity || !in->buffer.data || !in->buffer.length || !in->terminalInput.capacity || !in->terminalInput.data || !in->terminalInput.length) {
        perror("in_init error");
        exit(-1);
    }
    return in;
}*/

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

long comp_get_file_size(FILE *in_file) {
    fseek(in_file, 0, SEEK_END);
    long size = ftell(in_file);
    fseek(in_file, 0, SEEK_SET); // Reset pointer
    return size;
}

void line_parse(ParserBuffers *pbuffers, InputForm *in, FILE* export_file) {
    int control;
    char *workingChar;
    int open_brace_check = 0;
    int open_brace_check_two = 0;
    int semicolon_check = 0;
    int associator_check = 0;
    int name_token_one_check = 0;
    int name_token_two_check = 0;
    int comma_check = 0;
    int close_brace_check = 0;

    for (int i = 0; i < pbuffers->line.length; i++)
    {
        *workingChar = pbuffers->line.data[i];

        switch (*workingChar) {
            case OPENBRACE:
                open_brace_check = 1;
                control = 0;
                if (semicolon_check == 1 && open_brace_check == 1) {
                    open_brace_check_two = 1;
                    control = 1;
                }
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
            case NAMETOKEN:
                if (name_token_one_check && name_token_two_check == 0 && open_brace_check == 1) {
                    name_token_one_check = 1;
                    control = 0;
                }
                if (name_token_one_check == 1 && name_token_two_check == 0 && open_brace_check == 1) {
                    name_token_two_check = 1;
                    control = 0;
                }
                if (name_token_one_check == 1 && name_token_two_check == 1 && semicolon_check == 1) {
                    name_token_two_check = 0;
                    control = 1;
                }
                if (comma_check == 1 && associator_check == 1) {
                    associator_check = 0;
                    control = 1;
                }
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
            case ASSOCIATOR:
                associator_check = 1;
                if (associator_check == 1) {
                    control = 2;
                }
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
            case SEMICOLON:
                semicolon_check = 1;
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
            case COMMA:
                if (name_token_one_check && name_token_two_check == 1 && open_brace_check_two == 1) {
                    comma_check = 1;
                }
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
            case CLOSEBRACE:
                close_brace_check = 1;
                in_append_bytes(in, workingChar, sizeof(*workingChar), control);
                break;
                // default will handle alphanumerics
            default:
                if isalnum(workingChar) {
                in_append_string(in,workingChar,sizeof(workingChar),control);
            }
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

void append_file_to_buffers(FILE* in_file, ParserBuffers *pbuffers, InputForm *in, size_t file_size)
    {
    FILE* export_file;
    for (int i = 0; i <= file_size; i++) {
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
        line_parse(pbuffers, in, export_file);
        pbuffer_line_clear(pbuffers);

        // fclose(in_file);
        // free(in_file);
    }

}


int comp_open_file(FILE* in_file, ParserBuffers *pbuffers, int nex_code_flag) {
    if (!in_file) {
        perror("comp_open_file error");
        return -1;
    }
    // Getting the size of inFile
    size_t file_size = comp_get_file_size(in_file);
    // Append to pbuffer appropriately
    InputForm *in = input_init();
    append_file_to_buffers(in_file, pbuffers, in, file_size);
    match(in,nex_code_flag,pbuffers);
    input_free(in);
    // The last two flags in this sgRun call need reviewed
    sgRun(pbuffers->out_filename.data,nex_code_flag, 0,0);
}

int comp_from_file_append_bytes(ParserBuffers *pbuffers, FILE* in_file, int nex_code_flag) {
    //  We are appending the file to pbuffers
    int cofr;
    cofr = comp_open_file(in_file, pbuffers, nex_code_flag);
    if (cofr == -1) {
        exit(-1);
    }
    return 1;
}
// append_bytes is for appending raw bytes from the given input
int comp_append_bytes(Unencoded *unencoded, Input *in) {
    size_t x = in->terminalInput.length;
    if (comp_ensure_capacity(in, x) != 0) {
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
