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
    int peekIdx = breakdownIdx + 1;
    char wCPeek = breakdown->associations[peekIdx];
    if (isupper(wC)) {
        builderr->scratchOne[scratchOneIdx] = wC;
        scratchOneIdx++;
        switch (wC) {
            case 'A':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'b') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'l') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = Able;
                        }
                    }
                }
                if (wC == 'l') {
                    builderr->scratchOne[scratchOneIdx] = Al;
                }
                if (wC == 's') {
                    builderr->scratchOne[scratchOneIdx] = As;
                }
                if (wC == 't') {
                    builderr->scratchOne[scratchOneIdx] = At;
                }
                if (wC == 'n') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'd') {
                        builderr->scratchOne[scratchOneIdx] = And;
                    }
                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'i') {
                            builderr->scratchOne[scratchOneIdx] = Anti;
                        }
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = Ante;
                        }
                    if (wC == 'c') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = Ance;
                        }
                    }
                }


            break;
            case 'C':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'd') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = Cede;
                        }
                    }
                    if (wC == 's') {
                        builderr->scratchOne[scratchOneIdx] = Cess;
                    }
                }
                if (wC == 'i') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'r') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'c') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'u') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'm') {
                        builderr->scratchOne[scratchOneIdx] = Circum;
                }
                if (wC == 'l') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'u') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                builderr->scratchOne[scratchOneIdx] = Clude;
                            }
                        }
                    }
                }
                break;
            case 'D':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'i') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'c') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 't') {
                            builderr->scratchOne[scratchOneIdx] = Dict;
                        }
                    }
                }
                break;
            case 'E':
                 breakdownIdx++;
                 wC = breakdown->associations[breakdownIdx];
                 if (wC == 'd') {
                     builderr->scratchOne[scratchOneIdx] = Ed;
                 }
                 if (wC == 'n') {
                     builderr->scratchOne[scratchOneIdx] = En;
                 }
                 if (wC == 'r') {
                     builderr->scratchOne[scratchOneIdx] = Er;
                 }
            case 'F':
                 breakdownIdx++;
                 wC = breakdown->associations[breakdownIdx];
                 if (wC == 'o') {
                     breakdownIdx++;
                     wC = breakdown->associations[breakdownIdx];
                     if (wC == 'r' && wCPeek != 'm') {
                         builderr->scratchOne[scratchOneIdx] = For_;
                     }
                     if (wC == 'r' && wCPeek == 'm') {
                         builderr->scratchOne[scratchOneIdx] = Form;
                     }
                 }
                 break;
            case 'I':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            builderr->scratchOne[scratchOneIdx] = Intra;
                        }
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = Inter;
                        }
                break;


            case 'M':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'a') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'g') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                    }
                    if (wC == 'n') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                    }
                    if (wC == 'i') {
                        builderr->scratchOne[scratchOneIdx] = Magni;
                    }
                }
                if (wC == 'i') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'l') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'l') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'i') {
                                builderr->scratchOne[scratchOneIdx] = Milli;
                            }
                        }
                    }
                    if (wC == 'c') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                    }
                    if (wC == 'r') {
                        builderr->scratchOne[scratchOneIdx] = Micro;
                    }
                }
                if (wC == 'u') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'l') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 't') {
                            builderr->scratchOne[scratchOneIdx] = Multi;
                        }
                    }
                }
                break;
            case 'P':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 's') {
                    if (wC == 'e') {
                        builderr->scratchOne[scratchOneIdx] = Pseudo;
                    }
                }
                break;
            case 'R':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'o') {
                                builderr->scratchOne[scratchOneIdx] = Retro;
                            }
                        }
                    }
                }
                break;

            case 'T':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'r') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'a') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'n') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                            if (wC == 's') {
                            builderr->scratchOne[scratchOneIdx] = Trans;
                            }
                break;
            case 'S':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'u') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'p') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'r') {
                            builderr->scratchOne[scratchOneIdx] = Super;
                }
                break;
            case 'U':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];

                    if (wC == 'd') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'e') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                        if (wC == 'r') {
                            builderr->scratchOne[scratchOneIdx] = Under;
                }
                break;

                default:
                perror("Uppers");
                break;
        }
    }
    int firstSize = sizeof(firsts) / sizeof(firsts[0]);



    if (islower(wC) == true)
    {
        for (int i = 0; i < firstSize; i++) {
            if (wC == firsts[i])
            {
                // This switch covers the lowercase morphemes only. I'm thinking
                // We should allow default to fall through to a second switch to
                // sift through, or a loop
                switch (wC)
                {
                    case 'a':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'l') {
                            builderr->scratchOne[scratchOneIdx] = al;
                        }
                        if (wC == 's') {
                            builderr->scratchOne[scratchOneIdx] = as;
                            scratchOneIdx++;
                        }
                        if (wC == 't') {
                            builderr->scratchOne[scratchOneIdx] = at;
                        }
                        if (wC == 'n') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                            if (wC == 't') {
                                breakdown++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'i') {
                                    builderr->scratchOne[scratchOneIdx] = anti;
                                }
                                if (wC == 'e') {
                                    builderr->scratchOne[scratchOneIdx] = ante;
                                }
                            }
                            if (wC == 'c') {
                                builderr->scratchOne[scratchOneIdx] = ance;
                            }
                            if (wC == 'd') {
                                builderr->scratchOne[scratchOneIdx] = and;
                            }
                        }
                        if (wC == 'b') {
                            builderr->scratchOne[scratchOneIdx] = able;
                            scratchOneIdx++;
                        }
                        break;
                    case 'c':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'd') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    builderr->scratchOne[scratchOneIdx] = cede;
                                }
                            }
                            if (wC == 's') {
                                builderr->scratchOne[scratchOneIdx] = cess;
                            }
                        }
                        if (wC == 'i') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'c') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'u') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'm') {
                                            builderr->scratchOne[scratchOneIdx] = circum;
                                        }
                                    }
                                }
                            }
                        }
                        if (wC == 'l') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'u') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'd') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'e') {
                                        builderr->scratchOne[scratchOneIdx] = clude;
                                    }
                                }
                            }
                        }
                        break;
                    case 'd':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'i') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    builderr->scratchOne[scratchOneIdx] = dict;
                                }
                            }
                        }
                    case 'e':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            builderr->scratchOne[scratchOneIdx] = ed;
                            scratchOneIdx++;
                        }
                        if (wC == 'n') {
                            builderr->scratchOne[scratchOneIdx] = en;
                        }
                        if (wC == 'r') {
                            builderr->scratchOne[scratchOneIdx] = er;
                            scratchOneIdx++;
                        }
                        break;
                    case 'f':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'o') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'r' && wCPeek != 'm') {
                                builderr->scratchOne[scratchOneIdx] = for_;
                            }
                            if (wC == 'r' && wCPeek == 'm') {
                                builderr->scratchOne[scratchOneIdx] = form;
                            }
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
                    case 'l':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'y') {
                            builderr->scratchOne[scratchOneIdx] = ly;
                            scratchOneIdx++;
                        }
                        if (wC == 'e') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 's') {
                                builderr->scratchOne[scratchOneIdx] = less;
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
                    case 'n':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = ness;
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
                    case 'r':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            builderr->scratchOne[scratchOneIdx] = re;
                            scratchOneIdx++;
                        }
                        break;
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

                            if (wC == 'a') {
                                builderr->scratchTwo[scratchOneIdx] = that;
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

            switch (wC) {
                case 'a':
                    if (wC == 'b') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'l') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                builderr->scratchOne[scratchOneIdx] = able;
                            }
                        }
                    }
                    //if (wC == )

                    break;
                case 'c':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'i') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'u') {
                                    builderr->scratchOne[scratchOneIdx] = circum;
                                }
                            }
                        }
                    }
                case 's':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'u') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'p') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'r') {
                                    builderr->scratchOne[scratchOneIdx] = super;
                                }
                            }
                        }
                    }

                case 'u':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'n') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'r') {
                                    builderr->scratchOne[scratchOneIdx] = under;
                                }
                            }
                        }
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

