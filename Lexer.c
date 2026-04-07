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


/*
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
*/


void *loadNexFile(FILE *fp, MemoryFileSplit *split) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(split->mainArray, sizeof(split->mainArray), 1, fp);
   split->mainArray[size] = '\0';

}

char increment(MemoryFileSplit *split, Breakdown *breakdown) {
    char wC;
    breakdown->tracker++;
    wC = split->mainArray[breakdown->tracker];
    return wC;
}

void wCCheck(char wC, char location[30]) {
    printf("wC Check %s: %c\n", location, wC);

}

void associations(char wC, MemoryFileSplit *split, Breakdown *breakdown)
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


    bool repeatBool = true;
    bool commaBool = false;
    printf("Tracker check line 83: %d\n", breakdown->tracker);
    while (repeatBool == true) {
        switch (wC)
        {
            case NAMETOKEN:

                if (nameTokenOne != true) {
                    nameTokenOne = true;
                    wC = increment(split, breakdown); // This puts wC at the first char
                    printf("Tracker check 001: %d\n", breakdown->tracker);
                    break;
                }


                if ((nameTokenOne == true) && (nameTokenTwo == true)) {
                    repeatBool = false;
                    break;
                }
                nameTokenTwo = true;
                repeatBool = false;
                break;
            default:
                if (isalpha(wC)) {
                    while (isalpha(wC)) {


                        breakdown->associations[workingAssocationsIdx] = wC;
                        printf("Tracker check 118: %d\n", breakdown->tracker);
                        wC = increment(split, breakdown);
                        printf("Tracker Check line 120: %d\n", breakdown->tracker);
                        workingAssocationsIdx++;
                    }
                }
                if (isalnum(wC)) {
                    breakdown->associations[workingAssociatorIdx] = wC;
                    printf("Tracker check 126: %d\n", breakdown->tracker);
                    wC = increment(split, breakdown);
                    printf("Tracker check 128: %d\n", breakdown->tracker);
                    wCCheck(wC, "isalnum"); // Should be 1 in test input
                    wC = increment(split, breakdown); // Should place wC on nametoken in test input
                    workingAssocationsIdx++;
                }
                nameTokenTwo = true;
                break;
        } // End of switch

    } // While loop closing brace
} // End of the associations loop

