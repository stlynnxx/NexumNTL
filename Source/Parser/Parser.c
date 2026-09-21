//
// Created by steviexx on 3/31/26.
//
#include "Parser.h"



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
            builder->wC.data[breakdownIdx] = lexerbreakdown->memoryKey.data[breakdownIdx];
            break;
        case 1:
            breakdownIdx++;
            builder->wC.data[breakdownIdx] = lexerbreakdown->associations.data[breakdownIdx];
            break;
        case 2:
            breakdownIdx++;
            builder->wC.data[breakdownIdx] = lexerbreakdown->workingAssociators.data[breakdownIdx];
            break;
        default:
            break;
    }
    return breakdownIdx;
}

Export* exp_init()
{
    Export *ex = malloc(sizeof(Export));
    ex->assoc.length = 0;
    ex->assoc.capacity = 0;
    ex->memKey.length = 0;
    ex->memKey.capacity = 0;
    ex->encodedMorpheme.length = 0;
    ex->encodedMorpheme.capacity = 0;
    ex->encodedMorpheme.data = malloc(32);
    ex->memKey.data = malloc(32);
    ex->assoc.data = malloc(64);
    ex->associators.data = malloc(32);
    if (!ex->memKey.data || !ex->assoc.data || !ex->associators.data) {
        perror("exp_init malloc failed");
        exit(EXIT_FAILURE);
    }
    return ex;
}

// 0 = memkey, 1 = assoc, 2 = associator, 3 = encodedMorpheme
void exp_append(Export *export, int flag, char append[])
{
    switch (flag)
    {
        case 0:
            exp_append_string(&*export, append, sizeof(append[0]), flag);
            // Memory Keys
            break;
        case 1:
            // Associations
            break;
        case 2:
            // Associators
            break;
        case 3:
            // encodedMorpheme
            append_string(*export_, append[0], sizeof(append[0]));
            break;
        default:
            break;
    }
}

