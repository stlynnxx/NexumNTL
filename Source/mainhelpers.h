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

typedef enum {
    Engram_Memkey = 0,
    Engram_Associator = 1,
    Engram_Association = 2
} EngramAppendFlag;

inline Engram* engram_helpers(EngramStore *store);
inline void engram_append(const char *string, Engram *engram, int engram_append_flag);
inline EngramID engram_create(EngramStore *store);
inline Engram *engram_get(EngramStore *store, EngramID id);
inline void engram_store_free(EngramStore *store);
inline EngramStore *engram_store_init(void);
inline int scan_directory(const char *dir_path, const char *extension, FileList *list);
inline void free_file_list(FileList *list);
static int get_filename(InputForm *form,int output, int opt);
static int read_choice(const char *prompt, int lo, int hi);
inline int set_filepath(InputForm *form, int source);
inline FILE* file_handler(InputForm *form, int control);
inline void in_file_to_nexc_cleanup(FILE* in_file, Export *export_form, InputForm *form);
#endif //NEXUMNTL_MAINHELPERS_H
