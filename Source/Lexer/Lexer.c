//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"

#include <ctype.h>

#include "../SymbolTable/SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Macros
#define MAX_ASSOC 200
#define MAX_ASSOC_LEN 200
#define ROW 20
#define COLUMN 20


// Ensuring proper capacity for the array before writing
static int ensure_capacity(DynamicBuffers *buf, size_t extra) {
   size_t needed = buf->length + extra;
    if (needed <= buf->capacity) {
        return 0;
    }
    size_t capacity = buf->capacity ? buf->capacity : 16;
    while (needed > capacity) {
        capacity *= 2;
    }
    char *tmp = realloc(buf->data, capacity);
    if (!tmp)
        return -1;

    buf->data = tmp;
    buf->capacity = capacity;
    return 0;
}

// append_bytes is for appending raw bytes from the given input
int append_bytes(DynamicBuffers *buf, const char *byte, size_t x) {
    if (ensure_capacity(buf, x) != 0) {
        return -1; // failure
    }
    memcpy(buf->data + buf->length, byte, x);
    buf->length += x;
    return 0;
}

// This is an interface for passing a string to append bytes
int append_string(DynamicBuffers *buf, const char *string) {
    return (append_bytes(buf, string, strlen(string)));
}

// This is an interface for passing chars to append_bytes
int append_char(DynamicBuffers *buf, char c) {
    return (append_bytes(buf, &c, 1));
}

// This is for loading the nexfile from storage
void *loadNexFile(FILE *fp, MemoryFileLoad *load) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(&load->mainArray, sizeof(load->mainArray), 1, fp);
   ensure_capacity(&load->mainArray, size);
    load->mainArray.data[load->mainArray.length] = '\0';
    free(load->mainArray.data);

}

// This increments wC
char increment(MemoryFileLoad *load, Breakdown *breakdown) {
    char wC;
    breakdown->tracker++;
    ensure_capacity(&load->mainArray, 1);
    load->mainArray.data[load->mainArray.length] = wC;
    free(load->mainArray.data);
    return wC;
}

// Checking wC for debugging
void wCCheck(char wC, char location[30]) {
    printf("wC Check %s: %c\n", location, wC);

}

// The associatons loop
void associations(char wC, MemoryFileLoad *split, Breakdown *breakdown)
{
    // Whenever associations is called initally wC will be on
    // the first association's opening name token
    // bool associationBool = false;
    // bool associatorBool = false;
    // bool nameTokenBool = false;
    bool nameTokenOne = false;
    bool nameTokenTwo = false;


    // int letterCounter = 0;
    // int size;
    // int exportSize;
    // int associatorLetterCounter = 0;
    // int associatiorStartPoint;
    // int associatorEndPoint;
    //int workingAssociatorIdx = 0;
    // char workingAssociations[50];
     int workingAssocationsIdx = 0;
    // int associationsSizes[100];


    bool repeatBool = true;

    printf("Tracker check line 83: %d\n", breakdown->tracker);
    while (repeatBool == true) {
        if (wC) {
            if (nameTokenOne != true)
            {
                nameTokenOne = true;
                wC = increment(split, breakdown); // This puts wC at the first char
                printf("Tracker check 001: %d\n", breakdown->tracker);

            }
            if ((nameTokenOne == true) && (nameTokenTwo == true))
            {
                repeatBool = false;

            }
            nameTokenTwo = true;
            repeatBool = false;
        }
        else
        {
            if (isalpha(wC)) {
                while (isalpha(wC)) {
                    append_char(&breakdown->associations, wC);
                    printf("Tracker check 118: %d\n", breakdown->tracker);
                    wC = increment(split, breakdown);
                    printf("Tracker Check line 120: %d\n", breakdown->tracker);
                    workingAssocationsIdx++;
                }
            }
            if (isalnum(wC))
            {
                append_char(&breakdown->associations, wC);
                printf("Tracker check 126: %d\n", breakdown->tracker);
                wC = increment(split, breakdown);
                printf("Tracker check 128: %d\n", breakdown->tracker);
                wCCheck(wC, "isalnum"); // Should be 1 in test input
                wC = increment(split, breakdown); // Should place wC on nametoken in test input
                workingAssocationsIdx++;
            }
            nameTokenTwo = true;

        }

    } // While loop closing brace
} // End of the associations loop

char setr(MemoryFileLoad *load) {
    char wC;
    append_char(&load->mainArray, wC);
    free(load->mainArray.data);
    return wC;
}