Export* encode(int foundI, int row, int scratchOneIdx, int flag)
{
    Export *ex = exp_init();
    int encodeVal;
    // Encoded morpheme eventually needs to use a dynamic buffer
    char *encodedMorpheme[10];
    encodedMorpheme[0] = encodedMatrix[row][foundI];
    // Should we have write target write to export at this point?
    // writeTarget[scratchOneIdx] = encodedMorpheme[0];
    switch (flag)
    {
        case 0:
            exp_append(ex, flag, encodedMorpheme[0]);
            if (!ex->memKey.data[scratchOneIdx])
            {
                encodeVal = -1;
            }
            else {
                encodeVal = 1;
            }
            break;
        case 1:
            exp_append(ex, flag, encodedMorpheme[0]);
            if (!ex->assoc.data[scratchOneIdx]) {
                encodeVal = -1;
            }
            else {
                encodeVal = 1;
            }
            break;
        case 2:
            exp_append(ex, flag, encodedMorpheme[0]);
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
    return ex;
}

Export* verify(Export *exp, ParserBuffers *pbuffer, int rowSiZe, int row, int scratchOneIdx, int flag)
{
    int foundI;
    for (int i = 0; i <= rowSiZe; i++)
    {
        if (valuesMatrix[row][i] == NULL) perror("values matrix null"); exit(EXIT_FAILURE);
        if (strncmp(pbuffer->Buffers.data, valuesMatrix[row][i], strlen(pbuffer->Buffers.data)) == 0)
        {
            // match is found here
            foundI = i;
            exp = encode(foundI, row, scratchOneIdx, flag);
        }
        else {
            // We need to catch the unverified morpheme here and then hand it over to usrmor
            foundI = i;
            exp = encode(foundI, row, scratchOneIdx, flag);

        }
    }
    return exp;
}

//
Export* match(Export *exp,int scratchOneIdx, int flag, ParserBuffers *pbuffers)
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
                exp = verify(exp,pbuffers, rowSize, A, scratchOneIdx, flag);
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                exp = verify(exp,pbuffers, rowSize, B, scratchOneIdx, flag);
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                exp = verify(exp,pbuffers, rowSize, C, scratchOneIdx, flag);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                exp = verify(exp,pbuffers, rowSize, D, scratchOneIdx, flag);
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
                builderr->memKeyScratch.data[scratchOneIdx] = builderr->wC.data[breakdownIdx];
                break;
            case 1:
                builderr->assocScratch.data[scratchOneIdx] = builderr->wC.data[breakdownIdx];
                break;
            case 2:
                builderr->associatorScratch.data[scratchOneIdx] = builderr->wC.data[breakdownIdx];
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
    // char wC; // Similar to wC in Lexer, is the current working character

    builderr->wC.data[breakdownIdx] = breakdown->associations[breakdownIdx]; // This sets the current working character
    char *writeTarget; // the array being written to within checker
    // This loops through the memKeys
    for (int j = 0; j < memKeySize; j++) { // This loops through the memKeys
        incrementFlag = 0;
        writeFlag = 0;
        // wC = breakdown->memoryKey.data[breakdownIdx]; // Setting wC for this logic block
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        writeTarget = builderr->memKeyScratch.data; // Assigns write target
        // The next line is what will be replaced with newCheck
        /// breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 1, builderr, breakdown, pbuffers, incrementFlag); // wC should be at the end of whatever word was last parsed here
        exp->memKey.data[breakdownIdx] = writeTarget[breakdownIdx]; // We need to replace breakdownIdx
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (builderr->wC.data[breakdownIdx] == CLOSEBRACE) {
            // closeBraceCheck = true;
            j = memKeySize + 1;
        }
    } // End memkey loop
    breakdownIdx = 0;
    // this loops through associations
    for (int i = 0; i < assocSize; i++) {
        incrementFlag = 1;
        writeFlag = 1;
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        writeTarget = builderr->assocScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 2, builderr, breakdown, pbuffers, incrementFlag); // wC should be at the end of whatever word was last parsed here
        if (breakdownIdx == -1) {exit(EXIT_FAILURE);}
        exp->assoc.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace BreakdownIDX
        /* This was originally updating wC from memoryKey before increment; i've implemented increment with 2 for association because
            I think that the memoryKey was a mistake */
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
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
        writeFlag = 2;
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
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        writeTarget = builderr->associatorScratch.data; // Assigns write target
        // breakdownIdx = checker(breakdownIdx, scratchOneIdx, writeTarget, builderr, breakdown, wC); // wC should be at the end of whatever word was last parsed here
        breakdownIdx = newCheck(exp,breakdownIdx, scratchOneIdx, 3, builderr, breakdown, pbuffers,incrementFlag); // wC should be at the end of whatever word was last parsed here
        exp->associators.data[breakdownIdx] = writeTarget[breakdownIdx]; // Probably should replace breakdownIdx
        breakdownIdx = increment(breakdownIdx, builderr->wC.data[breakdownIdx], breakdown, incrementFlag, builderr);
        if (builderr->wC.data[breakdownIdx] == NAMETOKEN) {
            secondNameTokenCheck = true;
        }
        if (builderr->wC.data[breakdownIdx] == CLOSEBRACE) {
            // closeBraceCheck = true;
            k = associatorsSize + 1;
        }
    } // End associators loop
}

Builder* build_init() {
    Builder *builderr = malloc(sizeof(Builder));
    builderr->associatorScratch.length = 0;
    builderr->associatorScratch.capacity = 0;\
    builderr->assocScratch.length = 0;
    builderr->assocScratch.capacity = 0;
    builderr->memKeyScratch.length = 0;
    builderr->memKeyScratch.capacity = 0;
    builderr->wC.length = 0;
    builderr->wC.capacity = 0;
    builderr->memKeyScratch.data = malloc(32);
    builderr->assocScratch.data = malloc(64);
    builderr->associatorScratch.data = malloc(32);
    builderr->wC.data = malloc(2);
    if (!builderr->memKeyScratch.data || !builderr->assocScratch.data || !builderr->associatorScratch.data || !builderr->wC.data || !builderr->assocScratch.data)
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


