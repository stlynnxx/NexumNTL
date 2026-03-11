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
    if (wC == nameToken)
    {
        tracker++;
        wC[0] = fileArray[tracker];
        // At this point wC will be on the first char of the association
            }

    for (int i = 0; i < alphasLength; i++) {
        // This is the same loop I'm using for the alpha check
        // for the memory key with the bool swapped out


        if (wC == nameToken | wC[i] == alphas[i]) {
            wC[i] = fileArray[tracker];
            if (wC == nameToken) {
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
        if (wC == associatorToken) {
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
            if (wC == comma)
                {
                    // This puts tracker at the point of the comma which
                    // in this context is acting as a delimiliter for the associator
                    tracker = tracker + associatorLetterCounter + 1;
                    wC[0] = fileArray[tracker];

                }
            tracker++;
            wC[0] = fileArray[tracker];
            if (wC == space) {
                tracker++;
                wC[0] = fileArray[tracker];
            }
            if (wC == nameToken) {
                // This will need to repeat earlier logic an indefinte amount of times.

            }





        }

        // Instead of looking for a specific delimiter to end the assocations loop
        // this ends it if wc is neither a letter or nameToken
        if (wC[i] != alphas[i] | wC != nameToken | wC != associatorToken) {
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

void crawler(FILE *fp) {
    MemoryFileSplit memoryFileSplit;
    char fileArray[2000];
    char workingCheck[5];
    char wC[50];
    char workingMemKeys[200];
    bool memoryKeyBool;
    bool assocationBool;
    int tracker = 0;
    int nameTokenPoint;
    int letterCounter = 0;
    // loadNexFile loads the working file into memoryFileSplit.mainArray
    loadNexFile(fp, &memoryFileSplit);
    int len = sizeof(memoryFileSplit.mainArray) / sizeof(memoryFileSplit.mainArray[0]);
    // Here begins the crawling process.

    for (int i = 0; i < len; i++);
    {
        // During loadNexFile, the working file is loaded into
        // mainArray, and now that is being loaded into fileArray

        wC[0] = memoryFileSplit.mainArray[0]; // wC is our working character.
        if (wC == openBraceToken)
            {
                tracker++; // tracker is doing as it is named and tracking our working location
                wC[0] = memoryFileSplit.mainArray[tracker];
            }
        if (wC == nameToken)
            {
                nameTokenPoint = tracker; // This records the index where the first name token occurs
                tracker++;
                wC[0] = memoryFileSplit.mainArray[tracker];
            }
        for (int i = 0; i < alphasLength; i++)
            {
                if (wC[i] == alphas[i] | wC == nameToken)
                    {
                      // I feel comfortable placing this signal here before the hard letter check
                      // Just because even if it's only a pass for a nameToken at this point we're
                      // Likely reading a memoryKey
                        memoryKeyBool = true;
                        // The idea here is that the while loop will run until memkeybool
                        // gets flipped and THEN if wC == nameToken runs
                        while (memoryKeyBool == true) {
                            if (wC[i] == alphas[i])
                            {
                                letterCounter++;
                                tracker++;
                                workingMemKeys[i] = memoryFileSplit.mainArray[i];

                            }
                            if (wC[i] != alphas[i])
                            {
                                memoryKeyBool = false;
                            }
                        }
                        if (wC == nameToken)
                            {
                                tracker++;
                                wC[0] = memoryFileSplit.mainArray[tracker];
                            }

                    }

            }
            // I'm unsure about using these multi char tokens
            if (wC[0] == openingSeq[0])
                {
                    tracker++;
                    wC[0] = memoryFileSplit.mainArray[tracker];
                }
            if (wC == nameToken)
                {
                    tracker++;
                    wC[0] = memoryFileSplit.mainArray[tracker];
                    while (wC[0] == alphas[0] | wC == nameToken)
                        {
                            associations(wC, memoryFileSplit.mainArray, tracker);
                            tracker++;
                            wC[0] = memoryFileSplit.mainArray[tracker];
                        }

                }

    }




}





// The open function will serve to open the file and append
// to memory.
void catalyst()
    {
        FILE *fp = fopen("Testing2.nex", "r");
        crawler(fp);
        fclose(fp);
    }


int lex_main() {
    printf("%s", openBraceToken);

    char list[5] = "Hell";



    catalyst();
    return 0;
}