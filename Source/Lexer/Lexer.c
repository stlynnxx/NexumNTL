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



// This is for loading the nexfile from storage
int loadNexFile(FILE *fp, MemoryFileLoad *load) {
    int returned;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(&load->mainArray, sizeof(load->mainArray), 1, fp);
   returned = ensure_capacity(&load->mainArray, size);
    if (returned == -1) {
        return -1;
    }
   load->mainArray.data[load->mainArray.length] = '\0';
   free(load->mainArray.data);
    return 1;
}

// This increments wC
/*char increment(MemoryFileLoad *load, Breakdown *breakdown) {
    char wC;
    breakdown->tracker++;

    append_char()
    ensure_capacity(&load->mainArray, 1);
    load->mainArray.data[load->mainArray.length] = wC;

    free(load->mainArray.data);
    return wC;
}*/

// Checking wC for debugging
void wCCheck(char wC, char location[30]) {
    printf("wC Check %s: %c\n", location, wC);
}
char setr(MemoryFileLoad *load, char wC, int index) {
    wC = load->mainArray.data[index];
    /*append_char(&load->mainArray, wC);
    free(load->mainArray.data);*/
    return wC;
}
// The associatons loop
void associations(char wC, MemoryFileLoad *split, Organizer *organizer,int incrementIdx)
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

    printf("Tracker check line 83: %d\n", organizer->tracker);
    while (repeatBool == true) {
        if (wC) {
            if (nameTokenOne != true)
            {
                nameTokenOne = true;
                incrementIdx++;
                wC = setr(split,wC, incrementIdx);
                printf("Tracker check 001: %d\n", organizer->tracker);

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
                    append_char(&organizer->associations, wC);
                    printf("Tracker check 118: %d\n", organizer->tracker);
                    incrementIdx++;
                    wC = setr(split,wC, incrementIdx);
                    printf("Tracker Check line 120: %d\n", organizer->tracker);
                    workingAssocationsIdx++;
                }
            }
            if (isalnum(wC))
            {
                append_char(&organizer->associations, wC);
                printf("Tracker check 126: %d\n", organizer->tracker);
                incrementIdx++;
                wC = setr(split,wC, incrementIdx);
                printf("Tracker check 128: %d\n", organizer->tracker);
                // wCCheck(wC, "isalnum"); // Should be 1 in test input
                incrementIdx++;
                wC = setr(split,wC, incrementIdx); // Should place wC on nametoken in test input
                workingAssocationsIdx++;
            }
            nameTokenTwo = true;

        }

    } // While loop closing brace
} // End of the associations loop



