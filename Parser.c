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
    char assocScratch[80];
    char memKeyScratch[80];
} builder;

// int workIdx = breakdownIdx + 1;


char checker(int breakdownIdx, int scratchOneIdx, builder *builderr, Breakdown *breakdown, char wC) {
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
                                builderr->assocScratch[scratchOneIdx] = Able;
                            }
                        }
                        break;
                    case 'l':
                        builderr->assocScratch[scratchOneIdx] = Al;
                        break;
                    case 's':
                        builderr->assocScratch[scratchOneIdx] = As;
                        break;
                    case 't':
                        builderr->assocScratch[scratchOneIdx] = At;
                        break;
                    case 'n':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'd') {
                            builderr->assocScratch[scratchOneIdx] = And;
                        }
                        if (wC == 't') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                            if (wC == 'i') {
                                builderr->assocScratch[scratchOneIdx] = Anti;
                            }
                            if (wC == 'e') {
                                builderr->assocScratch[scratchOneIdx] = Ante;
                            }
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    builderr->assocScratch[scratchOneIdx] = Ance;
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
                                builderr->assocScratch[scratchOneIdx] = Cede;
                            }
                        }
                        if (wC == 's') {
                            builderr->assocScratch[scratchOneIdx] = Cess;
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
                                        builderr->assocScratch[scratchOneIdx] = Circum;
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
                                    builderr->assocScratch[scratchOneIdx] = Clude;
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
                            builderr->assocScratch[scratchOneIdx] = Dict;
                        }
                    }
                }
                break;
            case 'E':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'd':
                        builderr->assocScratch[scratchOneIdx] = Ed;
                        break;
                    case 'r':
                        builderr->assocScratch[scratchOneIdx] = Er;
                        break;
                    case 'n':
                        builderr->assocScratch[scratchOneIdx] = En;
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
                        builderr->assocScratch[scratchOneIdx] = For_;
                    }
                    if (wC == 'r' && wCPeek == 'm') {
                        builderr->assocScratch[scratchOneIdx] = Form;
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
                                builderr->assocScratch[scratchOneIdx] = Gress;
                            }
                        }
                    }

                }
                break;
            case 'H':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    builderr->assocScratch[scratchOneIdx] = He;
                }
                break;
            case 'I':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n' && wCPeek != 'g') {
                    builderr->assocScratch[scratchOneIdx] = In;
                }
                if (wC == 'n' && wCPeek == 'g') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'g') {
                        builderr->assocScratch[scratchOneIdx] = Ing;
                    }
                    if (wC == 's') {
                        builderr->assocScratch[scratchOneIdx] = Is;
                    }

                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            builderr->assocScratch[scratchOneIdx] = Intra;
                        }
                        if (wC == 'e') {
                            builderr->assocScratch[scratchOneIdx] = Inter;
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
                                    builderr->assocScratch[scratchOneIdx] = Ject;
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
                                builderr->assocScratch[scratchOneIdx] = Less;
                            }
                        }
                    }
                    if (wC == 'y') {
                        builderr->assocScratch[scratchOneIdx] = Ly;
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
                                builderr->assocScratch[scratchOneIdx] = Magni;
                            }
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'k') {
                                    builderr->assocScratch[scratchOneIdx] = Mark;
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
                                    builderr->assocScratch[scratchOneIdx] = Ment;
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
                                        builderr->assocScratch[scratchOneIdx] = Milli;
                                    }
                                }
                            }
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                            }
                            if (wC == 'r') {
                                builderr->assocScratch[scratchOneIdx] = Micro;
                            }
                            break;
                        case 'u':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'l') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 't') {
                                    builderr->assocScratch[scratchOneIdx] = Multi;
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
                                builderr->assocScratch[scratchOneIdx] == Ness;
                            }
                        }
                    }
                    break;
                    case 'O':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    switch (wC) {
                        case 'f':
                            builderr->assocScratch[scratchOneIdx] = Of;
                            break;
                        case 'n':
                            builderr->assocScratch[scratchOneIdx] = On;
                            break;
                        case 'r':
                            builderr->assocScratch[scratchOneIdx] = Or;
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
                            builderr->assocScratch[scratchOneIdx] = Pseudo;
                        }
                    }
                    break;
                    case 'R':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e' && wCPeek != 'e') {
                        builderr->assocScratch[scratchOneIdx] = Re;
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
                                    builderr->assocScratch[scratchOneIdx] = Retro;
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
                                    builderr->assocScratch[scratchOneIdx] = Super;
                                }
                            }
                        }
                    }
                    break;


                    case 'T':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'o') {
                        builderr->assocScratch[scratchOneIdx] = To;
                    }
                    if (wC == 'h' && wCPeek != 'e') {
                        builderr->assocScratch[scratchOneIdx] = Th;
                    }
                    if (wC == 'h' && wCPeek == 'e') {
                        builderr->assocScratch[scratchOneIdx] = The;
                    }
                    if (wC == 'h' && wCPeek == 'a') {
                        builderr->assocScratch[scratchOneIdx] = That;
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
                                    builderr->assocScratch[scratchOneIdx] = Trans;
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
                                    builderr->assocScratch[scratchOneIdx] = Under;
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
                                builderr->assocScratch[scratchOneIdx] = Vert;
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
                                builderr->assocScratch[scratchOneIdx] = With;
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
                                            builderr->assocScratch[scratchOneIdx] = able;
                                        }
                                    }
                                    break;
                                case 'l':
                                    builderr->assocScratch[scratchOneIdx] = al;
                                    break;
                                case 's':
                                    builderr->assocScratch[scratchOneIdx] = as;
                                    break;
                                case 't':
                                    builderr->assocScratch[scratchOneIdx] = at;
                                    break;
                                case 'n':
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'd') {
                                        builderr->assocScratch[scratchOneIdx] = and;
                                    }
                                    if (wC == 't') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'i') {
                                            builderr->assocScratch[scratchOneIdx] = anti;
                                        }
                                    }
                                    if (wC == 'e') {
                                        builderr->assocScratch[scratchOneIdx] = ante;
                                    }
                                    if (wC == 'c') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'e') {
                                            builderr->assocScratch[scratchOneIdx] = ance;
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
                                            builderr->assocScratch[scratchOneIdx] = cede;
                                        }
                                    }
                                    if (wC == 's') {
                                        builderr->assocScratch[scratchOneIdx] = cess;
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
                                                    builderr->assocScratch[scratchOneIdx] = circum;
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
                                                builderr->assocScratch[scratchOneIdx] = clude;
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
                                        builderr->assocScratch[scratchOneIdx] = dict;
                                    }
                                }
                            }
                            break;
                        case 'e':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            switch (wC) {
                                case 'd':
                                    builderr->assocScratch[scratchOneIdx] = ed;
                                    break;
                                case 'n':
                                    builderr->assocScratch[scratchOneIdx] = en;
                                    break;
                                case 'r':
                                    builderr->assocScratch[scratchOneIdx] = er;
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
                                    builderr->assocScratch[scratchOneIdx] = for_;
                                }
                                if (wC == 'r' && wCPeek == 'm') {
                                    builderr->assocScratch[scratchOneIdx] = form;
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
                                            builderr->assocScratch[scratchOneIdx] = gress;
                                        }
                                    }
                                }
                            }
                            break;
                        case 'h':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                builderr->assocScratch[scratchOneIdx] = he;
                            }
                            break;
                        case 'i':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'n' && wCPeek != 't' | wCPeek != 'g') {
                                builderr->assocScratch[scratchOneIdx] = in;
                            }
                            if (wC == 'n' && wCPeek == 's') {
                                builderr->assocScratch[scratchOneIdx] = is;
                                scratchOneIdx++;
                            }
                            if (wC == 'n' && wCPeek == 't') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'e') {
                                    builderr->assocScratch[scratchOneIdx] = inter;
                                }
                                if (wC == 'r') {
                                    builderr->assocScratch[scratchOneIdx] = intra;
                                }
                            }
                            if (wC == 'n' && wCPeek == 'g') {
                                builderr->assocScratch[scratchOneIdx] = ing;
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
                                        builderr->assocScratch[scratchOneIdx] = ject;
                                    }
                                }
                            }
                            break;
                        case 'l':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'y') {
                                builderr->assocScratch[scratchOneIdx] = ly;
                                scratchOneIdx++;
                            }
                            if (wC == 'e') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 's') {
                                    builderr->assocScratch[scratchOneIdx] = less;
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
                                                builderr->assocScratch[scratchOneIdx] = magni;
                                            }
                                        }
                                    }
                                    if (wC == 'r') {
                                        breakdownIdx++;
                                        wC = breakdown->associations[breakdownIdx];
                                        if (wC == 'k') {
                                            builderr->assocScratch[scratchOneIdx] = mark;
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
                                            builderr->assocScratch[scratchOneIdx] = ment;
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
                                                builderr->assocScratch[scratchOneIdx] = micro;
                                            }
                                        }
                                        if (wC == 'l') {
                                            breakdownIdx++;
                                            wC = breakdown->associations[breakdownIdx];
                                            if (wC == 'l') {
                                                breakdownIdx++;
                                                wC = breakdown->associations[breakdownIdx];
                                                if (wC == 'i') {
                                                    builderr->assocScratch[scratchOneIdx] = milli;
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
                                                builderr->assocScratch[scratchOneIdx] = multi;
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
                                builderr->assocScratch[scratchOneIdx] = nd;
                            }
                            if (wC == 'e') {
                                builderr->assocScratch[scratchOneIdx] = ness;
                                scratchOneIdx++;
                            }
                            break;
                        case 'o':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            switch (wC) {
                                case 'f':
                                    builderr->assocScratch[scratchOneIdx] = of;
                                    break;
                                case 'r':
                                    builderr->assocScratch[scratchOneIdx] = or;
                                    break;
                                case 'n':
                                    builderr->assocScratch[scratchOneIdx] = on;
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
                                builderr->assocScratch[scratchOneIdx] = re;
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
                                            builderr->assocScratch[scratchOneIdx] = retro;
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
                                            builderr->assocScratch[scratchOneIdx] = super;
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
                                    builderr->assocScratch[scratchOneIdx] = to;
                                    scratchOneIdx++;
                                    break;
                                case 'i':
                                    builderr->memKeyScratch[scratchOneIdx] = tion;
                                    scratchOneIdx++;
                                    break;
                                case 'h':
                                    breakdownIdx++;
                                    wC = breakdown->associations[breakdownIdx];
                                    if (wC == 'e') {
                                        builderr->assocScratch[scratchOneIdx] = the;
                                        scratchOneIdx++;
                                    }
                                    if (wC == 'a') {
                                        builderr->memKeyScratch[scratchOneIdx] = that;
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
                                            builderr->assocScratch[scratchOneIdx] = circum;
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
                                            builderr->assocScratch[scratchOneIdx] = super;
                                        }
                                    }
                                }
                            }
                            break;
                        case 'u':
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'n' && wCPeek != 'd') {
                                builderr->assocScratch[scratchOneIdx] = un;
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
                                            builderr->assocScratch[scratchOneIdx] = under;
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
                                        builderr->assocScratch[scratchOneIdx] = vert;
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
                                        builderr->assocScratch[scratchOneIdx] = with;
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

} // End Checker


