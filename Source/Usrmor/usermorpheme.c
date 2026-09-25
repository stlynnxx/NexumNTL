//
// Created by steviexx on 9/19/26.
//

#include "usermorpheme.h"

#include "usrmorhelpers.h"
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"

void match(Unencoded *unencoded, char firstLetter) {
    int rowSize;
    int usrmorIdx;
    switch (firstLetter)
        {
            case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[A][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[B][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[C][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[D][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[E][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[F][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[G][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[H][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[I][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[J][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[K][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[L][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[M][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[N][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[O][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[P][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Q][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[R][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[S][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[T][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[U][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[V][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[W][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix[X][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[X][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Y][usrmorIdx] = unencoded->morpheme.data;
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Z][usrmorIdx] = unencoded->morpheme.data;
                break;
            default:
                break;
        }
}




void usrmor_add_p(Export *export, ParserBuffers *pbuffers, int foundI) {
    Unencoded *unencoded = unencoded_init();
    unc_append_string(unencoded, pbuffers, foundI, sizeof(pbuffers->Buffers.data[foundI]));
    char firstLetter = unencoded->morpheme.data[0];
    match(firstLetter);

}
void usrmor_add() {

}
