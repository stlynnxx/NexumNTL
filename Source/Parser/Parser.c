//
// Created by steviexx on 3/31/26.
//
#include "Parser.h"
#include "../Usrmor/usermorpheme.h"

#include <math.h>

#include "parserhelpers.h"


// This will be for checking if a given search term is within the values matrix
const char *valuesSearch(const char *searchTerm)
{
    for (int i = 0; i < 26; i++)
    {
        int cols = sizeof(valuesMatrix[0]) / sizeof(valuesMatrix[0][0]);
        for (int j = 0; j < cols; j++)
        {
            const char *v = valuesMatrix[i][j];
            if (!v || strcmp(v, "NULL") == 0) {
                continue;
            }
            if (strcmp(v, searchTerm) == 0) {
                return v;
            }
        }
    }
    return NULL;
}

// Loads a row associated with a given wC into compArray
void look(ParserBuffers pbuffers, char wC)
{
    for (int r  = 0; r < 26; r++)
    {
        if (toupper(wC) == *valuesMatrix[r][0])
        {
            for (int ii = 0; ii < 14; ii++)
            {
                pbuffers.compArray.data[ii] = *valuesMatrix[r][ii];
            }
        }
    }
}

int increment(int breakdownIdx, char wC, Organizer *lexerbreakdown, int direction, Builder *builder)
{
    switch (direction)
    {
        case 0:
            breakdownIdx++;
            builder_append_string(builder, lexerbreakdown->memoryKey.data[breakdownIdx], sizeof(lexerbreakdown->memoryKey.data[breakdownIdx]), 0);
            break;
        case 1:
            breakdownIdx++;
            builder_append_string(builder, lexerbreakdown->memoryKey.data[breakdownIdx], sizeof(lexerbreakdown->memoryKey.data[breakdownIdx]), 1);
            break;
        case 2:
            breakdownIdx++;
            builder_append_string(builder, lexerbreakdown->memoryKey.data[breakdownIdx], sizeof(lexerbreakdown->memoryKey.data[breakdownIdx]), 2);
            break;
        case 3:
            breakdownIdx++;
            builder_append_string(builder, lexerbreakdown->memoryKey.data[breakdownIdx], sizeof(lexerbreakdown->memoryKey.data[breakdownIdx]), 3);
        default:
            break;
    }
    return breakdownIdx;
}

// terminal to nexc match

void terminalToNexcEncode(Export *ex, int foundI, int row, int flag)
{
    int expReturn;
    ex->encodedMorpheme.data[0] = *encodedMatrix[row][foundI];
    expReturn = exp_append_string(ex, &ex->encodedMorpheme.data[0], sizeof(ex->encodedMorpheme.data[0]), flag);
    if (expReturn == -1) {
        perror("Encode failure");
        exit(EXIT_FAILURE);
    }
    // exp needs to be freed here

}

void terminalToNexcVerify(Export *exp, int rowSiZe, int row, int flag)
{
    int foundI;
    for (int i = 0; i <= rowSiZe; i++)
    {
        if (valuesMatrix[row][i] == NULL) perror("values matrix null"); exit(EXIT_FAILURE);
        if (strncmp(exp->memoryKeyScratch.data, valuesMatrix[row][i], strlen(exp->memoryKeyScratch.data)) == 0)
        {
            // match is found here
            foundI = i;
            terminalToNexcEncode(exp, foundI, row, flag);
        }
        else {
            // We need to catch the unverified morpheme here and then hand it over to usrmor
            foundI = i;
            terminalToNexcUsrmorAddP(exp, foundI);


        }
    }

}



