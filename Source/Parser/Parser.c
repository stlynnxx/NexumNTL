//
// Created by steviexx on 3/31/26.
//

#include "Parser.h"
#include "../Lexer/Lexer.h"
#include "../SourceGenerator/SourceGenerator.h"
#include "../SymbolTable/SymbolTable.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdatomic.h>
#include <stdlib.h>




// int workIdx = breakdownIdx + 1;


// This will be for checking if a given search term is within the values matrix
const char *valuesSearch(const char *searchTerm) {
    for (int i = 0; i < 26; i++) {
        int cols = sizeof(valuesMatrix[0]) / sizeof(valuesMatrix[0][0]);
        for (int j = 0; j < cols; j++) {
            const char *v = valuesMatrix[i][j];
            if (!v || strcmp(v, "NULL") == 0)
                continue;
            if (strcmp(v, searchTerm) == 0)
                return v;
        }
    }
    return NULL;
}

// Loads a row associated with a given wC into compArray
void look(ParserBuffers pbuffers, char wC) {
    for (int r  = 0; r < 26; r++) {
        if (toupper(wC) == *valuesMatrix[r][0]) {
            for (int ii = 0; ii < 14; ii++) {
                pbuffers.compArray.data[ii] = *valuesMatrix[r][ii];
            }
        }
    }
}

char increment(int breakdownIdx, char wC, Organizer *lexerbreakdown, int direction) {
    switch (direction) {
        case 0:
            breakdownIdx++;
            wC = lexerbreakdown->memoryKey.data[breakdownIdx];
            break;
        case 1:
            breakdownIdx++;
            wC = lexerbreakdown->associations.data[breakdownIdx];
            break;
        case 2:
            breakdownIdx++;
            wC = lexerbreakdown->workingAssociators.data[breakdownIdx];
            break;
        default:
            break;
    }
    return wC;
}
Export* exp_init() {
    Export *ex = malloc(sizeof(Export));
    ex->assoc.length = 0;
    ex->assoc.capacity = 0;
    ex->memKey.length = 0;
    ex->memKey.capacity = 0;
    ex->memKey.data = malloc(32);
    ex->assoc.data = malloc(64);
    ex->associators.data = malloc(32);
    if (!ex->memKey.data || !ex->assoc.data || !ex->associators.data) {
        perror("exp_init malloc failed");
        exit(EXIT_FAILURE);
    }
    return ex;
}
void exp_add(Export *export_, int flag) {
    switch (flag) {
        case 0:
            appendChar(export_, '\0');

    }

}

int encode(int foundI, int row, int scratchOneIdx, int flag) {
    Export *ex = exp_init();
    int encodeVal;
    // Encoded morpheme eventually needs to use a dynaminc buffer
    char *encodedMorpheme[10];
    encodedMorpheme[0] = encodedMatrix[row][foundI];
    // Should we have write target write to export at this point?
    // writeTarget[scratchOneIdx] = encodedMorpheme[0];
    switch (flag)
    {
        case 1:
            ex->memKey.data[scratchOneIdx] = *encodedMorpheme[0];
            if (!ex->memKey.data[scratchOneIdx]) {
                encodeVal = -1;
            }
            else {
                encodeVal = 1;
            }
            break;
        case 2:
            ex->assoc.data[scratchOneIdx] = *encodedMorpheme[0];
            if (!ex->assoc.data[scratchOneIdx]) {
                encodeVal = -1;
            }
            else {
                encodeVal = 1;
            }
            break;
        case 3:
            ex->associators.data[scratchOneIdx] = *encodedMorpheme[0];
            if (!ex->associators.data[scratchOneIdx]) {
                encodeVal = -1;
            }
            else {
                encodeVal = 1;
            }
        default:
            encodeVal = 0;
            break;
    }
    switch (encodeVal) {
        case 1:
            return 1;
            break;
        case 0:
            return 0;
            break;
        case -1:
            return -1;
            break;
        default:
            perror("Encode error in Parser");
            return -1;
            break;
    }

}


