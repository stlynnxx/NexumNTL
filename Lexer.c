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
char associations(char wC[50], char fileArray[50], int tracker) {

    // Whenever associations is called initally wC will be on
    // the first association's opening name token
    bool associationBool = false;
    bool nameTokenBool = false;
    int letterCounter = 0;
    char workingAssociations[50];
    int associationsSizes[100];
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
        // Instead of looking for a specific delimiter to end the assocations loop
        // this ends it if wc is neither a letter or nameToken
        if (wC[i] != alphas[i] | wC != nameToken) {
            i = alphasLength + 1;
        }

    }
    // Tracker at this point should be on the closing brace of the line in question
    return workingAssociations[0], tracker;
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
                            associations(wC, fileArray ,tracker);
                            tracker++;
                            wC[0] = fileArray[tracker];
                        }

                }

    }




}
void rawler(FILE *fp) {

        for (int i = 0; i < sizeof(memoryFileSplit.mainArray); i++)
        {
            /* Here the first char of memfilesplit.mainarray is loaded into workingChar[0]
              letterCounter is also sitting at 0 */
            fileArray[0] = memoryFileSplit.mainArray[i];
            // Don't forget that fileArray is the entirety of the file at this moment
            wC[0] = fileArray[0];
            if (wC == openBraceToken) {
                /* If we are thinking of wC as a 'selector' moving across the file
                Char by Char then this next line advances the selector */
                wC[0] = fileArray[1];
                tracker++;
                /* We won't exactly be needing tracker at this moment but it's still good to
                 * keep it updated */
                if (wC == nameToken) {
                    // This will need to advance workingChar until another nameToken is hit
                    // And then append everything between to workingMemKeys
                    wC[0] = fileArray[2];
                    tracker++;
                    nameTokenPoint = tracker;
                    // this is the loop that will be doing the letter check.
                    // Alphas and alphas length are in SymbolTable.h
                    // This is also where we get the length of the memory key
                    // via letterCounter.
                    for (int i = 0; i < alphasLength; i++) {
                        // I'm not super convinced that this is exactly how I
                        // want to handle letter checking for real as it seems
                        // prone to unwanted results/unnecessary loops.
                        // But also maybe I'm overthinking it
                        if (wC[i] != alphas[i]) {
                            memoryKeyBool = false;
                        }
                        if (workingCheck[i] == alphas[i]) {
                            memoryKeyBool = true;
                            workingMemKeys[i] = fileArray[i];
                            letterCounter++;
                            tracker++;
                        }
                    }
                    /* letterCounter gets us the length of the Memory Key.
                     * From here we can go from the point of one char after the initial
                     * nametoken (namePointToken is that exact index)
                    and add letterCounter and that range will hold the memory key and we can append
                    it to a seperate array.
                    if nameTokenPoint = 5 and letterCounter = 6, then 5-11 is our MemoryKeyRange

                    */
                    // If we're thinking of tracker as a sort of mirror for the imagined selector of
                    // fileArray then this statement moves tracker onto the first char after the last letter of
                    // the memory key, which means it should return a name token.
                    tracker++;
                    wC[0] = fileArray[tracker];
                    if (wC == nameToken) {
                        tracker++;
                        wC[0] = fileArray[tracker];
                    }
                    // Right now we aren't using a comma in the .nex
                    /*
                    if (wC == comma) {
                        tracker++;
                        tracker++;
                        wC[0] = fileArray[tracker];
                    }*/




                    if (wC == nameToken) {
                        //This is where we will begin associator logic. We need to keep
                        // in mind that it needs to be repeatable.

                        // this is the start of the association loop. I've already started
                        // a function to move all of this into but I'm feeling it out here first
                        // and then moving it all to the function

                        // We basically need to repeatedly call associations
                        // Until we hit the end file delimiter outside of the
                        // associations loop

                        // This is the loop that is meant to call the associations
                        // loop for all of the associations
                        tracker++;
                        wC[0] = fileArray[tracker];
                        while (wC[i] == alphas[i] | wC == nameToken) {
                            associations(wC, fileArray ,tracker);
                            tracker++;
                            wC[0] = fileArray[tracker];
                        }

                    }
                    // I still need to figure out a clean end to the lexing process
                    // here
                }
            }

            // we will need a demlimiter to tell the association loop when to end
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


    catalyst();
    return 0;
}