void terminalToNexcMatch(Export *exp,int flag, char firstLetter)
{
    size_t rowSize;
    switch (firstLetter)
    {
        case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                terminalToNexcVerify(exp, rowSize, A,  flag);
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                terminalToNexcVerify(exp, rowSize, B,  flag);
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                terminalToNexcVerify(exp, rowSize, C,  flag);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                terminalToNexcVerify(exp, rowSize, D,  flag);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                terminalToNexcVerify(exp, rowSize, E,  flag);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                terminalToNexcVerify(exp, rowSize, F,  flag);
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                terminalToNexcVerify(exp, rowSize, G,  flag);
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                terminalToNexcVerify(exp, rowSize, H,  flag);
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                terminalToNexcVerify(exp, rowSize, I,  flag);
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                terminalToNexcVerify(exp, rowSize, J,  flag);
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                terminalToNexcVerify(exp, rowSize, K,  flag);
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                terminalToNexcVerify(exp, rowSize, L,  flag);
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                terminalToNexcVerify(exp, rowSize, M,  flag);
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                terminalToNexcVerify(exp, rowSize, N,  flag);
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                terminalToNexcVerify(exp, rowSize, O,  flag);
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                terminalToNexcVerify(exp, rowSize, P,  flag);
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                terminalToNexcVerify(exp, rowSize, Q,  flag);
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                terminalToNexcVerify(exp, rowSize, R,  flag);
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                terminalToNexcVerify(exp, rowSize, S,  flag);
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                terminalToNexcVerify(exp, rowSize, T,  flag);
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                terminalToNexcVerify(exp, rowSize, U,  flag);
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                terminalToNexcVerify(exp, rowSize, V,  flag);
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                terminalToNexcVerify(exp, rowSize, W,  flag);
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                terminalToNexcVerify(exp, rowSize, X,  flag);
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                terminalToNexcVerify(exp, rowSize, Y,  flag);
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                terminalToNexcVerify(exp, rowSize, Z,  flag);
                break;
            default:
                verifyReturn = -1;
                break;
        }
    } return exp;
}

//

Export* encode(Export *ex, int foundI, int row, int flag)
{
    int expReturn;
    ex->encodedMorpheme.data[0] = *encodedMatrix[row][foundI];
    expReturn = exp_append_string(ex, &ex->encodedMorpheme.data[0], sizeof(ex->encodedMorpheme.data[0]), flag);
    if (expReturn == -1) {
        perror("Encode failure");
        exit(EXIT_FAILURE);
    }
    return ex;
}

Export* verify(Export *exp, ParserBuffers *pbuffer, int rowSiZe, int row, int flag)
{
    int foundI;
    for (int i = 0; i <= rowSiZe; i++)
    {
        if (valuesMatrix[row][i] == NULL) perror("values matrix null"); exit(EXIT_FAILURE);
        if (strncmp(pbuffer->Buffers.data, valuesMatrix[row][i], strlen(pbuffer->Buffers.data)) == 0)
        {
            // match is found here
            foundI = i;
            exp = encode(exp, foundI, row, flag);
        }
        else {
            // We need to catch the unverified morpheme here and then hand it over to usrmor
            foundI = i;
            usrmor_add_p(exp,pbuffer,foundI);


        }
    }
    return exp;
}

