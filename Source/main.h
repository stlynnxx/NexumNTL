//
// Created by steviexx on 2/28/26.
//

#ifndef MAIN_H
#define MAIN_H
// replacement for nex_code_flag
typedef enum {
    AGENT_OPT = 0,
    HUMAN_OPT = 1,
    RAW_MORP = 2,
    AGENT_FILE = 3,
    OUTPUT_OPT = 6,
    INPUT_OPT = 7,
} Options;

typedef enum {
    NEX = 0,
    NEXC = 1
} OutType;

extern OutType outType;
typedef enum {
    TERMINAL_IN = 0,
    FILE_IN = 1,
    AGENT = 2
} InType;

#endif //MAIN_H