int lenChecker(int val1, int val2) {
    if (val1 == val2) {

    }
    if (val1 != val2) {
        return 1;
    }
    return 0;
}
void associator(char wC, MemoryFileLoad *load, Breakdown *breakdown) {
    bool associatorBool = false;
    int associatorLetterCounter = 0;
    int associatorLen = 0;
    int checkReturn;
    associatorBool = true;
    // This will record the index where the associator token was discovered
    int associatorStartPoint = breakdown->tracker;
    // This will move tracker to the first letter of the associator
    wC = increment(load, breakdown);
    while (associatorBool == true) {
        if (isalpha(wC))
        {
            associatorLetterCounter++;
            append_char(&breakdown->workingAssociators, wC);
            breakdown->tracker++;
            wC = increment(load, breakdown);
        }
        if (isalpha(wC) != true && isalnum(wC)) {
            associatorLetterCounter++;
            append_char(&breakdown->workingAssociators, wC);
            breakdown->tracker++;

            wC = increment(load, breakdown);
        }
        if (isalpha(wC) == false) {
            associatorLen = breakdown->tracker - associatorStartPoint;
            // This is just an outline of a length check and needs expanded
            checkReturn = lenChecker(associatorLetterCounter, associatorLen);
            if (checkReturn == 1) {
                perror("Associator Length Check error");
            }
            associatorBool = false;
        }
    }
}


void load_init(MemoryFileLoad *load) {
    load->mainArray.data = malloc(32);
    if (!load->mainArray.length) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    load->mainArray.length = 0;
    load->mainArray.capacity = 32;
}
void load_free(MemoryFileLoad *load) {
    free(load->mainArray.data);
}
void breakdown_init(Breakdown *brk) {
    brk->associations.length = 0;
    brk->associations.capacity = 0;
    brk->memoryKey.length = 0;
    brk->memoryKey.capacity = 0;
    brk->memoryKey.data = malloc(32);
    brk->associations.data = malloc(64);
    brk->workingAssociators.data = malloc(32);
    if (!brk->memoryKey.data || !brk->associations.data || !brk->workingAssociators.data) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
}
void breakdown_free(Breakdown *brk) {
    free(brk->memoryKey.data);
    free(brk->associations.data);
    free(brk->workingAssociators.data);
}

