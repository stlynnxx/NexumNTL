//
// Created by steviexx on 10/25/26.
//

#ifndef NEXUMNTL_MAINHELPERS_H
#define NEXUMNTL_MAINHELPERS_H
#include "SourceGenerator/SourceGenerator.h"

typedef struct {
    char **entries;
    int count;
} FileList;

inline int scan_directory(const char *dir_path, const char *extension, FileList *list);
inline void free_file_list(FileList *list);
static int get_filename(InputForm *form,int output, int opt);
static int read_choice(const char *prompt, int lo, int hi);
inline int set_filepath(InputForm *form, int source);
inline FILE* file_handler(InputForm *form, int control);
inline void in_file_to_nexc_cleanup(FILE* in_file, Export *export_form, InputForm *form);
#endif //NEXUMNTL_MAINHELPERS_H
