//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"

#include <ctype.h>

#include "SymbolTable.h"
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
} Breakdown;


int tracker = 0;


void *loadNexFile(FILE *fp, MemoryFileSplit *split) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(split->mainArray, sizeof(split->mainArray), 1, fp);
   split->mainArray[size] = '\0';

}

char increment(MemoryFileSplit *split, int *tracker) {
    char wC;
    (*tracker)++;
    wC = split->mainArray[*tracker];
    return wC;
}



void associations(char wC, MemoryFileSplit *split, Breakdown *breakdown, int *tracker)
{
    // Whenever associations is called initally wC will be on
    // the first association's opening name token
    bool associationBool = false;
    bool associatorBool = false;
    bool nameTokenBool = false;
    bool nameTokenOne = false;
    bool nameTokenTwo = false;

    int letterCounter = 0;
    int size;
    int exportSize;
    int associatorLetterCounter = 0;
    int associatiorStartPoint;
    int associatorEndPoint;
    int workingAssociatorIdx = 0;
    char workingAssociations[50];
    int workingAssocationsIdx = 0;
    int associationsSizes[100];

    char export[250];
    bool repeatBool = true;
    wC = wC;
    while (repeatBool == true) {
        switch (wC)
        {
            case NAMETOKEN:

                if (nameTokenOne != true) {
                    nameTokenOne = true;
                    wC = increment(split, tracker); // This puts wC at the first char
                    break;
                }

                if ((nameTokenOne == true) && (nameTokenTwo == true)) {
                    repeatBool = false;
                    break;
                }
                nameTokenTwo = true;
                repeatBool = false;
                break;


            case COMMA:
                *tracker = *tracker + associatorLetterCounter + 1;

                wC = split->mainArray[*tracker];
                split->mainArray[*tracker] = wC;
                break;

            default:
                if (isalpha(wC) == true) {
                    while (isalpha(wC) == true) {


                        breakdown->associations[workingAssocationsIdx] = wC;
                        wC = increment(split, tracker);
                        workingAssocationsIdx++;
                    }
                }
                nameTokenTwo = true;
                repeatBool = false;



                break;
        } // End of switch
        /*printf("associations loop bottom: wC=%c (%d), repeatBool=%d\n", wC, (int)wC, repeatBool);
        if ((isalpha(wC) == false) && (wC != NAMETOKEN) && (wC != ASSOCIATOR)) {
            repeatBool = false;
        }*/
    } // While loop closing brace
} // End of the associations loop

char setr(MemoryFileSplit *split) {
    char wC;
    wC = split->mainArray[0];
    return wC;
}

