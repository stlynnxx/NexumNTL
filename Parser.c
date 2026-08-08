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
    int cols  = sizeof(valuesMatrix[0] / sizeof(valuesMatrix[0][0]);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (valuesMatrix[i][j]) == searchTerm){
                return valuesMatrix[i][j];}
        }
    }

}
char look(char compArray[], char letter) {
    int counter = 0;


    if (counter <= 26) {
        compArray[0] = valuesMatrix[letter][counter];
        counter++;
    }
    return compArray[0];
}
char increment(int breakdownIdx, char wC, Breakdown *breakdown, int direction) {

    if (direction == 1) {
        breakdownIdx++;
        wC = breakdown->memoryKey[breakdownIdx];
    }
    if (direction == 2) {
        breakdownIdx++;
        wC = breakdown->associations[breakdownIdx];
    }
    if (direction == 3) {
        breakdownIdx++;
        wC = breakdown->workingAssociators[breakdownIdx];
    }
    switch (direction) {
        case 1:
            breakdownIdx++;
            wC = breakdown->memoryKey[breakdownIdx];
            break;
        case 2:
            breakdownIdx++;
            wC = breakdown->associations[breakdownIdx];
            break;
        case 3:
            breakdownIdx++;
            wC = breakdown->workingAssociators[breakdownIdx];
            break;
        default:
            break;
    }
    return wC;
}
char alpha[30] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
    "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
    "U", "V", "W", "X", "Y", "Z"
};

 void match(char buffer[100]) {
     char select = buffer[0];

     char workSelect = toupper(select);

     size_t rowSize;



     if (isalnum(select)) {

         switch (workSelect) {

             case 'A':

                 rowSize = sizeof(valuesMatrix[A]);

                 break;

                 case 'B':

                 rowSize = sizeof(valuesMatrix[B]);

                 break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C]);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D]);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E]);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F]);





        }
        size_t rowSize = sizeof(valuesMatrix[select]);

    }


}


