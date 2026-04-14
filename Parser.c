//
// Created by steviexx on 3/31/26.
//

#include "Parser.h"
#include "Lexer.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "SourceGenerator.h"

typedef struct {
    char scratchOne[80];
    char scratchTwo[80];
} builder;


// Globals
int breakdownIdx = 0;

int scratchOneIdx = 0;
// int workIdx = breakdownIdx + 1;


char checker(builder *builderr, Breakdown *breakdown, char wC) {
    if (isupper(wC)) {
        builderr->scratchOne[scratchOneIdx] = wC;
        scratchOneIdx++;
    }
    int firstSize = sizeof(firsts) / sizeof(firsts[0]);
    for (int i = 0; i < firstSize; i++) {
        if (wC == firsts[i]) {
            // This switch covers the lowercase morphemes only. I'm thinking
            // We should allow default to fall through to a second switch to
            // sift through, or a loop
            switch (wC)
            {
                case 't':
                    // We need to incremenet here
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'o') {
                        builderr->scratchOne[scratchOneIdx] = to;
                        scratchOneIdx++;

                    }
                    if (wC == 'i') {
                        builderr->scratchTwo[scratchOneIdx] = tion;
                        scratchOneIdx++;
                    }
                    if (wC == 'h') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = the;
                            scratchOneIdx++;
                        }
                        if (wC == 'a') {
                            builderr->scratchTwo[scratchOneIdx] = that;
                            scratchOneIdx++;

                        }
                        break;
                        case 'i':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 's') {
                            builderr->scratchOne[scratchOneIdx] = is;
                            scratchOneIdx++;
                        }
                        if (wC == 'n') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                        }
                        if (wC != 'g') {
                            builderr->scratchOne[scratchOneIdx] = in;
                            scratchOneIdx++;
                        }
                        if (wC == 'g') {
                            builderr->scratchOne[scratchOneIdx] = ing;
                            scratchOneIdx++;
                        }
                        break;
                        case 'a':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 's') {
                            builderr->scratchOne[scratchOneIdx] = as;
                            scratchOneIdx++;
                        }
                        if (wC == 'n') {
                            builderr->scratchOne[scratchOneIdx] = and;
                            scratchOneIdx++;
                        }
                        if (wC == 'b') {
                            builderr->scratchOne[scratchOneIdx] = able;
                            scratchOneIdx++;
                        }
                        break;
                        case 'o':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'f') {
                            builderr->scratchOne[scratchOneIdx] = of;
                            scratchOneIdx++;
                        }
                        if (wC == 'n') {
                            builderr->scratchOne[scratchOneIdx] = on;
                            scratchOneIdx++;
                        }
                        break;
                        case 'e':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            builderr->scratchOne[scratchOneIdx] = ed;
                            scratchOneIdx++;
                        }
                        if (wC == 'r') {
                            builderr->scratchOne[scratchOneIdx] = er;
                            scratchOneIdx++;
                        }
                        break;
                        case 'r':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = re;
                            scratchOneIdx++;
                        }
                        break;
                        case 'l':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'y') {
                            builderr->scratchOne[scratchOneIdx] = ly;
                            scratchOneIdx++;
                        }
                        break;
                        case 'm':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = ment;
                            scratchOneIdx++;
                        }
                        break;
                        case 'f':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'f') {
                            builderr->scratchOne[scratchOneIdx] = for_;
                            scratchOneIdx++;
                        }
                        break;
                        case 'n':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = ness;
                            scratchOneIdx++;
                        }
                        break;
                        default:
                        // if the currently examined char does not branch out
                        // to one of the shortened morphemes, then we fall through
                        // to the next check
                        printf("Falling through");
                        break;
                    } // End of Switch


            }
        }
    }
    return wC;
}











void parseAssocs(Breakdown *breakdown, Working *working, builder *builderr) {
    free_morphemes fmorphemes;

    int assocSize; // size of the assoc array in the working struct
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    int workIdx = breakdownIdx + 1;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations[0]);
    char wC; // Similar to wC in Lexer
    bool run = true;
    wC = breakdown->associations[breakdownIdx]; // This sets the current working character

    if (wC == NAMETOKEN) {
        if (firstNameTokenCheck == false) {
            firstNameTokenCheck = true;

        }
        if (firstNameTokenCheck == true && secondNameTokenCheck == false) {
            working->assoc[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
            secondNameTokenCheck = true;
            if (secondNameTokenCheck == true) {
                firstNameTokenCheck = false;
                secondNameTokenCheck = false;
            }
        }

    }
    else {
        perror("Parser nametoken error");
    }


    breakdownIdx++;
    wC = breakdown->associations[breakdownIdx];


    // I don't remember why I wrote this so it's commented out hoping it'll become obvious that I do or don't need it

    /*
    for (int b = 0; b < assocSize; b++) {
        // These if statements get the char counts for the associations
        if (isalpha(working->assoc[b])) {
            assocCharCount++;
        }
        if (isalnum(working->assoc[b])) {
            assocCharCount++;
        }
        if (breakdown->associations[b] == COMMA) {
            commaPoint = breakdown->associations[b];
            counts[countsIdx] = assocCharCount;
            countsIdx++;
            assocCharCount = 0;
        }
        // The k for loop is isolating assocations
        for (int k = 0; k <= commaPoint - 1; k++) {
            breakdown->associations[k] = breakdown->associations[b];

        } // End of k for
        */

    // Here we will need to reference the symbol table for encodings and translate to .nexcode

    // For checking for macro'd morphemes (mm's) we should have a list of all of the first letters of
    // the mm's and if there's a match advance one letter at a time checking for mm matches



    // This is checking to see if the current char being examined is a capital letter,
    // and append it to the scratch if so

    wC = checker(builderr, breakdown, wC);

    if (islower(wC)) {
        // We need to loop through secondaries and check for a match
        for (int seconds = 0; seconds < sizeof(secondaries) / sizeof(secondaries[0]); seconds++) {
            if (wC == secondaries[seconds])
            {
                builderr->scratchOne[0] = secondaries[seconds];
            }
            else
            {
                exit(1);
            }
            if (isalnum(wC))
            {
                builderr->scratchOne[scratchOneIdx] = wC;
                scratchOneIdx++;
            }

            if (wC == NAMETOKEN)
            {
                if (firstNameTokenCheck == true) {
                    // This where we will need to repeat some logic
                }






            }
        }
    }
}




// End of j for
// End of a loop
void flag() {
    nexcodeFlag = true;
}


int prun() {
    // This establishes the struct instances and
    // passes them into parseAssocs
    Breakdown breakdown;
    Working working;
    builder builderr;
    parseAssocs(&breakdown, &working, &builderr);


    return 0;
}