int verify(ParserBuffers *pbuffer, int rowSiZe, int row, int scratchOneIdx, int flag) {
    int encodeVal;
    int foundI;
    for (int i = 0; i <= rowSiZe; i++) {
        if (valuesMatrix[row][i] == NULL) return -1;
        if (strncmp(pbuffer->Buffers.data, valuesMatrix[row][i], strlen(pbuffer->Buffers.data)) == 0) {
            // match is found here
            foundI = i;
            encodeVal = encode(foundI, row, scratchOneIdx, flag);
        }
        else {
            // We need to catch the unverified morpheme here and then hand it over to usrmor
        }
    }
    switch (encodeVal) {
        case 1:
            return 1;
            break;
        case 0:
            perror("Encode error in Parser");
            return 0;
            break;
        case -1:
            perror("Encode error in Parser");
            return -1;
            break;
        default:
            perror("Encode error in Parser");
            return 0;
            break;
    }
}

//
int match(int scratchOneIdx, int flag, ParserBuffers *pbuffers) {
    size_t rowSize;
    const char select = pbuffers->Buffers.data[0];
    // const char compSelect =  pbuffers->compBuffer.data[0];
    char workSelect = toupper(select);
    int verifyReturn;
    if (isalnum(select))
    {
        switch (workSelect)
        {
            case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                verifyReturn = verify(pbuffers, rowSize, A, scratchOneIdx, flag);
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                verifyReturn = verify(pbuffers, rowSize, B, scratchOneIdx, flag);
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                verifyReturn = verify(pbuffers, rowSize, C, scratchOneIdx, flag);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                verifyReturn = verify(pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                verifyReturn = verify(pbuffers, rowSize, E, scratchOneIdx, flag);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                verifyReturn = verify(pbuffers, rowSize, F, scratchOneIdx, flag);
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                verifyReturn = verify(pbuffers, rowSize, G, scratchOneIdx, flag);
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                verifyReturn = verify(pbuffers, rowSize, H, scratchOneIdx, flag);
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                verifyReturn = verify(pbuffers, rowSize, I, scratchOneIdx, flag);
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                verifyReturn = verify(pbuffers, rowSize, J, scratchOneIdx, flag);
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                verifyReturn = verify(pbuffers, rowSize, K, scratchOneIdx, flag);
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                verifyReturn = verify(pbuffers, rowSize, L,scratchOneIdx, flag);
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                verifyReturn = verify(pbuffers, rowSize, M, scratchOneIdx, flag);
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                verifyReturn = verify(pbuffers, rowSize, N, scratchOneIdx, flag);
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                verifyReturn = verify(pbuffers, rowSize, O, scratchOneIdx, flag);
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                verifyReturn = verify(pbuffers, rowSize, P, scratchOneIdx, flag);
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                verifyReturn = verify(pbuffers, rowSize, Q, scratchOneIdx, flag);
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                verifyReturn = verify(pbuffers, rowSize, R, scratchOneIdx, flag);
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                verifyReturn = verify(pbuffers, rowSize, S, scratchOneIdx, flag);
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                verifyReturn = verify(pbuffers, rowSize, T, scratchOneIdx, flag);
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                verifyReturn = verify(pbuffers, rowSize, U, scratchOneIdx, flag);
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                verifyReturn = verify(pbuffers, rowSize, V, scratchOneIdx, flag);
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                verifyReturn = verify(pbuffers, rowSize, W, scratchOneIdx, flag);
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                verifyReturn = verify(pbuffers, rowSize, X, scratchOneIdx, flag);
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                verifyReturn = verify(pbuffers, rowSize, Y, scratchOneIdx, flag);
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                verifyReturn = verify(pbuffers, rowSize, Z, scratchOneIdx, flag);
                break;
            default:
                verifyReturn = -1;
                break;
        }
        switch (verifyReturn)
        {
            case 1:
                return 1;
                break;
            case 0:
                return 0;
                break;
            case -1:
                return -1;
                break;
            default:
                return -1;
                break;
        }

    }
    else {
        return -1;
    }
}



int newCheck(int breakdownIdx, int scratchOneIdx, int writeFlag, Builder *builderr, Organizer *lexerbreakdown, ParserBuffers *pbuffers,char wC, int incrementFlag) {
    bool delimCheck = false;
    int matchChk;
    look(*pbuffers, wC); // At this point we should have all of the row associated with the given wC loaded into compArray
    if (!pbuffers->compArray.data[0]) {
        perror("Empty pbuffer comparray in Parser newCheck");
        return -1;
    }
    if (isupper(wC)) {
        switch (incrementFlag) {
            case 0:
                builderr->memKeyScratch.data[scratchOneIdx] = wC;
                break;
            case 1:
                builderr->assocScratch.data[scratchOneIdx] = wC;
                break;
            case 2:
                builderr->associatorScratch.data[scratchOneIdx] = wC;
                break;
            default:
                perror("Default error, closing");
                return -1;
                break;
        }
        for (int i = 0; i < pbuffers->compArray.length; i++) {
            if (wC == pbuffers->compArray.data[i]) {
                if (wC || pbuffers->compArray.data[i] == COMMA) {
                    // the comma is the delimiter, so this should denote the end of a word/entry
                    delimCheck = true;
                }
                else {
                    return -1;
                }
                pbuffers->Buffers.data[i] = pbuffers->compArray.data[i];
                wC = increment(breakdownIdx, wC, &*lexerbreakdown,incrementFlag);
            }

            if (wC != pbuffers->compArray.data[i]) {
                perror("Parser->newCheck failure");
                return -1;
            }

            if (delimCheck == true) {
                // sizeX = sizeof(buffer) / sizeof(buffer[0]);
                for (int j = 0; j < pbuffers->Buffers.length; j++)
                {
                    pbuffers->compArray.data[i] = pbuffers->compBuffer.data[i];
                }
                // sizeY = sizeof(compBuffer) / sizeof(compBuffer[0]);
                if (pbuffers->Buffers.length != pbuffers->compBuffer.length) {
                    perror("Size x y error");
                    return -1;
                }
                if (pbuffers->Buffers.length == pbuffers->compBuffer.length) {
                    // Morpheme match
                    matchChk = match(scratchOneIdx, writeFlag, pbuffers);
                    switch (matchChk) {
                        case 1:
                            return 1;
                            break;
                        case 0:
                            return 0;
                            break;
                        case -1:
                            return -1;
                            break;
                        default:
                            return -1;
                            break;
                    }
                }

            } else {
                return -1;
            }
        }
    } else {
        return -1;
    }
    return -1;
}

void sendToSource() {
    bool flag = true;
    sgRun("Testing2.nexcode", flag);

}


void parse(Organizer *breakdown, Export *export_, Builder *builderr, ParserBuffers *pbuffers) {
    int writeFlag;
    int incrementFlag;
    // int checkChk;
    size_t assocSize; // size of the assoc array in the working struct
    size_t memKeySize; // size of mem key array in breakdown
    size_t associatorsSize;
    bool firstNameTokenCheck = false;
    bool secondNameTokenCheck = false;
    // bool closeBraceCheck = false;
    int breakdownIdx = 0;
    int scratchOneIdx = 0;
    int workIdx = breakdownIdx + 1;
    assocSize = sizeof(breakdown->associations) / sizeof(breakdown->associations.data[0]);
    memKeySize = sizeof(breakdown->memoryKey)/ sizeof(breakdown->memoryKey.data[0]);
    associatorsSize = sizeof(breakdown->workingAssociators)/ sizeof(breakdown->workingAssociators.data[0]);
    char wC; // Similar to wC in Lexer, is the current working character
    // wC = breakdown->associations[breakdownIdx]; // This sets the current working character
    char *writeTarget; // the array being written to within checker

    // This loops through the memKeys
    for (int j = 0; j < memKeySize; j++) { // This loops through the memKeys
        incrementFlag = 0;
        writeFlag = 0;
        wC = breakdown->memoryKey.data[breakdownIdx]; // Setting wC for this logic block
        wC = increment(breakdownIdx, wC, breakdown, incrementFlag);
        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->memKeyScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
                if (secondNameTokenCheck == true) {
                    firstNameTokenCheck = false;
                    secondNameTokenCheck = false;
                    // expNameTokenCheck = false;
                }
            }
        }
        else {
            perror("Parser nametoken error");
        }
        wC = increment(breakdownIdx, wC, breakdown, incrementFlag);
        writeTarget = builderr->memKeyScratch.data; // Assigns write target
        // The next line is what will be replaced with newCheck
        /// breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 1, builderr, breakdown, pbuffers, wC, incrementFlag); // wC should be at the end of whatever word was last parsed here
        
        export_->memKey.data[breakdownIdx] = writeTarget[breakdownIdx]; // We need to replace breakdownIdx

        wC = increment(breakdownIdx, wC, breakdown, 1);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            // closeBraceCheck = true;
            j = memKeySize + 1;
        }
    } // End memkey loop
    breakdownIdx = 0;

    // this loops through associations
    for (int i = 0; i < assocSize; i++) {
        incrementFlag = 1;
        writeFlag = 1;
        wC = breakdown->associations.data[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->assocScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
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
        wC = increment(breakdownIdx, wC, breakdown, incrementFlag);
        writeTarget = builderr->assocScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 2, builderr, breakdown, pbuffers,wC, incrementFlag); // wC should be at the end of whatever word was last parsed here
        if (breakdownIdx == -1) {exit(EXIT_FAILURE);}
        export_->assoc.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace BreakdownIDX

        /* This was originally updating wC from memoryKey before increment; i've implemented increment with 2 for association because
         I think that the memoryKey was a mistake */
        wC = increment(breakdownIdx, wC, breakdown, 2);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            // closeBraceCheck = true;
            i = assocSize + 1;
        }
    } // End associations loop
    breakdownIdx = 0;

    // this loops through associators
    for (int k = 0; k < associatorsSize; k++) { // this loops through associators
        incrementFlag = 2;
        writeFlag = 2;
        wC = breakdown->workingAssociators.data[breakdownIdx]; // Setting wC for this logic block

        if (wC == NAMETOKEN) {
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }
            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->associatorScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct, needs an index
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
        wC = increment(breakdownIdx, wC, breakdown, incrementFlag);
        writeTarget = builderr->associatorScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(breakdownIdx, scratchOneIdx, 3, builderr, breakdown, pbuffers, wC, incrementFlag); // wC should be at the end of whatever word was last parsed here
        export_->associators.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace breakdownIdx
        wC = increment(breakdownIdx, wC, breakdown, 3);
        if (wC == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (wC == CLOSEBRACE) {
            // closeBraceCheck = true;
            k = associatorsSize + 1;
        }
    } // End associators loop
}

