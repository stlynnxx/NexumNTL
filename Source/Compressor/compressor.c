//
// Created by steviexx on 9/16/26.
//

#include "compressor.h"

#include <ctype.h>

#include "../Parser/Parser.h"


Input* in_init() {
    Input *in = malloc(sizeof(Input));
    in->buffer.capacity = 0;
    in->buffer.length = 0;
    in->buffer.data = malloc(32);
    if (!in->buffer.capacity || !in->buffer.data || !in->buffer.length) {
        perror("in_init error");
        exit(-1);
    }
    return in;
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

int verify(Input *in, size_t rowSiZe, int row, int scratchOneIdx, int flag) {
    int encodeVal = 0;
    int foundI;
    for (int i = 0; i <= rowSiZe; i++) {
        if (valuesMatrix[row][i] == NULL) return -1;
        if (strncmp(in->buffer.data, valuesMatrix[row][i], strlen(in->buffer.data)) == 0) {
            // match is found here
            foundI = i;
            encodeVal = encode(foundI, row, scratchOneIdx, flag);
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
int match(int scratchOneIdx, int flag, Input *in) {
    size_t rowSize;
    const char select = in->buffer.data[0];
    // const char compSelect =  pbuffers->compBuffer.data[0];
    char workSelect = toupper(select);
    int verifyReturn;
    if (isalnum(select))
    {
        switch (workSelect)
        {
            case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                verifyReturn = verify(in, rowSize, A, scratchOneIdx, flag);
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                verifyReturn = verify(in, rowSize, B, scratchOneIdx, flag);
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                verifyReturn = verify(in, rowSize, C, scratchOneIdx, flag);
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                verifyReturn = verify(in, rowSize, D, scratchOneIdx, flag);
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                verifyReturn = verify(in, rowSize, E, scratchOneIdx, flag);
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                verifyReturn = verify(in, rowSize, F, scratchOneIdx, flag);
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                verifyReturn = verify(in, rowSize, G, scratchOneIdx, flag);
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                verifyReturn = verify(in, rowSize, H, scratchOneIdx, flag);
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                verifyReturn = verify(in, rowSize, I, scratchOneIdx, flag);
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                verifyReturn = verify(in, rowSize, J, scratchOneIdx, flag);
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                verifyReturn = verify(in, rowSize, K, scratchOneIdx, flag);
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                verifyReturn = verify(in, rowSize, L,scratchOneIdx, flag);
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                verifyReturn = verify(in, rowSize, M, scratchOneIdx, flag);
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                verifyReturn = verify(in, rowSize, N, scratchOneIdx, flag);
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                verifyReturn = verify(in, rowSize, O, scratchOneIdx, flag);
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                verifyReturn = verify(in, rowSize, P, scratchOneIdx, flag);
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                verifyReturn = verify(in, rowSize, Q, scratchOneIdx, flag);
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                verifyReturn = verify(in, rowSize, R, scratchOneIdx, flag);
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                verifyReturn = verify(in, rowSize, S, scratchOneIdx, flag);
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                verifyReturn = verify(in, rowSize, T, scratchOneIdx, flag);
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                verifyReturn = verify(in, rowSize, U, scratchOneIdx, flag);
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                verifyReturn = verify(in, rowSize, V, scratchOneIdx, flag);
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                verifyReturn = verify(in, rowSize, W, scratchOneIdx, flag);
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix)[X][0];
                verifyReturn = verify(in, rowSize, X, scratchOneIdx, flag);
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                verifyReturn = verify(in, rowSize, Y, scratchOneIdx, flag);
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                verifyReturn = verify(in, rowSize, Z, scratchOneIdx, flag);
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
            default:
                return -1;
                break;
        }

    } return -1;

}
void input_collect(Input *input) {
    match(0,1, input);
    // this will need to get the input from python, get it translated into nexcode from NTL,
    // and then append it into the input buff


}
void collect() {
    Input *in = in_init();
}