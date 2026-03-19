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
#define MAX_ASSOC 50
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
    char associations[MAX_ASSOC][MAX_ASSOC_LEN];
} Breakdown;


int tracker = 0;


void *loadNexFile(FILE *fp, MemoryFileSplit *split) {
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

   fread(split->mainArray, sizeof(split->mainArray), 1, fp);
   split->mainArray[size] = '\0';

}

char associations(char wC, char fileArray[2000], int tracker)
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
    char workingAssociators[200];
    char export[250];
    bool repeatBool = true;
    wC = wC;
    while (repeatBool == true) {
        switch (wC)
        {
            case NAMETOKEN:
                nameTokenOne = true;
                if (nameTokenOne == true) {
                    tracker++;
                    wC = fileArray[tracker];
                    break;
                }
                if ((nameTokenOne == true) && (nameTokenTwo == true)) {
                    break;
                }

                break;
            case ASSOCIATOR:
                associatorBool = true;
                // This will record the index where the associator token was discovered
                associatiorStartPoint = tracker;
                // This will move tracker to the first letter of the associator
                tracker++;
                wC = fileArray[tracker];
                while (associationBool == true) {
                    if (isalpha(wC) == true)
                    {
                        associatorLetterCounter++;
                        workingAssociators[workingAssociatorIdx] = wC;
                        workingAssociatorIdx++;
                        tracker++;
                        wC = fileArray[tracker];
                    }
                    if (isalpha(wC) == false) {
                        associationBool = false;
                    }
                }
                break;
            case COMMA:
                tracker = tracker + associatorLetterCounter + 1;
                wC = fileArray[tracker];
                break;
            default:
                if (isalpha(wC) == true) {
                    while (isalpha(wC) == true) {

                        workingAssociations[workingAssocationsIdx] = fileArray[tracker];
                        wC = fileArray[tracker];
                        tracker++;
                        workingAssocationsIdx++;
                    }
                }
                nameTokenTwo = true;



                break;
        } // End of switch
        if ((isalpha(wC) == false) && (wC != NAMETOKEN) && (wC != ASSOCIATOR)) {
            repeatBool = false;
        }
    } // While loop closing brace


    size = sizeof(workingAssociations) / sizeof(workingAssociations[0]);
    for (int i = 0; i < size ; i++) {
        export[i] = workingAssociations[i];
    }
    exportSize = sizeof(export) / sizeof(export[0]);
    exportSize = exportSize + 1;
    export[exportSize] = tracker;
    // Tracker at this point should be on the closing brace of the line in question
    return export[0];
}

char setr(MemoryFileSplit *split) {
    char wC;
    wC = split->mainArray[0];
    return wC;
}
char increment(MemoryFileSplit *split) {
    char wC;
    tracker++;
    wC = split->mainArray[tracker];
    return wC;
}
void wCCheck(char wC, char location[30]) {
    printf("wC Check %s: %c\n", location, wC);

}
void associator() {}
void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
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
    wCCheck(wC, "Line 188"); // This should be mainArray[0], so, {
    printf("Tracker Check %d\n", tracker);
    // this function increments tracker by one and updates wC to mainArray[1]
    wC = increment(&memoryFileSplit);
    wCCheck(wC, "Line 192"); // Here wC should be at mainArray[1] which should be '
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
                wC = increment(&memoryFileSplit);
                wCCheck(wC, "Line 207"); // As of here the wC is correct; it is at the first letter of the first memkey
            }
            if (isalpha(wC) != true && memoryKeyBool == true) {
                memoryKeyBool = false;
                wC = increment(&memoryFileSplit);
            }


                // wC should be at [2] which should always be a letter
                if (isalpha(wC)) {
                    printf("wC == alphas[i] running\n");
                    memoryKeyBool = true;
                    wCCheck(wC, "Line 214");
                    wC = increment(&memoryFileSplit); // This should increment by one per call
                    wCCheck(wC, "Line 225");
                    // The idea here is that the while loop will run until memkeybool
                    // gets flipped and THEN if wC == nameToken runs
                    while (memoryKeyBool == true) {
                        int wmcIdx = 0;
                        printf("memkeybool == true loop running\n");
                        workingMemKeys[wmcIdx] = wC;
                        wCCheck(wC, "Line 231");
                        wC = increment(&memoryFileSplit);
                        wmcIdx++;
                        wCCheck(wC, "Line 233");
                        if (wC == NAMETOKEN) {
                            memoryKeyBool = false;
                        }
                    }

                    if (wC == NAMETOKEN && nameTokenOne == true) {
                        nameTokenTwo = true;
                        printf("Line 238 reached");
                        wC = increment(&memoryFileSplit);
                        wCCheck(wC, "Line 247"); // this should put wC at a colon
                    }
                    bool colonCheck = false;
                    bool spaceCheck = false;
                    bool openBraceToken = false;
                    if (wC == COLON) {
                        colonCheck = true;
                        wC = increment(&memoryFileSplit); // this should place wC at a space
                        wCCheck(wC, "Line 255");
                    }
                    /*if (wC == SPACE) {
                        spaceCheck = true;
                        wC = increment(&memoryFileSplit);
                        wCCheck(wC, "Line 260");
                    }*/
                    if (wC == OPENBRACE) {
                        openBraceToken = true;
                        wC = increment(&memoryFileSplit);
                        wCCheck(wC, "Line 265");
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
                        if (incrementOrNah == true) {
                            wC = increment(&memoryFileSplit);
                        }
                        if (isalpha(wC) == false) {
                            wCCheck(wC, "Line 281\n");
                            switch (wC) {
                                case COLON:
                                    printf("Line 240 reached");
                                    wC = increment(&memoryFileSplit);
                                    break;
                                /*case SPACE:
                                    printf("243");
                                    wC = increment(&memoryFileSplit);
                                    break;*/

                                case NAMETOKEN:
                                case ASSOCIATOR:
                                    printf("246");
                                    if (wC == ASSOCIATOR) {
                                        associatorCheck = true;
                                    }
                                    if (nameTokenOne == true) {
                                        // wC = increment(&memoryFileSplit);
                                        while (isalpha(wC) == true || wC == NAMETOKEN) {
                                            associationsReturn[0] = associations(wC, memoryFileSplit.mainArray, tracker);
                                            wC = increment(&memoryFileSplit);
                                        }
                                    }
                                    break;
                                case CLOSEBRACE:
                                    printf("249");
                                    wC = increment(&memoryFileSplit);
                                    break;
                                case ENDOFFILE:
                                    printf("252");
                                    endLinePoint = tracker;
                                    break;
                                case COMMA:
                                    wC = increment(&memoryFileSplit);
                                    commaCheck = true;
                                    break;


                                    default:
                                    printf("Default Error");
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