void parse(Breakdown *breakdown, Export *export_, builder *builderr) {
    free_morphemes fmorphemes;
    int assocSize; // size of the assoc array in the working struct
    int memKeySize; // size of mem key array in breakdown
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    int assocCharCount = 0; // a working count of the current association being parsed
    int counts[2000]; // An array that stores the values that represent the amount of chars in each associaton
    int countsIdx = 0; // The index for appending to the above array
    int commaPoint;
    int breakdownIdx = 0;
    int scratchOneIdx = 0;
    int workIdx = breakdownIdx + 1;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations[0]);
    memKeySize = sizeof(breakdown->memoryKey)/ sizeof(breakdown->memoryKey[0]);
    char wC; // Similar to wC in Lexer
    bool run = true;
    // wC = breakdown->associations[breakdownIdx]; // This sets the current working character
    for (int j = 0; j < memKeySize; j++) {
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
        wC = checker(breakdownIdx, scratchOneIdx, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
    }
    for (int i = 0; i < assocSize; i++) {
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
        wC = checker(breakdownIdx, scratchOneIdx, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here

        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }

    }



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


    if (isalnum(wC)) {
        builderr->assocScratch[scratchOneIdx] = wC;
        scratchOneIdx++;
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
    Export export_;
    builder builderr;
    parse(&breakdown, &export_, &builderr);


    return 0;
}

