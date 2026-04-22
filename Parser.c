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
                switch (wC) {
                    case 'b':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'l') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                builderr->scratchOne[scratchOneIdx] = Able;
                            }
                        }
                        break;
                    case 'l':
                        builderr->scratchOne[scratchOneIdx] = Al;
                        break;
                    case 's':
                        builderr->scratchOne[scratchOneIdx] = As;
                        break;
                    case 't':
                        builderr->scratchOne[scratchOneIdx] = At;
                        break;
                    case 'n':
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
                                builderr->scratchOne[scratchOneIdx] = Cede;
                            }
                        }
                        if (wC == 's') {
                            builderr->scratchOne[scratchOneIdx] = Cess;
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
                                        builderr->scratchOne[scratchOneIdx] = Circum;
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
                                    builderr->scratchOne[scratchOneIdx] = Clude;
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
                            builderr->scratchOne[scratchOneIdx] = Dict;
                        }
                    }
                }
                break;
            case 'E':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'd':
                        builderr->scratchOne[scratchOneIdx] = Ed;
                        break;
                    case 'r':
                        builderr->scratchOne[scratchOneIdx] = Er;
                        break;
                    case 'n':
                        builderr->scratchOne[scratchOneIdx] = En;
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
                        builderr->scratchOne[scratchOneIdx] = For_;
                    }
                    if (wC == 'r' && wCPeek == 'm') {
                        builderr->scratchOne[scratchOneIdx] = Form;
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
                                builderr->scratchOne[scratchOneIdx] = Gress;
                            }
                        }
                    }

                }
                break;
            case 'H':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    builderr->scratchOne[scratchOneIdx] = He;
                }
                break;
            case 'I':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n' && wCPeek != 'g') {
                    builderr->scratchOne[scratchOneIdx] = In;
                }
                if (wC == 'n' && wCPeek == 'g') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'g') {
                        builderr->scratchOne[scratchOneIdx] = Ing;
                    }
                    if (wC == 's') {
                        builderr->scratchOne[scratchOneIdx] = Is;
                    }

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
                                    builderr->scratchOne[scratchOneIdx] = Ject;
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
                                builderr->scratchOne[scratchOneIdx] = Less;
                            }
                        }
                    }
                    if (wC == 'y') {
                        builderr->scratchOne[scratchOneIdx] = Ly;
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
                            }
                            if (wC == 'n') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                            }
                            if (wC == 'i') {
                                builderr->scratchOne[scratchOneIdx] = Magni;
                            }
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'k') {
                                    builderr->scratchOne[scratchOneIdx] = Mark;
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
                                    builderr->scratchOne[scratchOneIdx] = Ment;
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
                            break;
                        case 'u':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'l') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    builderr->scratchOne[scratchOneIdx] = Multi;
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
                                builderr->scratchOne[scratchOneIdx] == Ness;
                            }
                        }
                    }
                    break;
                    case 'O':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    switch (wC) {
                        case 'f':
                            builderr->scratchOne[scratchOneIdx] = Of;
                            break;
                        case 'n':
                            builderr->scratchOne[scratchOneIdx] = On;
                            break;
                        case 'r':
                            builderr->scratchOne[scratchOneIdx] = Or;
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
                            builderr->scratchOne[scratchOneIdx] = Pseudo;
                        }
                    }
                    break;
                    case 'R':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e' && wCPeek != 'e') {
                        builderr->scratchOne[scratchOneIdx] = Re;
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
                                    builderr->scratchOne[scratchOneIdx] = Retro;
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
                                    builderr->scratchOne[scratchOneIdx] = Super;
                                }
                            }
                        }
                    }
                    break;


                    case 'T':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'o') {
                        builderr->scratchOne[scratchOneIdx] = To;
                    }
                    if (wC == 'h' && wCPeek != 'e') {
                        builderr->scratchOne[scratchOneIdx] = Th;
                    }
                    if (wC == 'h' && wCPeek == 'e') {
                        builderr->scratchOne[scratchOneIdx] = The;
                    }
                    if (wC == 'h' && wCPeek == 'a') {
                        builderr->scratchOne[scratchOneIdx] = That;
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
                                    builderr->scratchOne[scratchOneIdx] = Trans;
                                }
                            }
                        }
                    }
                    break;
                    case 'U':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'n' && wCPeek != 'd') {
                        builderr->scratchOne[scratchOneIdx] = Un;
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
                                    builderr->scratchOne[scratchOneIdx] = Under;
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
                                builderr->scratchOne[scratchOneIdx] = Vert;
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
                                builderr->scratchOne[scratchOneIdx] = With;
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
                if (wC == firsts[i]) {                                                {
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
                                            builderr->scratchOne[scratchOneIdx] = able;
                                        }
                                    }
                                    break;
                                case 'l':
                                    builderr->scratchOne[scratchOneIdx] = al;
                                    break;
                                case 's':
                                    builderr->scratchOne[scratchOneIdx] = as;
                                    break;
                                case 't':
                                    builderr->scratchOne[scratchOneIdx] = at;
                                    break;
                                case 'n':
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'd') {
                                        builderr->scratchOne[scratchOneIdx] = and;
                                    }
                                    if (wC == 't') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'i') {
                                            builderr->scratchOne[scratchOneIdx] = anti;
                                        }
                                    }
                                    if (wC == 'e') {
                                        builderr->scratchOne[scratchOneIdx] = ante;
                                    }
                                    if (wC == 'c') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'e') {
                                            builderr->scratchOne[scratchOneIdx] = ance;
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
                                            builderr->scratchOne[scratchOneIdx] = cede;
                                        }
                                    }
                                    if (wC == 's') {
                                        builderr->scratchOne[scratchOneIdx] = cess;
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
                                                    builderr->scratchOne[scratchOneIdx] = circum;
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
                                                builderr->scratchOne[scratchOneIdx] = clude;
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
                                        builderr->scratchOne[scratchOneIdx] = dict;
                                    }
                                }
                            }
                            break;
                        case 'e':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            switch (wC) {
                                case 'd':
                                    builderr->scratchOne[scratchOneIdx] = ed;
                                    break;
                                case 'n':
                                    builderr->scratchOne[scratchOneIdx] = en;
                                    break;
                                case 'r':
                                    builderr->scratchOne[scratchOneIdx] = er;
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
                                    builderr->scratchOne[scratchOneIdx] = for_;
                                }
                                if (wC == 'r' && wCPeek == 'm') {
                                    builderr->scratchOne[scratchOneIdx] = form;
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
                                            builderr->scratchOne[scratchOneIdx] = gress;
                                        }
                                    }
                                }
                            }
                            break;
                        case 'h':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                builderr->scratchOne[scratchOneIdx] = he;
                            }
                            break;
                        case 'i':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'n' && wCPeek != 't' | wCPeek != 'g') {
                                builderr->scratchOne[scratchOneIdx] = in;
                            }
                            if (wC == 'n' && wCPeek == 's') {
                                builderr->scratchOne[scratchOneIdx] = is;
                                scratchOneIdx++;
                            }
                            if (wC == 'n' && wCPeek == 't') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    builderr->scratchOne[scratchOneIdx] = inter;
                                }
                                if (wC == 'r') {
                                    builderr->scratchOne[scratchOneIdx] = intra;
                                }
                            }
                            if (wC == 'n' && wCPeek == 'g') {
                                builderr->scratchOne[scratchOneIdx] = ing;
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
                                        builderr->scratchOne[scratchOneIdx] = ject;
                                    }
                                }
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
                                                builderr->scratchOne[scratchOneIdx] = magni;
                                            }
                                        }
                                    }
                                    if (wC == 'r') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'k') {
                                            builderr->scratchOne[scratchOneIdx] = mark;
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
                                            builderr->scratchOne[scratchOneIdx] = ment;
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
                                                builderr->scratchOne[scratchOneIdx] = micro;
                                            }
                                        }
                                        if (wC == 'l') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'l') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'i') {
                                                    builderr->scratchOne[scratchOneIdx] = milli;
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
                                                builderr->scratchOne[scratchOneIdx] = multi;
                                            }
                                        }
                                    }
                                    break;
                                    break;
                            } // EOS M                                   break; // Ends case m
                        case 'n':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'd') {
                                builderr->scratchOne[scratchOneIdx] = nd;
                            }
                            if (wC == 'e') {
                                builderr->scratchOne[scratchOneIdx] = ness;
                                scratchOneIdx++;
                            }
                            break;
                        case 'o':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            switch (wC) {
                                case 'f':
                                    builderr->scratchOne[scratchOneIdx] = of;
                                    break;
                                case 'r':
                                    builderr->scratchOne[scratchOneIdx] = or;
                                    break;
                                case 'n':
                                    builderr->scratchOne[scratchOneIdx] = on;
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
                                builderr->scratchOne[scratchOneIdx] = re;
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
                                            builderr->scratchOne[scratchOneIdx] = retro;
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
                                            builderr->scratchOne[scratchOneIdx] = super;
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
                                    builderr->scratchOne[scratchOneIdx] = to;
                                    scratchOneIdx++;
                                    break;
                                case 'i':
                                    builderr->scratchTwo[scratchOneIdx] = tion;
                                    scratchOneIdx++;
                                    break;
                                case 'h':
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
                                            builderr->scratchOne[scratchOneIdx] = circum;
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
                                            builderr->scratchOne[scratchOneIdx] = super;
                                        }
                                    }
                                }
                            }
                            break;
                        case 'u':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'n' && wCPeek != 'd') {
                                builderr->scratchOne[scratchOneIdx] = un;
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
                                            builderr->scratchOne[scratchOneIdx] = under;
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
                                        builderr->scratchOne[scratchOneIdx] = vert;
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
                                        builderr->scratchOne[scratchOneIdx] = with;
                                    }
                                }
                            }
                            break;
                    } // EOS Main
                    return wC;
                }

                }
            }
        }
    }
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
    if (isalnum(wC)) {
        builderr->scratchOne[scratchOneIdx] = wC;
        scratchOneIdx++;
    }
    if (wC == NAMETOKEN) {
        if (firstNameTokenCheck == true) {
            // This where we will need to repeat some logic
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