int lenChecker(int val1, int val2) {
    if (val1 == val2) {

    }
    if (val1 != val2) {
        return 1;
    }
    return 0;
}
void associator(char wC, MemoryFileLoad *load, Organizer *organizer, int incrementIdx) {
    bool associatorBool = false;
    int associatorLetterCounter = 0;
    int associatorLen = 0;
    int checkReturn;
    associatorBool = true;
    // This will record the index where the associator token was discovered
    int associatorStartPoint = organizer->tracker;
    // This will move tracker to the first letter of the associator
    incrementIdx++;
    wC = setr(load,wC, incrementIdx);
    while (associatorBool == true) {
        if (isalpha(wC))
        {
            associatorLetterCounter++;
            append_char(&organizer->workingAssociators, wC);
            organizer->tracker++;
            incrementIdx++;
            wC = setr(load,wC, incrementIdx);
        }
        if (isalpha(wC) != true && isalnum(wC)) {
            associatorLetterCounter++;
            append_char(&organizer->workingAssociators, wC);
            organizer->tracker++;

            incrementIdx++;
            wC = setr(load,wC, incrementIdx);
        }
        if (isalpha(wC) == false) {
            associatorLen = organizer->tracker - associatorStartPoint;
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
Organizer* breakdown_init() {
    Organizer *brk = malloc(sizeof(Organizer));
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
    return brk;
}
void breakdown_free(Organizer *brk) {
    free(brk->memoryKey.data);
    free(brk->associations.data);
    free(brk->workingAssociators.data);
}

void crawler(FILE *fp) {
    MemoryFileLoad *memoryFileLoad;
    load_init(memoryFileLoad);
    Organizer *breakdown;
    breakdown_init(breakdown);
    // Sizes
    char wC;
    bool memoryKeyBool = false;
    bool nameTokenTwo = false;
    bool whileBool = true;
    int loadFileReturn;
    int incrementIdx = 0;
    // loadNexFile loads the working file into memoryFileSplit.mainArray
    loadFileReturn = loadNexFile(fp, memoryFileLoad);
    if (loadFileReturn == -1) {
        perror("loadNexFile error");
        exit(EXIT_FAILURE);
    }
    // Here begins the crawling process.
    printf("Crawler Start Reached\n");
    printf("For Loop 01 executed\n");
    // wC[0] = memoryFileSplit.mainArray[tracker]; // wC is our working character.
    wC = setr(memoryFileLoad,wC, incrementIdx); // setr sets wC to mainArray[0]. At this point wC and tracker should both be at 0
    // wC should be { when the next line runs
    wCCheck(wC, "Line 278"); // This should be mainArray[0], so, {
    // this function increments tracker by one and updates wC to mainArray[1]
    incrementIdx++;
    wC = setr(memoryFileLoad,wC, incrementIdx);
    wCCheck(wC, "Line 282"); // Here wC should be at mainArray[1] which should be '
    if (wC == NAMETOKEN) {
        wCCheck(wC, "Just inside NAMETOKEN Loop");
        if (memoryKeyBool == false) {
            incrementIdx++;
            wC = setr(memoryFileLoad,wC, incrementIdx);
            wCCheck(wC, "if memkey == false"); // As of here the wC is correct; it is at the first letter of the first memkey (2)
        }

        // wC should be at [2] which should always be a letter
        wCCheck(wC, "Just before alpha check");
        if (isalpha(wC)) {
            printf("wC == alphas[i] running\n");
            memoryKeyBool = true;
            // wCCheck(wC, "Line 226");
            incrementIdx++;
            wC = setr(memoryFileLoad,wC, incrementIdx);
            wCCheck(wC, "First Check inside alphas"); // Should be second char of memkey
            if (isalpha(wC)) {
                breakdown->memoryKey.data[breakdown->memoryKey.length] = wC;
                incrementIdx++;
                wC = setr(memoryFileLoad,wC, incrementIdx);
                breakdown->memoryKey.length++;
            }
            // The idea here is that the while loop will run until memkeybool
            // gets flipped and THEN if wC == nameToken runs
            while (memoryKeyBool == true) {
                breakdown->memoryKey.data[breakdown->memoryKey.length] = wC;
                incrementIdx++;
                wC = setr(memoryFileLoad,wC, incrementIdx);
                breakdown->memoryKey.length++;
                wCCheck(wC, "while loop check");

                if (isalnum(wC)) {
                    breakdown->memoryKey.data[breakdown->memoryKey.length] = wC;
                    incrementIdx++;
                    wC = setr(memoryFileLoad,wC, incrementIdx);
                    breakdown->memoryKey.length++;
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
                incrementIdx++;
                wC = setr(memoryFileLoad,wC, incrementIdx);
                wCCheck(wC, "Post NAMETOKEN 2 If Two");
                // wC will be at COLON
            }



            printf("Line 271\n");
            if (wC == COLON) {
                wCCheck(wC, "COLON check one");
                incrementIdx++;
                wC = setr(memoryFileLoad,wC, incrementIdx);
                wCCheck(wC, "COLON Check Two");
            }

            if (wC == OPENBRACE) {
                wCCheck(wC, "OPENBRACE check one");
                incrementIdx++;
                wC = setr(memoryFileLoad,wC, incrementIdx);
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

                    if (wC == 0) {
                        printf("314");

                        whileBool = false;
                    }
                    else {
                        switch (wC) {
                            case NAMETOKEN:
                                printf("NAMETOKEN CASE HIT: %d\n", (int)wC);
                                printf("Nametoken reached\n");
                                printf("Tracker check pre associations: %d\n", breakdown->tracker);
                                associations(wC,memoryFileLoad, breakdown, incrementIdx);
                                printf("Tracker check post associations: %d\n", breakdown->tracker);
                                incrementIdx++;
                                wC = setr(memoryFileLoad,wC, incrementIdx);
                                printf("Tracker Check Line 339: %d\n", breakdown->tracker);
                                wCCheck(wC, "Final NAMETOKEN check"); // At this point wC is returning an open brace
                                break;
                            case ASSOCIATOR:
                                printf("Associator reached");
                                associator(wC, memoryFileLoad, breakdown, incrementIdx);
                                break;
                            case CLOSEBRACE:
                                printf("310");
                                incrementIdx++;
                                wC = setr(memoryFileLoad,wC, incrementIdx);
                                break;
                            case COMMA:
                                printf("Line 319");
                                incrementIdx++;
                                wC = setr(memoryFileLoad,wC, incrementIdx);
                                break;
                            case SEMICOLON:
                                wCCheck(wC, "inside semicolon case");
                                incrementIdx++;
                                wC = setr(memoryFileLoad,wC, incrementIdx);
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
                    printf("isalpha true tracker check: %d", breakdown->tracker);
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
    {
        printf("Catalyst Reached\n");
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