int newCheck(int breakdownIdx, int scratchOneIdx, char *writeTarget, builder *builderr, Breakdown *breakdown, char wC) {
    int encodedScratch;
    int peekIdx = breakdownIdx + 1;
    char wCPeek = breakdown->associations[peekIdx];
    char compArray[800]; // This is a placeholder size that needs changed
    char compBuffer[100];
    char buffer[100];
    char comp; // Comp is sort of the opposite of wC, it is what wC is being compared against from the matrix
    size_t compSize;
    size_t sizeX;
    size_t sizeY;
    bool isAssociator = false;
    bool delimCheck = false;
    compArray[0] = look(compArray, wC); // At this point we should have all of the row associated with the given wC loaded into compArray
    compSize = sizeof(compArray) / sizeof(compArray[0]); // This gives us the number of entries within compArray

    if (isupper(wC)) {
        builderr->assocScratch[scratchOneIdx] = wC;
        scratchOneIdx++;
        for (int i = 0; i < compSize; i++) {
            if (wC == compArray[i]) {
                if (wC || compArray[i] == COMMA) {
                    // the comma is the delimiter, so this should denote the end of a word/entry
                    delimCheck = true;

                }
                buffer[0] = compArray[i];
                // We need to figure out how to determine direction for this call
                wC = increment(breakdownIdx, wC, &*breakdown,2);


            }
            if (wC != compArray[i]) {
                perror("Parser->newCheck failure");
                exit(EXIT_FAILURE);
            }
            if (delimCheck == true) {
                sizeX = sizeof(buffer) / sizeof(buffer[0]);
                for (int i = 0; i < sizeX; i++) {
                    compArray[i] = compBuffer[i];
                }
                sizeY = sizeof(compBuffer) / sizeof(compBuffer[0]);
                if (sizeX != sizeY) {
                    perror("Size x y error");
                    exit(EXIT_FAILURE);
                }
                if (sizeX == sizeY) {
                    // Morpheme match

                }



            }
            // If we go through letter by letter manually until a 'soft match', can we not then confirm it by comparing it to the entry size?
            // if i == wC, append to buffer until soft token match, then hard confirm via buffer size vs comp size?
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
                                writeTarget[scratchOneIdx] = valuesMatrix[A][0];

                            }
                        }
                        break;
                    case 'l':
                        writeTarget[scratchOneIdx] = valuesMatrix[A][1];
                        break;
                    case 's':
                        writeTarget[scratchOneIdx] = valuesMatrix[A][2];
                        break;
                    case 't':
                        writeTarget[scratchOneIdx] = valuesMatrix[A][3];
                        break;
                    case 'n':
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];

                        if (wC == 'd') {
                            writeTarget[scratchOneIdx] = valuesMatrix[A][6];
                        }
                        if (wC == 't') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];

                            if (wC == 'i') {
                                writeTarget[scratchOneIdx] = valuesMatrix[A][9];
                            }
                            if (wC == 'e') {
                                writeTarget[scratchOneIdx] = valuesMatrix[A][7];
                            }
                        }
                        if (wC == 'c') {
                            breakdownIdx++;
                            wC = breakdown->associations[breakdownIdx];
                            if (wC == 'e') {
                                writeTarget[scratchOneIdx] = valuesMatrix[A][4];
                            }
                        }
                }
                        break;
                } // EOS A
             // Ends case 'A'
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
                                writeTarget[scratchOneIdx] = valuesMatrix[C][0];
                            }
                        }
                        if (wC == 's') {
                            writeTarget[scratchOneIdx] = valuesMatrix[C][1];
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
                                        writeTarget[scratchOneIdx] = valuesMatrix[C][2];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[C][3];
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
                            writeTarget[scratchOneIdx] = valuesMatrix[D][0];
                        }
                    }
                }
                break;
            case 'E':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                switch (wC) {
                    case 'd':
                        writeTarget[scratchOneIdx] = valuesMatrix[E][0];
                        break;
                    case 'r':
                        writeTarget[scratchOneIdx] = valuesMatrix[4][1];
                        break;
                    case 'n':
                        writeTarget[scratchOneIdx] = valuesMatrix[4][2];
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
                        writeTarget[scratchOneIdx] = valuesMatrix[F][0];
                    }
                    if (wC == 'r' && wCPeek == 'm') {
                        writeTarget[scratchOneIdx] = valuesMatrix[F][1];
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
                                writeTarget[scratchOneIdx] = valuesMatrix[G][0];
                            }
                        }
                    }

                }
                break;
            case 'H':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'e') {
                    writeTarget[scratchOneIdx] = valuesMatrix[H][0];
                }
                break;
            case 'I':
                breakdownIdx++;
                wC = breakdown->associations[breakdownIdx];
                if (wC == 'n' && wCPeek != 'g') {
                    writeTarget[scratchOneIdx] = valuesMatrix[I][0];
                }
                if (wC == 'n' && wCPeek == 'g') {
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'g') {
                        writeTarget[scratchOneIdx] = valuesMatrix[I][1];
                    }
                    if (wC == 's') {
                        writeTarget[scratchOneIdx] = valuesMatrix[I][2];
                    }

                    if (wC == 't') {
                        breakdownIdx++;
                        wC = breakdown->associations[breakdownIdx];
                        if (wC == 'r') {
                            writeTarget[scratchOneIdx] = valuesMatrix[I][0];
                        }
                        if (wC == 'e') {
                            writeTarget[scratchOneIdx] = valuesMatrix[I][1];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[J][0];
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
                                writeTarget[scratchOneIdx] = valuesMatrix[L][0];
                            }
                        }
                    }
                    if (wC == 'y') {
                        writeTarget[scratchOneIdx] = valuesMatrix[L][1];
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
                                        writeTarget[scratchOneIdx] = valuesMatrix[M][0];
                                    }
                                }
                            }
                            if (wC == 'r') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];
                                if (wC == 'k') {
                                    writeTarget[scratchOneIdx] = valuesMatrix[M][1];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[M][2];
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
                                        writeTarget[scratchOneIdx] = valuesMatrix[M][3];
                                    }
                                }
                            }
                            if (wC == 'c') {
                                breakdownIdx++;
                                wC = breakdown->associations[breakdownIdx];

                                if (wC == 'r') {
                                    writeTarget[scratchOneIdx] = valuesMatrix[M][4];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[M][5];
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
                                writeTarget[scratchOneIdx] == valuesMatrix[N][0];
                            }
                        }
                    }
                    break; // End of N
                    case 'O':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    switch (wC) {
                        case 'f':
                            writeTarget[scratchOneIdx] = valuesMatrix[O][0];
                            break;
                        case 'n':
                            writeTarget[scratchOneIdx] = valuesMatrix[O][1];
                            break;
                        case 'r':
                            writeTarget[scratchOneIdx] = valuesMatrix[O][2];
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
                            writeTarget[scratchOneIdx] = valuesMatrix[P][0];
                        }
                    }
                    break;
                    case 'R':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'e' && wCPeek != 'e') {
                        writeTarget[scratchOneIdx] = valuesMatrix[R][0];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[R][1];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[S][0];
                                }
                            }
                        }
                    }
                    break;


                    case 'T':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'o') {
                        writeTarget[scratchOneIdx] = valuesMatrix[T][0];
                    }
                    if (wC == 'h' && wCPeek != 'e') {
                        writeTarget[scratchOneIdx] = valuesMatrix[T][1];
                    }
                    if (wC == 'h' && wCPeek == 'e') {
                        writeTarget[scratchOneIdx] = valuesMatrix[T][2];
                    }
                    if (wC == 'h' && wCPeek == 'a') {
                        writeTarget[scratchOneIdx] = valuesMatrix[T][3];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[T][4];
                                }
                            }
                        }
                    }
                    break;
                    case 'U':
                    breakdownIdx++;
                    wC = breakdown->associations[breakdownIdx];
                    if (wC == 'n' && wCPeek != 'd') {
                        builderr->assocScratch[scratchOneIdx] = valuesMatrix[U][0];
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
                                    writeTarget[scratchOneIdx] = valuesMatrix[U][1];
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
                                writeTarget[scratchOneIdx] = valuesMatrix[V][0];
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
                                writeTarget[scratchOneIdx] = valuesMatrix[W][0];
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
                                                // This will need to come from a hex values array and not the values matrix
                                                writeTarget[scratchOneIdx] = hex_matrix[A][0];
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
    char wC; // Similar to wC in Lexer, is the current working character
    bool run = true;
    // wC = breakdown->associations[breakdownIdx]; // This sets the current working character
    char *writeTarget = NULL; // the array being written to within checker

    for (int j = 0; j < memKeySize; j++) { // This loops through the memKeys
        wC = breakdown->memoryKey[breakdownIdx]; // Setting wC for this logic block


        wC = increment(breakdownIdx, wC, breakdown, 1);

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
        wC = increment(breakdownIdx, wC, breakdown, 1);
        writeTarget = builderr->memKeyScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->memKey[breakdownIdx] = writeTarget[breakdownIdx]; // We need to replace breakdownIdx

        wC = increment(breakdownIdx, wC, breakdown, 1);
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
        wC = increment(breakdownIdx, wC, breakdown, 2);
        writeTarget = builderr->assocScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->assoc[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace BreakdownIDX

        /* This was originally updating wC from memoryKey before increment; i've implemented increment with 2 for association because
         I think that the memoryKey was a mistake */
        wC = increment(breakdownIdx, wC, breakdown, 2);
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
        wC = increment(breakdownIdx, wC, breakdown, 3);
        writeTarget = builderr->associatorScratch; // Assigns write target
        breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        export_->associators[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace breakdownIdx
        wC = increment(breakdownIdx, wC, breakdown, 3);
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

