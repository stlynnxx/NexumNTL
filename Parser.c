//
// Created by steviexx on 3/31/26.
//

#include "Parser.h"
#include "Lexer.h"
#include "SourceGenerator.h"
#include "SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>



typedef struct {
    char assocScratch[80];
    char associatorScratch[80];
    char memKeyScratch[80];
} builder;

// int workIdx = breakdownIdx + 1;


// This will be for checking if a given search term is within the values matrix
char valuesSearch (char searchTerm[80]) {
    int rows = 26;
    int cols  = sizeof(values_matrix[0] / sizeof(values_matrix[0][0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (values_matrix[i][j]) == searchTerm){
                return values_matrix[i][j];}
        }
    }

}
int checker(int breakdownIdx, int scratchOneIdx, char *writeTarget, builder *builderr, Breakdown *breakdown, char wC) {
    int encodedScratch;
    int peekIdx = breakdownIdx + 1;
    char wCPeek = breakdown->associations[peekIdx];
    bool isAssociator = false;

    if (isupper(wC)) {
        builderr->assocScratch[scratchOneIdx] = wC;
        scratchOneIdx++;
        switch (wC) {
            case 'A':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'b':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'l') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                encodedScratch = valuesSearch("Able");
                                writeTarget[scratchOneIdx] = Able;

                            }
                        }
                        break;
                    case 'l':
                        writeTarget[scratchOneIdx] = Al;
                        break;
                    case 's':
                        writeTarget[scratchOneIdx] = As;
                        break;
                    case 't':
                        writeTarget[scratchOneIdx] = At;
                        break;
                    case 'n':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'd') {
                            writeTarget[scratchOneIdx] = And;
                        }
                        if (wC == 't') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                            if (wC == 'i') {
                                writeTarget[scratchOneIdx] = Anti;
                            }
                            if (wC == 'e') {
                                writeTarget[scratchOneIdx] = Ante;
                            }
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    writeTarget[scratchOneIdx] = Ance;
                                }
                            }
                        }
                        break;
                } // EOS A
                break; // Ends case 'A'
            case 'C':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'e':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                writeTarget[scratchOneIdx] = Cede;
                            }
                        }
                        if (wC == 's') {
                            writeTarget[scratchOneIdx] = Cess;
                        }
                        break;
                    case 'i':
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
                                        writeTarget[scratchOneIdx] = Circum;
                                    }
                                }
                            }
                        }
                        break;
                    case 'l':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'u') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'd') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    writeTarget[scratchOneIdx] = Clude;
                                }
                            }
                        }
                        break;
                } // EOS C
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
                            writeTarget[scratchOneIdx] = Dict;
                        }
                    }
                }
                break;
            case 'E':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'd':
                        writeTarget[scratchOneIdx] = Ed;
                        break;
                    case 'r':
                        writeTarget[scratchOneIdx] = Er;
                        break;
                    case 'n':
                        writeTarget[scratchOneIdx] = En;
                        break;
                } // EOS E
                break;
            case 'F':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'o') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'r' && wCPeek != 'm') {
                        writeTarget[scratchOneIdx] = For_;
                    }
                    if (wC == 'r' && wCPeek == 'm') {
                        writeTarget[scratchOneIdx] = Form;
                    }
                }
                break;
            case 'G':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'r') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 's') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 's') {
                                writeTarget[scratchOneIdx] = Gress;
                            }
                        }
                    }

                }
                break;
            case 'H':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    writeTarget[scratchOneIdx] = He;
                }
                break;
            case 'I':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n' && wCPeek != 'g') {
                    writeTarget[scratchOneIdx] = In;
                }
                if (wC == 'n' && wCPeek == 'g') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'g') {
                        writeTarget[scratchOneIdx] = Ing;
                    }
                    if (wC == 's') {
                        writeTarget[scratchOneIdx] = Is;
                    }

                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            writeTarget[scratchOneIdx] = Intra;
                        }
                        if (wC == 'e') {
                            writeTarget[scratchOneIdx] = Inter;
                        }
                        break;
                        case 'J':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    writeTarget[scratchOneIdx] = Ject;
                                }
                            }
                        }
                    }
                    break;
                    case 'L':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 's') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 's') {
                                writeTarget[scratchOneIdx] = Less;
                            }
                        }
                    }
                    if (wC == 'y') {
                        writeTarget[scratchOneIdx] = Ly;
                    }
                    break;
                    case 'M':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    switch (wC) {
                        case 'a':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'g') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];

                                if (wC == 'n') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];

                                    if (wC == 'i') {
                                        writeTarget[scratchOneIdx] = Magni;
                                    }
                                }
                            }
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'k') {
                                    writeTarget[scratchOneIdx] = Mark;
                                }
                            }
                            break;
                        case 'e':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'n') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    writeTarget[scratchOneIdx] = Ment;
                                }
                            }
                            break;
                        case 'i':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'l') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'l') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'i') {
                                        writeTarget[scratchOneIdx] = Milli;
                                    }
                                }
                            }
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];

                                if (wC == 'r') {
                                    writeTarget[scratchOneIdx] = Micro;
                                }
                            }
                            break;
                        case 'u':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'l') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    writeTarget[scratchOneIdx] = Multi;
                                }
                            }
                            break;
                    } // EOS M
                    break;
                    case 'N':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 's') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 's') {
                                writeTarget[scratchOneIdx] == Ness;
                            }
                        }
                    }
                    break;
                    case 'O':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    switch (wC) {
                        case 'f':
                            writeTarget[scratchOneIdx] = Of;
                            break;
                        case 'n':
                            writeTarget[scratchOneIdx] = On;
                            break;
                        case 'r':
                            writeTarget[scratchOneIdx] = Or;
                            break;
                    } // EOS O
                    break;


                    case 'P':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 's') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'e') {
                            writeTarget[scratchOneIdx] = Pseudo;
                        }
                    }
                    break;
                    case 'R':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e' && wCPeek != 'e') {
                        writeTarget[scratchOneIdx] = Re;
                    }
                    if (wC == 'e' && wCPeek == 'e') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 't') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'o') {
                                    writeTarget[scratchOneIdx] = Retro;
                                }
                            }
                        }
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
                                    writeTarget[scratchOneIdx] = Super;
                                }
                            }
                        }
                    }
                    break;


                    case 'T':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'o') {
                        writeTarget[scratchOneIdx] = To;
                    }
                    if (wC == 'h' && wCPeek != 'e') {
                        writeTarget[scratchOneIdx] = Th;
                    }
                    if (wC == 'h' && wCPeek == 'e') {
                        writeTarget[scratchOneIdx] = The;
                    }
                    if (wC == 'h' && wCPeek == 'a') {
                        writeTarget[scratchOneIdx] = That;
                    }
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
                                    writeTarget[scratchOneIdx] = Trans;
                                }
                            }
                        }
                    }
                    break;
                    case 'U':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'n' && wCPeek != 'd') {
                        builderr->assocScratch[scratchOneIdx] = Un;
                    }
                    if (wC == 'n' && wCPeek == 'd') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'd') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'r') {
                                    writeTarget[scratchOneIdx] = Under;
                                }
                            }
                        }
                    }
                    break;
                    case 'V':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 't') {
                                writeTarget[scratchOneIdx] = Vert;
                            }
                        }
                    }
                    break;
                    case 'W':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'i') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 't') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'h') {
                                writeTarget[scratchOneIdx] = With;
                            }
                        }
                    }
                    default:
                    perror("Uppers");
                    break;
                } // EOS Main
        }
        int firstSize = sizeof(firsts) / sizeof(firsts[0]);
        if (islower(wC) == true) {
            for (int i = 0; i < firstSize; i++) {
                if (wC == firsts[i]) {
                    {
                        // This switch covers the lowercase morphemes only. I'm thinking
                        // We should allow default to fall through to a second switch to
                        // sift through, or a loop
                        switch (wC) {
                            case 'a':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'b':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'l') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'e') {
                                                writeTarget[scratchOneIdx] = able;
                                            }
                                        }
                                        break;
                                    case 'l':
                                        writeTarget[scratchOneIdx] = al;
                                        break;
                                    case 's':
                                        writeTarget[scratchOneIdx] = as;
                                        break;
                                    case 't':
                                        writeTarget[scratchOneIdx] = at;
                                        break;
                                    case 'n':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'd') {
                                            writeTarget[scratchOneIdx] = and;
                                        }
                                        if (wC == 't') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'i') {
                                                writeTarget[scratchOneIdx] = anti;
                                            }
                                        }
                                        if (wC == 'e') {
                                            writeTarget[scratchOneIdx] = ante;
                                        }
                                        if (wC == 'c') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'e') {
                                                writeTarget[scratchOneIdx] = ance;
                                            }
                                        }
                                        break;
                                } // EOS A
                                break;
                            case 'c':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'e':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'd') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'e') {
                                                writeTarget[scratchOneIdx] = cede;
                                            }
                                        }
                                        if (wC == 's') {
                                            writeTarget[scratchOneIdx] = cess;
                                        }
                                        break;
                                    case 'i':
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
                                                        writeTarget[scratchOneIdx] = circum;
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    case 'l':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'u') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'd') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'e') {
                                                    writeTarget[scratchOneIdx] = clude;
                                                }
                                            }
                                        }
                                        break;
                                } // EOS c
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
                                            writeTarget[scratchOneIdx] = dict;
                                        }
                                    }
                                }
                                break;
                            case 'e':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'd':
                                        writeTarget[scratchOneIdx] = ed;
                                        break;
                                    case 'n':
                                        writeTarget[scratchOneIdx] = en;
                                        break;
                                    case 'r':
                                        writeTarget[scratchOneIdx] = er;
                                        break;
                                } // EOS e
                                break;
                            case 'f':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'o') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'r' && wCPeek != 'm') {
                                        writeTarget[scratchOneIdx] = for_;
                                    }
                                    if (wC == 'r' && wCPeek == 'm') {
                                        writeTarget[scratchOneIdx] = form;
                                    }
                                }
                                break;
                            case 'g':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'r') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'e') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 's') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 's') {
                                                writeTarget[scratchOneIdx] = gress;
                                            }
                                        }
                                    }
                                }
                                break;
                            case 'h':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    writeTarget[scratchOneIdx] = he;
                                }
                                break;
                            case 'i':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'n' && wCPeek != 't' | wCPeek != 'g') {
                                    writeTarget[scratchOneIdx] = in;
                                }
                                if (wC == 'n' && wCPeek == 's') {
                                    writeTarget[scratchOneIdx] = is;
                                    scratchOneIdx++;
                                }
                                if (wC == 'n' && wCPeek == 't') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'e') {
                                        writeTarget[scratchOneIdx] = inter;
                                    }
                                    if (wC == 'r') {
                                        writeTarget[scratchOneIdx] = intra;
                                    }
                                }
                                if (wC == 'n' && wCPeek == 'g') {
                                    writeTarget[scratchOneIdx] = ing;
                                }
                                break;
                            case 'j':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'c') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 't') {
                                            writeTarget[scratchOneIdx] = ject;
                                        }
                                    }
                                }
                                break;
                            case 'l':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'y') {
                                    writeTarget[scratchOneIdx] = ly;
                                    scratchOneIdx++;
                                }
                                if (wC == 'e') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 's') {


                                        writeTarget[scratchOneIdx] = less;
                                    }
                                }
                                break;
                            case 'm':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'a':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'g') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'n') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'i') {
                                                    writeTarget[scratchOneIdx] = magni;
                                                }
                                            }
                                        }
                                        if (wC == 'r') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'k') {
                                                writeTarget[scratchOneIdx] = mark;
                                            }
                                        }
                                        break;
                                    case 'e':
                                        breakdown++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'n') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 't') {
                                                writeTarget[scratchOneIdx] = ment;
                                            }
                                        }
                                        break;
                                    case 'i':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'c') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'r') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'o') {
                                                    writeTarget[scratchOneIdx] = micro;
                                                }
                                            }
                                            if (wC == 'l') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'l') {
                                                    breakdownIdx++;
                                                    wC = breakdown->associations[breakdownIdx];
                                                    if (wC == 'i') {
                                                        writeTarget[scratchOneIdx] = milli;
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                    case 'u':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'l') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 't') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'i') {
                                                    writeTarget[scratchOneIdx] = multi;
                                                }
                                            }
                                        }
                                        break;

                                } // EOS M                                   break; // Ends case m
                            case 'n':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'd') {
                                    writeTarget[scratchOneIdx] = nd;
                                }
                                if (wC == 'e') {
                                    writeTarget[scratchOneIdx] = ness;
                                    scratchOneIdx++;
                                }
                                break;
                            case 'o':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'f':
                                        writeTarget[scratchOneIdx] = of;
                                        break;
                                    case 'r':
                                        writeTarget[scratchOneIdx] = or;
                                        break;
                                    case 'n':
                                        writeTarget[scratchOneIdx] = on;
                                        break;
                                    default:
                                        perror("'o' switch");
                                        break;
                                } // EOS
                                break;
                            case 'r':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e' && wCPeek != 't') {
                                    writeTarget[scratchOneIdx] = re;
                                    scratchOneIdx++;
                                }
                                if (wC == 'e' && wCPeek == 't') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 't') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'r') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'o') {
                                                writeTarget[scratchOneIdx] = retro;
                                            }
                                        }
                                    }
                                }
                                break;
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
                                                writeTarget[scratchOneIdx] = super;
                                            }
                                        }
                                    }
                                }
                                break;
                            case 't':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                switch (wC) {
                                    case 'o':
                                        writeTarget[scratchOneIdx] = to;
                                        scratchOneIdx++;
                                        break;
                                    case 'i':
                                        writeTarget[scratchOneIdx] = tion;
                                        scratchOneIdx++;
                                        break;
                                    case 'h':
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'e') {
                                            writeTarget[scratchOneIdx] = the;
                                            scratchOneIdx++;
                                        }
                                        if (wC == 'a') {
                                            writeTarget[scratchOneIdx] = that;
                                            scratchOneIdx++;
                                        }
                                        break;
                                } // EOS
                                break;
                            default:
                                // if the currently examined char does not branch out
                                // to one of the shortened morphemes, then we fall through
                                // to the next check
                                printf("Falling through");
                                break;
                        } // EOS Main
                        switch (wC) {
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
                                                writeTarget[scratchOneIdx] = circum;
                                            }
                                        }
                                    }
                                }
                                break;
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
                                                writeTarget[scratchOneIdx] = super;
                                            }
                                        }
                                    }
                                }
                                break;
                            case 'u':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'n' && wCPeek != 'd') {
                                    writeTarget[scratchOneIdx] = un;
                                }
                                if (wC == 'n' && wCPeek == 'd') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'd') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'e') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'r') {
                                                writeTarget[scratchOneIdx] = under;
                                            }
                                        }
                                    }
                                }
                                break;
                            case 'v':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'r') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 't') {
                                            writeTarget[scratchOneIdx] = vert;
                                        }
                                    }
                                }
                                break;
                            case 'w':
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'i') {
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 't') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'h') {
                                            writeTarget[scratchOneIdx] = with;
                                        }
                                    }
                                }
                                break;
                        } // EOS Main
                        if (isalnum(wC)) {
                            writeTarget[scratchOneIdx] = wC;
                            scratchOneIdx++;
                        }
                        return breakdownIdx;
                    }
                }
            }
        }
    }


} // End Checker