Export* match(Export *exp, int flag, ParserBuffers *pbuffers)
{
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
                exp = verify(exp,pbuffers, rowSize, A,  flag);
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                exp = verify(exp,pbuffers, rowSize, B, flag);
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                exp = verify(exp,pbuffers, rowSize, C, flag);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                exp = verify(exp,pbuffers, rowSize, D, flag);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                exp = verify(exp,pbuffers, rowSize, E,  flag);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                exp = verify(exp,pbuffers, rowSize, F,  flag);
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                exp = verify(exp,pbuffers, rowSize, G,  flag);
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                exp = verify(exp,pbuffers, rowSize, H,  flag);
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                exp = verify(exp,pbuffers, rowSize, I,  flag);
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                exp = verify(exp,pbuffers, rowSize, J,  flag);
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                exp = verify(exp,pbuffers, rowSize, K,  flag);
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                exp = verify(exp,pbuffers, rowSize, L,  flag);
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                exp = verify(exp,pbuffers, rowSize, M,  flag);
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                exp = verify(exp,pbuffers, rowSize, N,  flag);
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                exp = verify(exp,pbuffers, rowSize, O,  flag);
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                exp = verify(exp,pbuffers, rowSize, P,  flag);
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                exp = verify(exp,pbuffers, rowSize, Q,  flag);
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                exp = verify(exp,pbuffers, rowSize, R,  flag);
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                exp = verify(exp,pbuffers, rowSize, S,  flag);
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                exp = verify(exp,pbuffers, rowSize, T,  flag);
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                exp = verify(exp,pbuffers, rowSize, U,  flag);
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                exp = verify(exp,pbuffers, rowSize, V,  flag);
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                exp = verify(exp,pbuffers, rowSize, W,  flag);
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                exp = verify(exp,pbuffers, rowSize, X,  flag);
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                exp = verify(exp,pbuffers, rowSize, Y,  flag);
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                exp = verify(exp,pbuffers, rowSize, z,  flag);
                break;
            default:
                verifyReturn = -1;
                break;
        }
    } return exp;
}

int newCheck(Export *exp, int breakdownIdx, int scratchOneIdx, int writeFlag, Builder *builderr, Organizer *lexerbreakdown, ParserBuffers *pbuffers, int incrementFlag) {
    bool delimCheck = false;
    int matchChk;
    look(*pbuffers, builderr->wC.data[breakdownIdx]); // At this point we should have all of the row associated with the given wC loaded into compArray
    if (!pbuffers->compArray.data[0]) {
        perror("Empty pbuffer comparray in Parser newCheck");
        return -1;
    }
    if (isupper(builderr->wC.data[breakdownIdx]))
    {
        switch (incrementFlag)
        {
            case 0:
                builder_append_char(builderr, builderr->wC.data[breakdownIdx], incrementFlag);
                break;
            case 1:
                builder_append_char(builderr, builderr->wC.data[breakdownIdx], incrementFlag);
                break;
            case 2:
                builder_append_char(builderr, builderr->wC.data[breakdownIdx], incrementFlag);
                break;
            case 3:
                builder_append_char(builderr, builderr->wC.data[breakdownIdx], incrementFlag);
                break;
            default:
                perror("Default error, closing");
                exit(EXIT_FAILURE);
                break;
        }
        for (int i = 0; i < pbuffers->compArray.length; i++)
        {
            if (builderr->wC.data[breakdownIdx] == pbuffers->compArray.data[i])
            {
                if (builderr->wC.data[breakdownIdx] || pbuffers->compArray.data[i] == COMMA)
                {
                    // the comma is the delimiter, so this should denote the end of a word/entry
                    delimCheck = true;
                }

                // we need an append function for pbuffers built
                pbuffers->Buffers.data[i] = pbuffers->compArray.data[i];
                breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], &*lexerbreakdown,incrementFlag, builderr);

            }

            if (builderr->wC.data[breakdownIdx] != pbuffers->compArray.data[i])
            {
                perror("Parser->newCheck failure");
                exit(EXIT_FAILURE);
            }

            if (delimCheck == true)
            {
                // sizeX = sizeof(buffer) / sizeof(buffer[0]);
                for (int j = 0; j < pbuffers->Buffers.length; j++)
                {
                    pbuffers->compArray.data[i] = pbuffers->compBuffer.data[i];
                }
                // sizeY = sizeof(compBuffer) / sizeof(compBuffer[0]);
                if (pbuffers->Buffers.length != pbuffers->compBuffer.length)
                {
                    perror("Size x y error");
                    exit(EXIT_FAILURE);
                }
                if (pbuffers->Buffers.length == pbuffers->compBuffer.length)
                {
                    // Morpheme match
                    exp = match(exp,scratchOneIdx, writeFlag, pbuffers);


                }
            }
        }
        return breakdownIdx;
    }
}

