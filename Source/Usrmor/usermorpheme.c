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

void usrmor_commit(InputForm *form, Export *export, ParserBuffers *pbuffers, int row, int row_size,int flag) {
    verify(export, form, pbuffers, row, row_size,flag);

}

void usrmor_match(InputForm *form, Export *export, ParserBuffers *pbuffers, Unencoded *unencoded, char first_letter, bool pCheck, int flag) {
    int found_i;
    int row_size;
    int row;
    int usrmor_idx;
    switch (first_letter)
        {
            case 'A':
                row = A;
                row_size = sizeof(valuesMatrix[A])/sizeof(valuesMatrix[A][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[A][usrmor_idx] = unencoded->morpheme.data;
                break;
            case 'B':
                row = B;
                row_size = sizeof(valuesMatrix[B])/sizeof(valuesMatrix[B][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[B][usrmor_idx] = unencoded->morpheme.data;

                break;
            case 'C':
                row = C;
                row_size = sizeof(valuesMatrix[C])/sizeof(valuesMatrix[C][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[C][usrmor_idx] = unencoded->morpheme.data;
                break;
            case 'D':
                row = D;
                row_size = sizeof(valuesMatrix[D])/sizeof(valuesMatrix[D][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[D][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[D][usrmor_idx] = valuesMatrix[D][usrmor_idx];
                break;
            case 'E':
                row = E;
                row_size = sizeof(valuesMatrix[E])/sizeof(valuesMatrix[E][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[E][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[E][usrmor_idx] = valuesMatrix[E][usrmor_idx];
                break;
            case 'F':
                row = F;
                row_size = sizeof(valuesMatrix[F])/sizeof(valuesMatrix[F][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[F][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[F][usrmor_idx] = valuesMatrix[F][usrmor_idx];
                break;
            case 'G':
                row  = G;
                row_size = sizeof(valuesMatrix[G])/sizeof(valuesMatrix[G][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[G][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[G][usrmor_idx] = valuesMatrix[G][usrmor_idx];
                break;
            case 'H':
                row  = H;
                row_size = sizeof(valuesMatrix[H])/sizeof(valuesMatrix[H][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[H][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[H][usrmor_idx] = valuesMatrix[H][usrmor_idx];
                break;
            case 'I':
                row = I;
                row_size = sizeof(valuesMatrix[I])/sizeof(valuesMatrix[I][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[I][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[I][usrmor_idx] = valuesMatrix[I][usrmor_idx];
                break;
            case 'J':
                row = J;
                row_size = sizeof(valuesMatrix[J])/sizeof(valuesMatrix[J][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[J][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[J][usrmor_idx] = valuesMatrix[J][usrmor_idx];
                break;
            case 'K':
                row = K;
                row_size = sizeof(valuesMatrix[K])/sizeof(valuesMatrix[K][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[K][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[K][usrmor_idx] = valuesMatrix[K][usrmor_idx];
                break;
            case 'L':
                row = L;
                row_size = sizeof(valuesMatrix[L])/sizeof(valuesMatrix[L][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[L][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[L][usrmor_idx] = valuesMatrix[L][usrmor_idx];
                break;
            case 'M':
                row = M;
                row_size = sizeof(valuesMatrix[M])/sizeof(valuesMatrix[M][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[M][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[M][usrmor_idx] = valuesMatrix[M][usrmor_idx];
                break;
            case 'N':
                row = N;
                row_size = sizeof(valuesMatrix[N])/sizeof(valuesMatrix[N][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[N][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[N][usrmor_idx] = valuesMatrix[N][usrmor_idx];
                break;
            case 'O':
                row = O;
                row_size = sizeof(valuesMatrix[O])/sizeof(valuesMatrix[O][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[O][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[O][usrmor_idx] = valuesMatrix[O][usrmor_idx];
                break;
            case 'P':
                row = P;
                row_size = sizeof(valuesMatrix[P])/sizeof(valuesMatrix[P][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[P][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[P][usrmor_idx] = valuesMatrix[P][usrmor_idx];
                break;
            case 'Q':
                row = Q;
                row_size = sizeof(valuesMatrix[Q])/sizeof(valuesMatrix[Q][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[Q][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[Q][usrmor_idx] = valuesMatrix[Q][usrmor_idx];
                break;
            case 'R':
                row = R;
                row_size = sizeof(valuesMatrix[R])/sizeof(valuesMatrix[R][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[R][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[R][usrmor_idx] = valuesMatrix[R][usrmor_idx];
                break;
            case 'S':
                row = S;
                row_size = sizeof(valuesMatrix[S])/sizeof(valuesMatrix[S][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[S][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[S][usrmor_idx] = valuesMatrix[S][usrmor_idx];
                break;
            case 'T':
                row = T;
                row_size = sizeof(valuesMatrix[T])/sizeof(valuesMatrix[T][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[T][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[T][usrmor_idx] = valuesMatrix[T][usrmor_idx];
                break;
            case 'U':
                row = U;
                row_size = sizeof(valuesMatrix[U])/sizeof(valuesMatrix[U][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[U][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[U][usrmor_idx] = valuesMatrix[U][usrmor_idx];
                break;
            case 'V':
                row = V;
                row_size = sizeof(valuesMatrix[V])/sizeof(valuesMatrix[V][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[V][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[V][usrmor_idx] = valuesMatrix[V][usrmor_idx];
                break;
            case 'W':
                row = W;
                row_size = sizeof(valuesMatrix[W])/sizeof(valuesMatrix[W][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[W][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[W][usrmor_idx] = valuesMatrix[W][usrmor_idx];
                break;
            case 'X':
                row = X;
                row_size = sizeof(valuesMatrix[X])/sizeof(valuesMatrix[X][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[X][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[X][usrmor_idx] = valuesMatrix[X][usrmor_idx];
                break;
            case 'Y':
                row = Y;
                row_size = sizeof(valuesMatrix[Y])/sizeof(valuesMatrix[Y][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[Y][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[Y][usrmor_idx] = valuesMatrix[Y][usrmor_idx];
                break;
            case 'Z':
                row = Z;
                row_size = sizeof(valuesMatrix[Z])/sizeof(valuesMatrix[Z][0]);
                usrmor_idx = row_size + 1;
                valuesMatrix[Z][usrmor_idx] = unencoded->morpheme.data;
                encodedMatrix[Z][usrmor_idx] = valuesMatrix[Z][usrmor_idx];
                break;
            default:
                break;
        }

        if (!pCheck) {
            usrmor_commit(form,export,pbuffers,row,row_size,flag);
        }
        else {
            terminal_to_nexc_encode(form, found_i, row_size, usrmor_idx);
        }
}
bool terminal_to_nexc_usrmor_add_p(InputForm *form, int foundI, bool add_p_check) {
    add_p_check = true;
    Unencoded *unencoded = unencoded_init();
    terminalToNexcUsrAppendString(unencoded, form);
    input_free(form);
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(form, unencoded, firstLetter, foundI, add_p_check);
    return add_p_check;
}
void usrmor_add_p(InputForm *form,Export *export,ParserBuffers *pbuffers,char *byte, int foundI, int flag) {
    bool pCheck = true;
    Unencoded *unencoded = unencoded_init();
    usr_append_string(unencoded, byte, foundI, sizeof(byte));
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(form,export, pbuffers,unencoded, firstLetter, pCheck, flag);
}

void usrmor_add(char *byte, int foundI) {
    bool pCheck = false;
    Unencoded *unencoded = unencoded_init();
    usr_append_string(unencoded, byte, foundI, sizeof());
    char firstLetter = unencoded->morpheme.data[0];
    usrmor_match(unencoded, firstLetter, pCheck);
}
