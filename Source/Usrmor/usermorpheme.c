//
// Created by steviexx on 9/19/26.
//

#include "usermorpheme.h"

#include "usrmorhelpers.h"
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"
#include "../SourceGenerator/SourceGenerator.h"
#include "../SourceGenerator/SGruninterface.h"
#define USRMOR_PATH "../data/usrmor.nex"
#define TERMINAL_SOURCE_FLAG 0
#define FILE_SOURCE_FLAG 1

void usrmor_commit(bool pCheck) {
    sgRun(USRMOR_PATH, 0, pCheck,FILE_SOURCE_FLAG);
}

void usrmor_match(Unencoded *unencoded, char firstLetter, bool pCheck) {
    int rowSize;
    int usrmorIdx;
    switch (firstLetter)
        {
            case 'A':
                rowSize = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[A][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[A][usrmorIdx] = valuesMatrix[A][usrmorIdx];
                break;
            case 'B':
                rowSize = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[B][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[B][usrmorIdx] = valuesMatrix[B][usrmorIdx];
                break;
            case 'C':
                rowSize = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[C][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[C][usrmorIdx] = valuesMatrix[C][usrmorIdx];
                break;
            case 'D':
                rowSize = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[D][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[D][usrmorIdx] = valuesMatrix[D][usrmorIdx];
                break;
            case 'E':
                rowSize = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[E][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[E][usrmorIdx] = valuesMatrix[E][usrmorIdx];
                break;
            case 'F':
                rowSize = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[F][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[F][usrmorIdx] = valuesMatrix[F][usrmorIdx];
                break;
            case 'G':
                rowSize = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[G][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[G][usrmorIdx] = valuesMatrix[G][usrmorIdx];
                break;
            case 'H':
                rowSize = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[H][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[H][usrmorIdx] = valuesMatrix[H][usrmorIdx];
                break;
            case 'I':
                rowSize = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[I][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[I][usrmorIdx] = valuesMatrix[I][usrmorIdx];
                break;
            case 'J':
                rowSize = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[J][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[J][usrmorIdx] = valuesMatrix[J][usrmorIdx];
                break;
            case 'K':
                rowSize = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[K][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[K][usrmorIdx] = valuesMatrix[K][usrmorIdx];
                break;
            case 'L':
                rowSize = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[L][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[L][usrmorIdx] = valuesMatrix[L][usrmorIdx];
                break;
            case 'M':
                rowSize = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[M][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[M][usrmorIdx] = valuesMatrix[M][usrmorIdx];
                break;
            case 'N':
                rowSize = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[N][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[N][usrmorIdx] = valuesMatrix[N][usrmorIdx];
                break;
            case 'O':
                rowSize = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[O][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[O][usrmorIdx] = valuesMatrix[O][usrmorIdx];
                break;
            case 'P':
                rowSize = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[P][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[P][usrmorIdx] = valuesMatrix[P][usrmorIdx];
                break;
            case 'Q':
                rowSize = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Q][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[Q][usrmorIdx] = valuesMatrix[Q][usrmorIdx];
                break;
            case 'R':
                rowSize = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[R][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[R][usrmorIdx] = valuesMatrix[R][usrmorIdx];
                break;
            case 'S':
                rowSize = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[S][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[S][usrmorIdx] = valuesMatrix[S][usrmorIdx];
                break;
            case 'T':
                rowSize = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[T][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[T][usrmorIdx] = valuesMatrix[T][usrmorIdx];
                break;
            case 'U':
                rowSize = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[U][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[U][usrmorIdx] = valuesMatrix[U][usrmorIdx];
                break;
            case 'V':
                rowSize = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[V][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[V][usrmorIdx] = valuesMatrix[V][usrmorIdx];
                break;
            case 'W':
                rowSize = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[W][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[W][usrmorIdx] = valuesMatrix[W][usrmorIdx];
                break;
            case 'X':
                rowSize = sizeof(valuesMatrix[X])/sizeof(valuesMatrix[X][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[X][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[X][usrmorIdx] = valuesMatrix[X][usrmorIdx];
                break;
            case 'Y':
                rowSize = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Y][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[Y][usrmorIdx] = valuesMatrix[Y][usrmorIdx];
                break;
            case 'Z':
                rowSize = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                usrmorIdx = rowSize + 1;
                valuesMatrix[Z][usrmorIdx] = unencoded->morpheme.data;
                encodedMatrix[Z][usrmorIdx] = valuesMatrix[Z][usrmorIdx];
                break;
            default:
                break;
        }
        if (pCheck) {
            usrmor_commit(pCheck);
        }
        else {

        }
}
void terminalToNexcUsrmorAddP(Export *export, int foundI) {
    bool pCheck = true;
    Unencoded *unencoded = unencoded_init();
    terminalToNexcUsrAppendString(unencoded, export, foundI, export->memKey.length);
    // exp needs freed here
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(unencoded, firstLetter, pCheck);
}
void usrmor_add_p(char *byte, int foundI) {
    bool pCheck = true;
    Unencoded *unencoded = unencoded_init();
    usr_append_string(unencoded, byte, foundI, sizeof());
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(unencoded, firstLetter, pCheck);
}

void usrmor_add(char *byte, int foundI) {
    bool pCheck = false;
    Unencoded *unencoded = unencoded_init();
    usr_append_string(unencoded, byte, foundI, sizeof());
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(unencoded, firstLetter, pCheck);
}