void sendToSource() {
    bool flag = true;
    sgRun("Testing2.nexcode", flag);
}


void parse(Organizer *breakdown, Export *exp, Builder *builderr, ParserBuffers *pbuffers) {
    int writeFlag;
    int incrementFlag;
    int wCFlag = 3;
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
    assocSize = breakdown->associations.length;
    memKeySize = breakdown->memoryKey.length;
    associatorsSize = breakdown->workingAssociators.length;
    // using builderr->wC.data[breakdownIdx] for the char here is wrong
    builder_append_char(builderr, builderr->wC.data[breakdownIdx], wCFlag); // This sets the current working character

    for (int i = 0; i < memKeySize; i++) { // This loops through the memKeys
        incrementFlag = 0;
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr); // Incrementing wC
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            // If this if loop isn't justified in the loop around then we should get rid of it
            if (firstNameTokenCheck == false) {
                firstNameTokenCheck = true;
            }

            if (firstNameTokenCheck == true && secondNameTokenCheck == true) {
                builderr->memKeyScratch.data[workIdx] = COMMA; // This will act as a delimiter for associations within the array within the struct
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        // writeTarget = builderr->memKeyScratch.data; // Assigns write target
        // The next line is what will be replaced with newCheck
        /// breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 1, builderr, breakdown, pbuffers, incrementFlag); // wC should be at the end of whatever word was last parsed here
        exp->memKey.data[breakdownIdx] = pbuffers->writeTarget.data[breakdownIdx]; // We need to replace breakdownIdx
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (builderr->wC.data[breakdownIdx] == CLOSEBRACE) {
            // closeBraceCheck = true;
            i = memKeySize + 1;
        }
    } // End memkey loop
    breakdownIdx = 0;

    // this loops through associations
    for (int i = 0; i < assocSize; i++) {
        incrementFlag = 1;
        builderr->wC.data[breakdownIdx] = breakdown->associations.data[breakdownIdx]; // Setting wC for this logic block
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        // writeTarget = builderr->assocScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 2, builderr, breakdown, pbuffers, incrementFlag); // wC should be at the end of whatever word was last parsed here
        if (breakdownIdx == -1) {exit(EXIT_FAILURE);}
        exp->assoc.data[breakdownIdx] = pbuffers->writeTarget.data[breakdownIdx]; // Probably should replace BreakdownIDX
        /* This was originally updating wC from memoryKey before increment; i've implemented increment with 2 for association because
            I think that the memoryKey was a mistake */
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (builderr->wC.data[breakdownIdx] == CLOSEBRACE) {
            // closeBraceCheck = true;
            i = assocSize + 1;
        }
    } // End associations loop
    breakdownIdx = 0;

    // this loops through associators
    for (int k = 0; k < associatorsSize; k++) { // this loops through associators
        incrementFlag = 2;
        builderr->wC.data[breakdownIdx] = breakdown->workingAssociators.data[breakdownIdx]; // Setting wC for this logic block
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        // writeTarget = builderr->associatorScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 3, builderr, breakdown, pbuffers,incrementFlag); // wC should be at the end of whatever word was last parsed here
        exp->associators.data[breakdownIdx] = pbuffers->writeTarget.data[breakdownIdx]; // Probably should replace breakdownIdx
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, wCFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (builderr->wC.data[breakdownIdx] == CLOSEBRACE) {
            // closeBraceCheck = true;
            k = associatorsSize + 1;
        }
    } // End associators loop
}

// I need to redo cleanup after I'm done working in other parts, i'm sure there will be changes that need to be made
void parser_cleanup_export(void) {
    if (parser_export) {
        exp_free(parser_export);
        parser_export = NULL;
    }
}
Export* get_parser_export(void) {
    return parser_export;
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
    parser_export = exp;
    return 0;
}