char setr(MemoryFileSplit *split) {
    char wC;
    wC = split->mainArray[0];
    return wC;
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
    wC = increment(split, breakdown);

    while (associatorBool == true) {
        if (isalpha(wC))
        {
            associatorLetterCounter++;
            breakdown->workingAssociators[workingAssociatorIdx] = wC;

            workingAssociatorIdx++;
            (*tracker)++;
            wC = increment(split, breakdown);
        }
        if (isalpha(wC) != true && isalnum(wC)) {
            associatorLetterCounter++;
            breakdown->workingAssociators[workingAssociatorIdx] = wC;

            workingAssociatorIdx++;
            (*tracker)++;
            wC = increment(split, breakdown);

        }
        if (isalpha(wC) == false) {
            associatorBool = false;
        }
    }
}
void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    Breakdown breakdown;

    int tracker = 0;
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

    bool colonCheckOne = false;
    bool spaceCheck = false;
    bool openBraceToken = false;
    bool whileBool = true;
    bool incrementOrNah = false;
    bool commaCheck = false;
    bool associatorCheck = false;


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
    wC = increment(&memoryFileSplit, &breakdown);
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
    if (wC == NAMETOKEN) {
        wCCheck(wC, "Just inside NAMETOKEN Loop");
        if (memoryKeyBool == false) {

            // This used to be in an if wC == NAMETOKEN loop but
            // After I added the one above I found it redundant.
            nameTokenOne = true;
            // printf("wC == nameToken running\n");
            wC = increment(&memoryFileSplit, &breakdown);
            wCCheck(wC, "if memkey == false"); // As of here the wC is correct; it is at the first letter of the first memkey (2)
        }

        // wC should be at [2] which should always be a letter
        wCCheck(wC, "Just before alpha check");
        if (isalpha(wC)) {
            printf("wC == alphas[i] running\n");
            memoryKeyBool = true;
            // wCCheck(wC, "Line 226");
            wC = increment(&memoryFileSplit, &breakdown); // This should increment by one per call [3]
            wCCheck(wC, "First Check inside alphas"); // Should be second char of memkey
            if (isalpha(wC)) {
                breakdown.memoryKey[0] = wC;
            }
            // The idea here is that the while loop will run until memkeybool
            // gets flipped and THEN if wC == nameToken runs
            while (memoryKeyBool == true) {
                int wmcIdx = 1;
                printf("memkeybool == true loop running\n");
                // This needs to be updated so it appends to Breakdown instead
                breakdown.memoryKey[wmcIdx] = wC;
                wC = increment(&memoryFileSplit, &breakdown);

                wmcIdx++;
                wCCheck(wC, "while loop check");

                if (isalnum(wC)) {
                    breakdown.memoryKey[wmcIdx] = wC;
                    wmcIdx++;
                    wC = increment(&memoryFileSplit, &breakdown);
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
                wC = increment(&memoryFileSplit, &breakdown);
                wCCheck(wC, "Post NAMETOKEN 2 If Two");
                // wC will be at COLON
            }



            printf("Line 271\n");
            if (wC == COLON) {
                wCCheck(wC, "COLON check one");
                colonCheckOne = true;
                wC = increment(&memoryFileSplit, &breakdown); // this should place wC at an open brace
                wCCheck(wC, "COLON Check Two");
            }

            if (wC == OPENBRACE) {
                wCCheck(wC, "OPENBRACE check one");
                openBraceToken = true;
                wC = increment(&memoryFileSplit, &breakdown);
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
                    switch (wC) {
                        case NAMETOKEN:
                            printf("NAMETOKEN CASE HIT: %d\n", (int)wC);
                            printf("Nametoken reached\n");

                            //
                            printf("Tracker check pre associations: %d\n", breakdown.tracker);
                            associations(wC, &memoryFileSplit, &breakdown);
                            printf("Tracker check post associations: %d\n", breakdown.tracker);
                            wC = increment(&memoryFileSplit, &breakdown);
                            printf("Tracker Check Line 339: %d\n", breakdown.tracker);
                            wCCheck(wC, "Final NAMETOKEN check"); // At this point wC is returning an open brace
                            break;
                        case ASSOCIATOR:
                            printf("Associator reached");
                            associator(wC, &tracker, &memoryFileSplit, &breakdown);

                            break;
                        case CLOSEBRACE:
                            printf("310");
                            wC = increment(&memoryFileSplit, &breakdown);
                            break;
                        case 'NULL':
                            printf("314");
                            endLinePoint = breakdown.tracker;
                            whileBool = false;
                            break;
                        case COMMA:
                            printf("Line 319");
                            wC = increment(&memoryFileSplit, &breakdown);
                            commaCheck = true;
                            break;
                        case SEMICOLON:
                            wCCheck(wC, "inside semicolon case");
                            wC = increment(&memoryFileSplit, &breakdown);
                            whileBool = false;
                            break;
                        default:
                            printf("Crawler Default Error");
                            whileBool = false;
                            break;
                    }

                } if (isalpha(wC)) {
                    printf("isalpha true! :o");
                    printf("isalpha true tracker check: %d", breakdown.tracker);
                    exit(1);
                }

            }
        }
        /* The next line is the end of the nametoken loop*/
     }


        printf("Fallen off of switch, 0\n");
        printf("Main array: %s\n", memoryFileSplit.mainArray);
        printf("Memkey: %s\n", breakdown.memoryKey);
        printf("Associations: %s\n", breakdown.associations);
        printf("Working Associators: %s\n", breakdown.workingAssociators);


    }


void lRun()
    {   printf("Catalyst Reached\n");
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