void sendToSource() {
    nexcodeFlag = true;
    sgRun("Testing2.nexcode");

}


void parse(Breakdown *breakdown, Export *export_, builder *builderr) {
    free_morphemes fmorphemes;
    size_t assocSize; // size of the assoc array in the working struct
    size_t memKeySize; // size of mem key array in breakdown
    size_t associatorsSize;
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    bool closeBraceCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    int breakdownIdx = 0;
    int scratchOneIdx = 0;
    int workIdx = breakdownIdx + 1;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations[0]);
    memKeySize = sizeof(breakdown->memoryKey)/ sizeof(breakdown->memoryKey[0]);
    associatorsSize = sizeof(breakdown->workingAssociators)/ sizeof(breakdown->workingAssociators[0]);
    char wC; // Similar to wC in Lexer
    bool run = true;
    // wC = breakdown->associations[breakdownIdx]; // This sets the current working character
    char *writeTarget = NULL; // the array being written to within checker

    for (int j = 0; j < memKeySize; j++) { // This loops through the memKeys
        wC = breakdown->memoryKey[breakdownIdx]; // Setting wC for this logic block

        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }

            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->memKeyScratch[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
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
        wC = breakdown->memoryKey[breakdownIdx];
        writeTarget = builderr->memKeyScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->memKey[breakdownIdx] = writeTarget[breakdownIdx]; // We need to replace breakdownIdx

        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            j = memKeySize + 1;
        }
    } // End memkey loop
    breakdownIdx = 0;
    for (int i = 0; i < assocSize; i++) { // this loops through associations
        wC = breakdown->associations[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->assocScratch[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
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
        writeTarget = builderr->assocScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->assoc[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace BreakdownIDX

        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            i = assocSize + 1;
        }
    } // End associations loop
    breakdownIdx = 0;
    for (int k = 0; k < associatorsSize; k++) { // this loops through associators
        wC = breakdown->workingAssociators[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->associatorScratch[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
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
        wC = breakdown->workingAssociators[breakdownIdx];
        writeTarget = builderr->associatorScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->associators[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace breakdownIdx
        breakdownIdx++;
        wC = breakdown->workingAssociators[breakdownIdx];
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            closeBraceCheck = true;
            k = associatorsSize + 1;
        }
    } // End associators loop




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




}

void flag() {
    nexcodeFlag = true;
}


int prun() {
    // This establishes the struct instances and
    // passes them into parseAssocs
    Breakdown breakdown;
    Export export_;
    builder builderr;
    parse(&breakdown, &export_, &builderr);
    return 0;
}

