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

typedef struct {
    char wordOne[80];
    char wordTwo[80];
} builder;




void parseAssocs(Breakdown *breakdown, Working *working) {
    free_morphemes fmorphemes;
    builder builderr;
    int assocSize; // size of the assoc array in the working struct
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations[0]);
    char selection[200]; // Similar to wC in Lexer
    for (int a = 0; a < assocSize; a++) {
        selection[a] = breakdown->associations[a]; // Sets the current working character
        switch (selection[a]) {
            case NAMETOKEN:
                if (firstNameTokenCheck == false) {
                    firstNameTokenCheck = true;
                }
                if (firstNameTokenCheck == true && secondNameTokenCheck == false) {
                   working->assoc[a] = COMMA; // This will act as a delimiter for associations within the array within the struct
                   secondNameTokenCheck = true;
                    if (secondNameTokenCheck == true) {
                        firstNameTokenCheck = false;
                        secondNameTokenCheck = false;
                    }
                }

                break;
            default:
                if (isalpha(selection[a]) || isalnum(selection[a])) {
                    working->assoc[a] = selection[a];
                }
                if (isalpha(selection[a]) != true) {
                    printf("Unrecognized token %s\n", selection);
                }
                break;


        } // End of switch

    } // End of for
    for (int b = 0; b < sizeof(working->assoc) / sizeof(working->assoc[0]); b++) {
        // These if statements get the char counts for the associations
        if (isalpha(working->assoc[b])) {
            assocCharCount++;
        }
        if (isalnum(working->assoc[b])) {
            assocCharCount++;
        }
        if (working->assoc[b] == COMMA) {
            commaPoint = working->assoc[b];
            counts[countsIdx] = assocCharCount;
            countsIdx++;
            assocCharCount = 0;
        }
        // The k for loop is isolating assocations
        for (int k = 0; k <= commaPoint - 1; k++) {
            working->association[k] = working->assoc[b];

        } // End of k for

        // Here we will need to reference the symbol table for encodings and translate to .nexcode

        // For checking for macro'd morphemes (mm's) we should have a list of all of the first letters of
        // the mm's and if there's a match advance one letter at a time checking for mm matches
        int firstsIdx = 0;
        int firstFoundIdx = 0;
        bool firstFound = false;
        char wC;

        for (int c = 0; c < assocSize; c++) {
            if (selection[c] == firsts[firstsIdx]) {
                firstFound = true;
                firstsIdx++;
                firstFoundIdx = c;
                wC = selection[c];
                int inc = c + 1;
                int wCU = inc;
                if (wC == firsts[firstsIdx]) {
                    // This switch covers the lowercase morphemes only. I'm thinking
                    // We should allow default to fall through to a second switch to
                    // sift through, or a loop
                    switch (wC) {
                        case 't':
                            wC = selection[wCU];
                            if (wC == 'o') {
                                builderr.wordOne[0] = to;

                            }
                            if (wC == 'i') {
                                builderr.wordTwo[0] = tion;
                            }
                            if (wC == 'h') {
                                inc = inc + 1;
                                wC = selection[inc];
                                if (wC == 'e') {
                                    builderr.wordOne[0] = the;
                                }
                                if (wC == 'a') {
                                    builderr.wordTwo[0] = that;
                                }
                            }
                            break;
                        case 'i':
                            wC = selection[wCU];
                            if (wC == 's') {
                                builderr.wordOne[0] = is;
                            }
                            if (wC == 'n') {
                                inc = inc + 1;
                                wC = selection[inc];
                                if (wC != 'g') {
                                    builderr.wordOne[0] = in;
                                }
                                if (wC == 'g') {
                                    builderr.wordOne[0] = ing;
                                }
                            }

                            break;
                        case 'a':
                            wC = selection[wCU];
                            if (wC == 's') {
                                builderr.wordOne[0] = as;
                            }
                            if (wC == 'n') {
                                builderr.wordOne[0] = and;
                            }
                            if (wC == 'b') {
                                builderr.wordOne[0] = able;
                            }
                            break;
                        case 'o':
                            wC = selection[wCU];
                            if (wC == 'f') {
                                builderr.wordOne[0] = of;
                            }
                            if (wC == 'n') {
                                builderr.wordOne[0] = on;
                            }
                            break;
                        case 'e':
                            wC = selection[wCU];
                            if (wC == 'd') {
                                builderr.wordOne[0] = ed;
                            }
                            if (wC == 'r') {
                                builderr.wordOne[0] = er;
                            }
                            break;
                        case 'r':
                            wC = selection[wCU];
                            if (wC == 'e') {
                                builderr.wordOne[0] = re;
                            }
                            break;
                        case 'l':
                            wC = selection[wCU];
                            if (wC == 'y') {
                                builderr.wordOne[0] = ly;
                            }
                            break;
                        case 'm':
                            wC = selection[wCU];
                            if (wC == 'e') {
                                builderr.wordOne[0] = ment;
                            }
                            break;
                        case 'f':
                            wC = selection[wCU];
                            if (wC == 'f') {
                                builderr.wordOne[0] = ffor;
                            }
                            break;
                        case 'n':
                            wC = selection[wCU];
                            if (wC == 'e') {
                                builderr.wordOne[0] = ness;
                            }
                            break;
                        default:
                            printf("Falling through");
                            break;

                    } // End of Switch


                    if (isalpha(selection[c])) {
                        if (isupper(selection[c])) {
                            builderr.wordOne[0] = selection[c];
                        }

                        if (islower(selection[c])) {
                            // We need to loop through secondaries and check for a match
                            for (int seconds = 0; seconds < sizeof(secondaries) / sizeof(secondaries[0]); seconds++) {
                                if (selection[c] == secondaries[seconds]) {
                                    builderr.wordOne[0] = secondaries[seconds];
                                }
                            }
                        }
                        else {
                            exit(1);
                        }


                    }

                    if (isalnum(selection[c])) {

                    }





                c = assocSize;
            }
        }






        }


    } // End of j for


}

int main() {
    // This establishes the Breakdown and Working instacnes and
    // passes them into parseAssocs
    Breakdown breakdown;
    Working working;
    parseAssocs(&breakdown, &working);




    return 0;
}

