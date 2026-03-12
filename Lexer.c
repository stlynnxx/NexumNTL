//
// Created by steviexx on 2/28/26.
//

#include "Lexer.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

char associations(char wC[50], char fileArray[2000], int tracker) {

    // Whenever associations is called initally wC will be on
    // the first association's opening name token
    bool associationBool = false;
    bool associatorBool = false;
    bool nameTokenBool = false;
    int letterCounter = 0;
    int size;
    int exportSize;
    int associatorLetterCounter = 0;
    int associatiorStartPoint;
    char workingAssociations[50];
    int associationsSizes[100];
    char workingAssociators[200];
    char export[250];
    wC[0] = fileArray[tracker];
    if (wC == NAMETOKEN)
    {
        tracker++;
        wC[0] = fileArray[tracker];
        // At this point wC will be on the first char of the association
            }

    for (int i = 0; i < alphasLength; i++) {
        // This is the same loop I'm using for the alpha check
        // for the memory key with the bool swapped out


        if (wC == NAMETOKEN) {
            wC[i] = fileArray[tracker];
            if (wC == NAMETOKEN) {
                nameTokenBool = true;
                tracker++;
            }
            if (wC[i] == alphas[i]) {
                associationBool = true;
                workingAssociations[i] = fileArray[i];
                letterCounter++;
                tracker++;
            }
        }
        if (wC == ASSOCIATOR) {
            associatorBool = true;
            // This will record the index where the associator token was discovered
            associatiorStartPoint = tracker;
            // This will move tracker to the first letter of the associator
            tracker++;
            wC[0] = fileArray[tracker];
            if (wC[i] == alphas[i])
            {
                    associatorLetterCounter++;
                    workingAssociators[i] = wC[i];

            }
            if (wC == COMMA)
                {
                    // This puts tracker at the point of the comma which
                    // in this context is acting as a delimiliter for the associator
                    tracker = tracker + associatorLetterCounter + 1;
                    wC[0] = fileArray[tracker];

                }
            tracker++;
            wC[0] = fileArray[tracker];
            if (wC == SPACE) {
                tracker++;
                wC[0] = fileArray[tracker];
            }
            if (wC == NAMETOKEN) {
                // This will need to repeat earlier logic an indefinte amount of times.

            }





        }

        // Instead of looking for a specific delimiter to end the assocations loop
        // this ends it if wc is neither a letter or nameToken
        if (wC[i] != alphas[i] | wC != NAMETOKEN | wC != ASSOCIATOR) {
            i = alphasLength + 1;
        }

    }
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
void crawler(FILE *fp)
{
    MemoryFileSplit memoryFileSplit;
    char associationsReturn[2000];
    char workingCheck[5];
    char wC;
    char workingMemKeys[200];
    bool memoryKeyBool;
    bool assocationBool;

    int nameTokenPoint;
    int letterCounter = 0;
    int endLinePoint;

    // loadNexFile loads the working file into memoryFileSplit.mainArray
    loadNexFile(fp, &memoryFileSplit);
    int len = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);

    // Here begins the crawling process.
    printf("Crawler Start Reached\n");
    for (int i = 0; i < len; i++);
    {
        printf("For Loop 01 executed\n");
        // During loadNexFile, the working file is loaded into
        // mainArray, and now that is being loaded into fileArray

       // wC[0] = memoryFileSplit.mainArray[tracker]; // wC is our working character.
        wC = setr(&memoryFileSplit); // setr sets wC to mainArray[0]. At this point wC and tracker should both be at 0
        // wC should be { when the next line runs
        wCCheck(wC, "One"); // This should be mainArray[0], so, {
        printf("Tracker Check %d\n", tracker);
        // this function increments tracker by one and updates wC to mainArray[1]
        wC = increment(&memoryFileSplit);
        wCCheck(wC, "Two"); // Here wC should be at mainArray[1] which should be '
        printf("---Testing Area---\n");
        int s = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);
        for (int i = 0; i < s; i++) {
            printf("Mem Test %d: %c\n", i, memoryFileSplit.mainArray[i]);
            printf("----\n");
        }


        if (wC == NAMETOKEN) // we should be at [1] which should always be '
            {
                printf("First nameToken found\n");
                nameTokenPoint = tracker; // This records the index where the first name token occurs

                wC = increment(&memoryFileSplit); // This should update wC to [2], which should always be the first char of the mem key
                wCCheck(wC, "Three");
            }
        for (int i = 0; i < alphasLength; i++)
            {
                if (wC == alphas[i]) // We should be at [2] which should always be a letter
                {
                        memoryKeyBool = true;
                        wCCheck(wC, "Pre MemkeyBool");

                        wC = increment(&memoryFileSplit); // This should increment by one per call
                        wCCheck(wC, "Line 208");
                        ;
                        printf("MemKeyBool reached\n");
                        // The idea here is that the while loop will run until memkeybool
                        // gets flipped and THEN if wC == nameToken runs
                        if (memoryKeyBool == true) {
                           workingMemKeys[i] = wC;

                        }
                } // this is the end of the letter check
                     if (wC == NAMETOKEN)
                     {
                        printf("wC == nameToken\n");
                        wC = increment(&memoryFileSplit);
                    }
            } // This is the end of the for loop

            if (wC == COLON)
                {
                    wC = increment(&memoryFileSplit);
                }
            if (wC == SPACE) {
                wC = increment(&memoryFileSplit);
            }
            if (wC == NAMETOKEN)
                {
                    wC = increment(&memoryFileSplit);
                    while (wC == alphas[0] | wC == NAMETOKEN)
                        {
                            associationsReturn[0] = associations(&wC, memoryFileSplit.mainArray, tracker);
                            wC = increment(&memoryFileSplit);
                        }

                }
            if (wC == CLOSEBRACE) {
                wC = increment(&memoryFileSplit);
            }
            if (wC == ENDOFFILE) {
                endLinePoint = tracker;

            }

    }
    printf("%s\n", associationsReturn);
    printf("%s\n", workingMemKeys);


}





// The open function will serve to open the file and append
// to memory.
void catalyst()
    {   printf("Catalyst Reached\n");
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


