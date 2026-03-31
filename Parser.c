//
// Created by steviexx on 3/31/26.
//

#include "Parser.h"
#include "Lexer.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

void parseAssocs(Breakdown *breakdown, Working *working) {
    int assocSize; // size of the assoc array in the working struct
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations[0]);
    char selection[200]; // Similar to wC in Lexer
    for (int i = 0; i < assocSize; i++) {
        selection[i] = breakdown->associations[i]; // Sets the current working character
        switch (selection[i]) {
            case NAMETOKEN:
                if (firstNameTokenCheck == false) {
                    firstNameTokenCheck = true;
                }
                if (firstNameTokenCheck == true && secondNameTokenCheck == false) {
                   working->assoc[i] = COMMA; // This will act as a delimiter for associations within the array within the struct
                   secondNameTokenCheck = true;
                    if (secondNameTokenCheck == true) {
                        firstNameTokenCheck = false;
                        secondNameTokenCheck = false;
                    }
                }

                break;
            default:
                if (isalpha(selection[i]) || isalpha(selection[i])) {
                    working->assoc[i] = selection[i];
                }
                if (isalpha(selection[i]) != true) {
                    printf("Unrecognized token %s\n", selection);
                }
                break;


        } // End of switch

    } // End of for
    for (int j = 0; j < sizeof(working->assoc) / sizeof(working->assoc[0]); j++) {
        // These if statements get the char counts for the associations
        if (isalpha(working->assoc[j])) {
            assocCharCount++;
        }
        if (isalnum(working->assoc[j])) {
            assocCharCount++;
        }
        if (working->assoc[j] == COMMA) {
            commaPoint = working->assoc[j];
            counts[countsIdx] = assocCharCount;
            countsIdx++;
            assocCharCount = 0;
        }
        // The k for loop is isolating assocations
        for (int k = 0; k <= commaPoint - 1; k++) {
            working->association[k] = working->assoc[j];

        } // End of k for

        // Here we will need to reference the symbol table for encodings and translate to .nexcode

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

