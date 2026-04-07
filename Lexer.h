//
// Created by steviexx on 2/28/26.
//

#ifndef NEXUMNTL_LEXER_H
#define NEXUMNTL_LEXER_H
void lRun();
#define MAX_ASSOC 200
#define MAX_ASSOC_LEN 200
#define ROW 20
#define COLUMN 20
typedef struct {
    char mainArray[2000];
    char splitArray[MAX_ASSOC][MAX_ASSOC_LEN];
} MemoryFileSplit;
typedef struct {} Add;
typedef struct {
    char memoryKey[200];
    int assocationCount;
    char associations[200];
    char workingAssociators[200];
    int tracker;
} Breakdown;
#endif //NEXUMNTL_LEXER_H