Builder* build_init() {
    Builder *builderr = malloc(sizeof(Builder));
    builderr->associatorScratch.length = 0;
    builderr->associatorScratch.capacity = 0;
    builderr->memKeyScratch.length = 0;
    builderr->memKeyScratch.capacity = 0;
    builderr->memKeyScratch.data = malloc(32);
    builderr->assocScratch.data = malloc(64);
    builderr->associatorScratch.data = malloc(32);
    if (!builderr->memKeyScratch.data || !builderr->assocScratch.data || !builderr->associatorScratch.data)
    {
        perror("build_init malloc failed");
        exit(EXIT_FAILURE);
    }
    return builderr;
}
ParserBuffers* pbuffers_init() {
    ParserBuffers *pbuffers = malloc(sizeof(ParserBuffers));
    pbuffers->compBuffer.length = 0;
    pbuffers->compBuffer.capacity = 0;
    pbuffers->compArray.length = 0;
    pbuffers->compArray.capacity = 0;
    pbuffers->Buffers.length = 0;
    pbuffers->Buffers.capacity = 0;
    pbuffers->Buffers.data = malloc(32);
    pbuffers->compArray.data = malloc(32);
    pbuffers->compBuffer.data = malloc(32);
    if (!pbuffers->Buffers.data || !pbuffers->compArray.data || !pbuffers->compBuffer.data) {
        perror("pbuffers_init malloc failed");
        exit(EXIT_FAILURE);
    }
    return pbuffers;
}
int prun()
{
    // This establishes the struct instances and
    // passes them into parseAssocs
    Organizer *lexerbreakdown = breakdown_init();
    Export *exp = exp_init();
    Builder *builderr = build_init();
    ParserBuffers *pbuffers = pbuffers_init();
    parse(lexerbreakdown, exp, builderr, pbuffers);
    return 0;
}


