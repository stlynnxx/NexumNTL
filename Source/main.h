//
// Created by steviexx on 2/28/26.
//

#ifndef MAIN_H
#define MAIN_H
// replacement for nex_code_flag
typedef enum {
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
    FILE_IN = 1
} InType;

#endif //MAIN_H