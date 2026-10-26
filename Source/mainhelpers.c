//
// Created by steviexx on 10/25/26.
//
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mainhelpers.h"

#include "main.h"
#include "Parser/parserhelpers.h"
#include "SourceGenerator/SourceGenerator.h"

FILE* file_handler(InputForm *form, int control) {
    switch (control) {
        case 0: {  // INPUT - Scan and open first matching .nexc file
            FileList files = {NULL, 0};
            DIR *dir = NULL;
            int found_any = 0;
            // Scan directory for .nexc files
            int scan_result = scan_directory("./data/Export", ".nexc", &files);

            if (scan_result == -1) {
                fprintf(stderr, "[create_file] Failed to scan input directory\n");
                return NULL;
            }
            if (scan_result == 0) {
                fprintf(stderr, "[create_file] No .nexc files found in ./data/Export\n");
                return NULL;
            }
            found_any = 1;
            // Try opening each candidate until one succeeds
            FILE *in_file = NULL;
            char filepath[PATH_MAX];
            for (int i = 0; i < files.count && in_file == NULL; i++) {
                snprintf(filepath, sizeof(filepath), "./data/Export/%s",
                        files.entries[i]);
                in_file = fopen(filepath, "r");
                if (in_file == NULL) {
                    fprintf(stderr, "[create_file] Failed to open: %s\n", filepath);
                    // Continue to next candidate
                } else {
                    fprintf(stdout, "[create_file] Opened: %s\n", filepath);
                }
            }

            // Cleanup file list (but NOT the FILE*)
            free_file_list(&files);
            if (in_file == NULL) {
                fprintf(stderr, "[create_file] All candidate files failed to open\n");
                return NULL;
            }
            // Caller owns the returned FILE* - caller must fclose() it
            return in_file;
        }
        case 1:
            FILE *out_file = fopen(form->output_filename.data, "w+");
            return out_file;
            break;
        default:
            return NULL;
    }
}

int scan_directory(const char *dir_path, const char *extension, FileList *list)
{
    // Input validation
    if (dir_path == NULL || extension == NULL || list == NULL) {
        fprintf(stderr, "scan_directory: null argument\n");
        return -1;
    }

    // Prevents leaks if opendir() fails
    list->entries = NULL;
    list->count = 0;
    int capacity = 0;

    // OPEN DIRECTORY
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror(dir_path);  // Shows the actual path that failed
        return -1;
    }

    // SCAN LOOP
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip . and ..
        if (entry->d_name[0] == '.') {
            if (entry->d_name[1] == '\0' || entry->d_name[1] == '.')
                continue;
        }

        // Extension filter
        size_t len = strlen(entry->d_name);
        size_t ext_len = strlen(extension);

        if (ext_len > 0 && len <= ext_len)
            continue;

        if (strcmp(entry->d_name + len - ext_len, extension) != 0)
            continue;

        // GROW ARRAY SAFELY
        if (list->count >= capacity) {
            int new_cap = (capacity == 0) ? 8 : capacity * 2;

            char **tmp = realloc(list->entries,
                                new_cap * sizeof(char *));
            if (tmp == NULL) {
                // CLEANUP ON FAILURE
                for (int i = 0; i < list->count; i++) {
                    free(list->entries[i]);
                }
                free(list->entries);
                closedir(dir);
                return -1;
            }

            list->entries = tmp;
            capacity = new_cap;
        }

        // COPY ENTRY NAME
        char *copy = strdup(entry->d_name);
        if (copy == NULL) {
            // CLEANUP ON FAILURE
            for (int i = 0; i < list->count; i++) {
                free(list->entries[i]);
            }
            free(list->entries);
            closedir(dir);
            return -1;
        }

        list->entries[list->count++] = copy;
    }

    // SUCCESS
    closedir(dir);
    return list->count;
}

void free_file_list(FileList *list)
{
    if (list == NULL || list->entries == NULL)
        return;

    for (int i = 0; i < list->count; i++) {
        free(list->entries[i]);
    }
    free(list->entries);

    list->entries = NULL;
    list->count = 0;
}
int set_filepath(InputForm *form, int source)

{
    const char *prefix;
    const char *name;
    size_t name_len;

    switch (source) {
        case OUTPUT_OPT:
            prefix   = "./data/Output_Files/";
            name     = form->output_filename.data;
            name_len = form->output_filename.length;
            break;

        case INPUT_OPT:
            prefix   = "./data/Input_Files";
            name     = form->input_filename.data;
            name_len = form->input_filename.length;
            break;

        default:
            fprintf(stderr, "set_filepath: invalid source %d\n", source);
            return -1;
    }

    if (name == NULL) {
        fprintf(stderr, "set_filepath: filename is NULL\n");
        return -1;
    }

    const size_t prefix_len = strlen(prefix);

    if (prefix_len + name_len >= PATH_MAX) {
        fprintf(stderr, "set_filepath: path too long (%zu + %zu >= %d)\n",
                prefix_len, name_len, PATH_MAX);
    }

    char path[PATH_MAX];

    memcpy(path, prefix, prefix_len);
    memcpy(path + prefix_len, name, name_len);
    path[prefix_len + name_len] = '\0';
    switch (source) {
        case OUTPUT_OPT:
            in_append_string(form, path, prefix_len + name_len, 8);
            return 1;
            break;
        case INPUT_OPT:
            in_append_string(form, path, prefix_len + name_len, 9);
            return 1;
            break;
        default:
            return -1;
            break;
    }
}

static int get_filename(InputForm *form,int output, int opt) {
    int set_filepath_return;
    // NAME_MAX - 4 is to allow as much room as possible without stepping on the extension,
    // with the longest possible extension being .nexc
    static char unfinished_filename[NAME_MAX - 4];
    size_t unfinished_size;
    // +4 to get us back up to NAME_MAX
    static char finished_filename[sizeof(unfinished_filename) + 4];
    size_t finished_size = sizeof(finished_filename);
    size_t filepath_size;
    size_t filename_size;
    printf("Enter file name, without extension: ");
    scanf("%s", unfinished_filename);
    // filename_size = sizeof(unfinished_filename);
    char filepath[PATH_MAX + filename_size];
    const char *extension = (output == NEX) ? ".nex" : ".nexc";
    strcat(unfinished_filename, extension);
    unfinished_size = sizeof(unfinished_filename);
    strncat(finished_filename, unfinished_filename, finished_size);
    finished_filename[sizeof(finished_filename) - 1] = '\0';
    // sets output filename in form as finished_filename
    in_append_string(form, finished_filename, sizeof(finished_filename) - 1, opt);
    set_filepath_return = set_filepath(form, opt);
    if (set_filepath_return > 0) {
        return 1;
    }
    if (set_filepath_return < 0) {
        return -1;
    }

}
static int read_choice(const char *prompt, int lo, int hi) {
    int value;
    for (;;) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= lo && value <= hi) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            return value;
        }
        fprintf(stderr, "Invalid input — enter %d or %d.\n", lo, hi);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
    }
}


void in_file_to_nexc_cleanup(FILE* in_file, Export *export_form, InputForm *form) {
    // in_file cleanup
    fclose(in_file);
    // form cleanup
    input_free(form);
    // export_form cleanup
    export_form_free(export_form);
}

void main_general_cleanup()