void crawler(FILE *fp) {
    MemoryFileLoad memoryFileLoad;
    load_init(&memoryFileLoad);
    Breakdown breakdown;
    breakdown_init(&breakdown);
    // Sizes
    char wC;
    bool memoryKeyBool = false;
    bool nameTokenTwo = false;
    bool whileBool = true;

    // loadNexFile loads the working file into memoryFileSplit.mainArray
    loadNexFile(fp, &memoryFileLoad);
    // int len = sizeof(memoryFileLoad.mainArray) / sizeof(memoryFileLoad.mainArray[0]);
    // Here begins the crawling process.
    printf("Crawler Start Reached\n");
    printf("For Loop 01 executed\n");
    // wC[0] = memoryFileSplit.mainArray[tracker]; // wC is our working character.
    wC = setr(&memoryFileLoad); // setr sets wC to mainArray[0]. At this point wC and tracker should both be at 0
    // wC should be { when the next line runs
    wCCheck(wC, "Line 218"); // This should be mainArray[0], so, {
    printf("Tracker Check %d\n", breakdown.tracker);
    // this function increments tracker by one and updates wC to mainArray[1]
    wC = increment(&memoryFileLoad, &breakdown);
    wCCheck(wC, "Line 222"); // Here wC should be at mainArray[1] which should be '
    // Dear god don't leave this uncommented unless we really need it
    /*printf("---Testing Area---\n");
    int s = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);
    for (int i = 0; i < s; i++) {
        printf("Mem Test %d: %c\n", i, memoryFileSplit.mainArray[i]);
        printf("----\n");
    }*/
    // int loopTracker = 0;

    // loopTracker++;
    // printf("Loop tracker: %d\n", loopTracker);
    if (wC == NAMETOKEN) {
        wCCheck(wC, "Just inside NAMETOKEN Loop");
        if (memoryKeyBool == false) {

            // This used to be in an if wC == NAMETOKEN loop but
            // After I added the one above I found it redundant.
            //nameTokenOne = true;
            // printf("wC == nameToken running\n");
            wC = increment(&memoryFileLoad, &breakdown);
            wCCheck(wC, "if memkey == false"); // As of here the wC is correct; it is at the first letter of the first memkey (2)
        }

        // wC should be at [2] which should always be a letter
        wCCheck(wC, "Just before alpha check");
        if (isalpha(wC)) {
            printf("wC == alphas[i] running\n");
            memoryKeyBool = true;
            // wCCheck(wC, "Line 226");
            wC = increment(&memoryFileLoad, &breakdown); // This should increment by one per call [3]
            wCCheck(wC, "First Check inside alphas"); // Should be second char of memkey
            if (isalpha(wC)) {
                breakdown.memoryKey.data[breakdown.memoryKey.length] = wC;
                wC = increment(&memoryFileLoad, &breakdown);
                breakdown.memoryKey.length++;
            }
            // The idea here is that the while loop will run until memkeybool
            // gets flipped and THEN if wC == nameToken runs
            while (memoryKeyBool == true) {
                breakdown.memoryKey.data[breakdown.memoryKey.length] = wC;
                wC = increment(&memoryFileLoad, &breakdown);
                breakdown.memoryKey.length++;
                wCCheck(wC, "while loop check");

                if (isalnum(wC)) {
                    breakdown.memoryKey.data[breakdown.memoryKey.length] = wC;
                    wC = increment(&memoryFileLoad, &breakdown);
                    breakdown.memoryKey.length++;
                }
                if (wC == NAMETOKEN) {
                    wCCheck(wC, "NAMETOKEN two check one");
                    nameTokenTwo = true;
                    // wC is at the first place after the Memkey, whatever index that may be.
                    memoryKeyBool = false;
                }
            }
            if (isalpha(wC) != true && nameTokenTwo == true) {
                wCCheck(wC, "Post NAMETOKEN 2 If one");
                memoryKeyBool = false;
                wC = increment(&memoryFileLoad, &breakdown);
                wCCheck(wC, "Post NAMETOKEN 2 If Two");
                // wC will be at COLON
            }



            printf("Line 271\n");
            if (wC == COLON) {
                wCCheck(wC, "COLON check one");
                wC = increment(&memoryFileLoad, &breakdown); // this should place wC at an open brace
                wCCheck(wC, "COLON Check Two");
            }

            if (wC == OPENBRACE) {
                wCCheck(wC, "OPENBRACE check one");
                wC = increment(&memoryFileLoad, &breakdown);
                wCCheck(wC, "OPENBRACE check two"); // wC here is a nameToken
            }

            // For the first pass of the while loop wC should be a nameToken
            // going in. On the second pass it should be a comma, which means we should NOT increment
            // On the third pass wC should be either a nameToken, an end brace, or an associator
            if (isalpha(wC)) {
                perror("Alpha Fail");
                exit(EXIT_FAILURE);
            }


            while (whileBool == true) {

                wCCheck(wC, "Line 293"); // Should still be a nameToken

                // printf("wC decimal: %d, NAMETOKEN decimal: %d\n", (int)wC, (int)NAMETOKEN);
                if (isalpha(wC) == false) {
                    // wCCheck(wC, "Line 295\n");

                    if (wC == 'NULL') {
                        printf("314");

                        whileBool = false;
                    }
                    else {
                        switch (wC) {
                            case NAMETOKEN:
                                printf("NAMETOKEN CASE HIT: %d\n", (int)wC);
                                printf("Nametoken reached\n");
                                printf("Tracker check pre associations: %d\n", breakdown.tracker);
                                associations(wC, &memoryFileLoad, &breakdown);
                                printf("Tracker check post associations: %d\n", breakdown.tracker);
                                wC = increment(&memoryFileLoad, &breakdown);
                                printf("Tracker Check Line 339: %d\n", breakdown.tracker);
                                wCCheck(wC, "Final NAMETOKEN check"); // At this point wC is returning an open brace
                                break;
                            case ASSOCIATOR:
                                printf("Associator reached");
                                associator(wC, &memoryFileLoad, &breakdown);
                                break;
                            case CLOSEBRACE:
                                printf("310");
                                wC = increment(&memoryFileLoad, &breakdown);
                                break;
                            case COMMA:
                                printf("Line 319");
                                wC = increment(&memoryFileLoad, &breakdown);
                                break;
                            case SEMICOLON:
                                wCCheck(wC, "inside semicolon case");
                                wC = increment(&memoryFileLoad, &breakdown);
                                whileBool = false;
                                break;
                            default:
                                printf("Crawler Default Error");
                                whileBool = false;
                                break;
                        }
                    }
                }
                if (isalpha(wC)) {
                    printf("isalpha true! :o");
                    printf("isalpha true tracker check: %d", breakdown.tracker);
                    exit(1);
                }
            }
        }
        /* The next line is the end of the nametoken loop*/
     }

        // DBs
    /*
        printf("Fallen off of switch, 0\n");
        printf("Main array: %s\n", memoryFileLoad.mainArray);
        printf("Memkey: %s\n", breakdown.memoryKey);
        printf("Associations: %s\n", breakdown.associations);
        printf("Working Associators: %s\n", breakdown.workingAssociators);
        breakdown_free(&breakdown);
        load_free(&memoryFileLoad);
        */

    }


void lRun()
    {   printf("Catalyst Reached\n");
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