void wCCheck(char wC, char location[30]) {
    printf("wC Check %s: %c\n", location, wC);

}
void associator(char wC,int *tracker, MemoryFileSplit *split, Breakdown *breakdown) {
    bool associatorBool = false;
    int associatorLetterCounter = 0;
    int associatorStartPoint = 0;
    int workingAssociatorIdx = 0;


    associatorBool = true;
    // This will record the index where the associator token was discovered
    associatorStartPoint = *tracker;
    // This will move tracker to the first letter of the associator
    wC = increment(split, tracker);

    while (associatorBool == true) {
        if (isalpha(wC) == true)
        {
            associatorLetterCounter++;
            breakdown->workingAssociators[workingAssociatorIdx] = wC;

            workingAssociatorIdx++;
            (*tracker)++;
            wC = increment(split, tracker);
        }
        if (isalpha(wC) == false) {
            associatorBool = false;
        }
    }
}
void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    Breakdown breakdown;
    char associationsReturn[2000];
    char workingCheck[5];
    char wC;
    char workingMemKeys[200];
    bool memoryKeyBool = false;
    bool assocationBool = false;

    int nameTokenPoint = 0;
    bool nameTokenOne = false;
    bool nameTokenTwo = false;
    int letterCounter = 0;
    int endLinePoint = 0;

    // loadNexFile loads the working file into memoryFileSplit.mainArray
    loadNexFile(fp, &memoryFileSplit);
    int len = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);

    // Here begins the crawling process.
    printf("Crawler Start Reached\n");


    printf("For Loop 01 executed\n");
    // wC[0] = memoryFileSplit.mainArray[tracker]; // wC is our working character.
    wC = setr(&memoryFileSplit); // setr sets wC to mainArray[0]. At this point wC and tracker should both be at 0
    // wC should be { when the next line runs
    wCCheck(wC, "Line 190"); // This should be mainArray[0], so, {
    printf("Tracker Check %d\n", tracker);
    // this function increments tracker by one and updates wC to mainArray[1]
    wC = increment(&memoryFileSplit, &tracker);
    wCCheck(wC, "Line 194"); // Here wC should be at mainArray[1] which should be '
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
        if (wC == NAMETOKEN || isalpha(wC) == true) {
            if (isalpha(wC) != true || memoryKeyBool == false) {

                // This used to be in an if wC == NAMETOKEN loop but
                // After I added the one above I found it redundant.
                nameTokenOne = true;
                // printf("wC == nameToken running\n");
                wC = increment(&memoryFileSplit, &tracker);
                wCCheck(wC, "Line 214"); // As of here the wC is correct; it is at the first letter of the first memkey
            }
            if (isalpha(wC) != true && memoryKeyBool == true) {
                memoryKeyBool = false;
                wC = increment(&memoryFileSplit, &tracker);
            }


                // wC should be at [2] which should always be a letter
                if (isalpha(wC)) {
                    printf("wC == alphas[i] running\n");
                    memoryKeyBool = true;
                    // wCCheck(wC, "Line 226");
                    wC = increment(&memoryFileSplit, &tracker); // This should increment by one per call
                    wCCheck(wC, "Line 249"); // Should be second char of memkey
                    // The idea here is that the while loop will run until memkeybool
                    // gets flipped and THEN if wC == nameToken runs
                    while (memoryKeyBool == true) {
                        int wmcIdx = 0;
                        printf("memkeybool == true loop running\n");
                        workingMemKeys[wmcIdx] = wC;
                        // wCCheck(wC, "Line 231");
                        wC = increment(&memoryFileSplit, &tracker);
                        wmcIdx++;
                        wCCheck(wC, "Line 259");
                        if (wC == NAMETOKEN) {
                            memoryKeyBool = false;
                        }
                    }

                    if (wC == NAMETOKEN && nameTokenOne == true) {
                        nameTokenTwo = true;
                        printf("Line 267 reached");
                        wC = increment(&memoryFileSplit, &tracker);
                        wCCheck(wC, "Line 247"); // this should put wC at a colon
                    }
                    bool colonCheckOne = false;
                    bool spaceCheck = false;
                    bool openBraceToken = false;
                    if (wC == COLON) {
                        colonCheckOne = true;
                        wC = increment(&memoryFileSplit, &tracker); // this should place wC at a space
                        wCCheck(wC, "Line 277");
                    }
                    /*if (wC == SPACE) {
                        spaceCheck = true;
                        wC = increment(&memoryFileSplit);
                        wCCheck(wC, "Line 260");
                    }*/
                    if (wC == OPENBRACE) {
                        openBraceToken = true;
                        wC = increment(&memoryFileSplit, &tracker);
                        wCCheck(wC, "Line 287"); // wC here is a nameToken
                    }


                    // I intend to move these to the top of the function eventually
                    bool whileBool = true;
                    bool incrementOrNah = false;
                    bool commaCheck = false;
                    bool associatorCheck = false;

                    // For the first pass of the while loop wC should be a nameToken
                    // going in. On the second pass it should be a comma, which means we should NOT increment
                    // On the third pass wC should be either a nameToken, an end brace, or an associator

                    while (whileBool == true) {

                        wCCheck(wC, "Line 292"); // Should still be a nameToken
                        // printf("wC decimal: %d, NAMETOKEN decimal: %d\n", (int)wC, (int)NAMETOKEN);
                        if (isalpha(wC) == false) {
                            wCCheck(wC, "Line 295\n");
                            switch (wC) {
                                case NAMETOKEN:
                                    printf("NAMETOKEN CASE HIT: %d\n", (int)wC);
                                    printf("Nametoken reached");
                                    associations(wC, &memoryFileSplit, &breakdown, &tracker);
                                    wC = increment(&memoryFileSplit, &tracker);
                                    printf("After associations, wC: %c (%d)\n", wC, (int)wC);
                                    break;
                                case ASSOCIATOR:
                                    printf("Associator reached");
                                    associator(wC, &tracker, &memoryFileSplit, &breakdown);

                                    break;
                                case CLOSEBRACE:
                                    printf("310");
                                    wC = increment(&memoryFileSplit, &tracker);
                                    break;
                                case ENDOFFILE:
                                    printf("314");
                                    endLinePoint = tracker;
                                    whileBool = false;
                                    break;
                                case COMMA:
                                    printf("Line 319");
                                    wC = increment(&memoryFileSplit, &tracker);
                                    commaCheck = true;
                                    break;
                                default:
                                    printf("Crawler Default Error");
                                    whileBool = false;
                                    break;
                            }

                        }
                    }
                }

        }// This is the end of the nametoken if loop

        printf("Fallen off of switch, 0");
        // printf("%s\n", associationsReturn);
        // printf("%s\n", workingMemKeys);


    }


void catalyst()
    {   printf("Catalyst Reached\n");
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


