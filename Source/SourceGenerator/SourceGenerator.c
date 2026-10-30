//
// Created by steviexx on 3/11/26.
//

#include "SourceGenerator.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "SGhelpers.h"
#include "../Lexer/Lexer.h"
#include "../SymbolTable/SymbolTable.h"
#include "../Parser/Parser.h"
#include "../Parser/parserhelpers.h"
#include "../Compressor/compressorhelpers.h"

// Input storage
StructFlags struct_flags;


int format_from_export(FILE *export_file, Export *export, int count, int mem_key_idx) {
    fprintf(export_file, "%s\n", "");
    char memoryKeyPrefix[5] = "{'";
    char memoryKeySuffix[5] = "':{";
    fprintf(export_file, "%s", memoryKeyPrefix);
    fprintf(export_file,"%s", export->memKey.data[mem_key_idx]);
    fprintf(export_file, "%s", memoryKeySuffix);
    for (int i = 0; i < count; i++) {
        fprintf(export_file, "%s", "'");
        fprintf(export_file, "%s", export->association.data[i]);
        fprintf(export_file, "%s", "'");
        if (i != export->assocCount - 1) {
            fprintf(export_file, "%c", COMMA);
        }

    }
    fprintf(export_file, "%s", "};");
    if (!export_file) {
        return -1;
    }
    else {
        return 1;
    }

}

int extract_morpheme(const char *data, size_t data_len, size_t *position, Morpheme *morpheme) {
    if (*position >= data_len) {
        return 0;
    }

    size_t start = *position;
    size_t end = start;

    while (end < data_len && data[end] != ',' && data[end] != COMMA) {
        end++;
    }

    morpheme->start = start;
    morpheme->length = end - start;
    *position = (end < data_len) ? end + 1 : end;

    return 1;
}

// This is what is actually being appended to the file
int format(FILE *export_file, InputForm *form, int count) {
    if (!export_file || !form) {
        return -1;
    }

    size_t pos = 0;
    Morpheme current;

    fprintf(export_file, "%s\n", "");

    char memoryKeyPrefix[5] = "{'";
    char memoryKeySuffix[5] = "':{";

    fprintf(export_file, "%s", memoryKeyPrefix);
    fprintf(export_file, "%s", form->memoryKey.data);
    fprintf(export_file, "%s", memoryKeySuffix);

    while (extract_morpheme(
        form->associations.data,
        form->associations.length,
        &pos,
        &current
    )) {
        for (size_t j = 0; j < current.length; j++) {
            fputc(form->associations.data[current.start + j], export_file);
        }

        if (pos < form->associations.length) {
            fputc(',', export_file);
        }
    }

    fprintf(export_file, "};");

    return 1;
}
// Step Two of the append process, opens the created file
// and collects input which gets placed into the input storage
int terminal_inp(FILE* export_file, InputForm *form, int control) {
    bool return_bool;
    int associator_chk = 0;
    // .nex
    if (control == 0) {
        // Memory Key
        printf("Memory Key: \n");
        scanf("%s", form->memoryKeyBuffer.data);
        in_append_string(form, form->memoryKeyBuffer.data, form->memoryKeyBuffer.length, 0);
        // Association
        // We need to check for associators here. Associators are associations prefaced with an @ symbol.
        printf("Assocation Count: \n");
        scanf("%d", form->assocCount);
        printf("Assocations (seperate with spaces, and be sure to match your association count correctly.): \n");
        // the loop below still needs some sort of call to match&verify
        for (int i = 0; i < form->assocCount; i++ )
        {
            scanf("%s", &form->associationBuffer.data[i]);
            if (form->associationBuffer.data[i] == ASSOCIATOR) {
                associator_chk = 1;
            }
            if (associator_chk == 1) {

                SG_line_parse(form);
                associator_chk = 0;
            }
            in_append_string(form, &form->associationBuffer.data[i], form->associationBuffer.length, 1);

        }

        format(export_file, form, form->assocCount, 0);
        return 0;
    }
    // .nexc
    if (control == 1) {
        printf("Memory Key: \n");
        scanf("%s", form->memoryKeyBuffer.data);
        // We need to encode the memoryKeyBuffer here and then write the encoded memorykey into
        // the proper spot in inputform
        // struct flag 4 is for the memkeybuffer
        in_append_string(form, form->memoryKeyBuffer.data, form->memoryKeyBuffer.length, memoryKey);
        // form->found_i and form->found_row are reassigned with every match call
        return_bool = terminal_to_nexc_match(form,export_file, memoryKey, form->memoryKey.data[0]);
        // We took encode out of match, and also format out of encode, so they will need handled individually.
        nexc_encode(form, export_file, encodedMemoryKey);
        if (return_bool == false) {
            perror("Match return error");
            exit(EXIT_FAILURE);
        }
        printf("Assocation Count: \n");
        scanf("%d", form->assocCount);
        for (int i = 0; i < form->assocCount; i++ )
        {
            printf("Enter Associaton");
            scanf("%s", form->associationBuffer.data);
            if (form->associatorBuffer.data[i] == ASSOCIATOR) {
                in_append_string(form, form->associatorBuffer.data, form->associatorBuffer.length, associations);
                free(form->associationBuffer.data);
                // form->found_i and form->found_row are reassigned with every match call
                return_bool = terminal_to_nexc_match(form,export_file,associations,form->associations.data);
                // form->found_row + form->found_i is our encoded morpheme
                // the encoded morpheme needs written to file via format
                if (return_bool == false) perror("Match return error!"); exit(EXIT_FAILURE);
            }
            // handling associations
            in_append_string(form, form->associatorBuffer.data, form->associatorBuffer.length, associators);
            free(form->associationBuffer.data);
            // form->found_i and form->found_row are reassigned with every match call
            return_bool = terminal_to_nexc_match(form,export_file,associators,form->associators.data);
            // form->found_row + form->found_i is our encoded morpheme
            // the encoded morpheme needs written to file via format
            if (return_bool == false) perror("Match return error!"); exit(EXIT_FAILURE);
        }
        // One format call for the entire line
        format(export_file, form, form->assocCount);
        return 0;
    }
    else {
        return -1;
    }
}
int* count_set(InputForm *form, int *counts) {
    // this loads the size of each row into counts by the letter macro number- entry 0 is the size for A, entry 1 is the size of B, and so forth
    for (int i = 0; i <= 25; i++) {
        counts[i] = sizeof(valuesMatrix[i])/sizeof(valuesMatrix[i][0]);
    }

    for (int k = 0; k <= 25; k++) {
        for (int l = 0; l < counts[k]; l++) {
            in_append_string(form, valuesMatrix[k][l], sizeof(valuesMatrix[k][l]), 1);
        }
    }
    return counts;

}

int usrmor_input(FILE *fp, InputForm *form) {
    // This will need to take the updated values matrices themselves and translate them to .nex/.nexc
    //
    // this is assigning memory keys as first letters
    int *counts[30];
    char letters[30] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i <= 25; i++) {
        form->memoryKey.data[i] = letters[i];
    }

    *counts = count_set(form, *counts);
    format(fp, form, *counts[A],  A);
    free(form->associators.data);
    form->associators.data = NULL;
    for (int i = 1; i <= 25; i++) {
        form->associators.data = malloc(32);
        *counts = count_set(form, *counts);
        format(fp, form, *counts[i], i);
        free(form->associations.data);
        form->associations.data = NULL;
    }
    return 0;
}

int nexc(FILE *fp, InputForm *form, Export *exp) {
    // The following variables are establishing the sizes for the arrays within the struct
    size_t sizeAssoc = sizeof(exp->association) / sizeof(exp->association.data[0]);
    size_t sizeAssociators = sizeof(exp->associators) / sizeof(exp->associators.data[0]);
    size_t sizeMemKeys = sizeof(exp->memKey) / sizeof(exp->memKey.data[0]);
    // Control Vars
    bool mem = false;
    // Here we are looping through the arrays individually
    for (int i = 0; i < sizeAssoc; i++) {
        if (i == 0) {

            exp->memKey.data[i] = NAMETOKEN;
            mem = true;
        }
        if (i > 0) {
            if (form->memoryKey.data[i] )
            form->memoryKey[i] = exp->memKey.data[i];
        }
    }
    for (int i = 0; i < sizeAssociators; i++) {
        form->associators[i] = exp->associators.data[i];
    }
    for (int i = 0; i < sizeMemKeys; i++) {
        form->memoryKey[i] = exp->memKey.data[i];
    }
    if (mem == true) {
        return 1;
    }
    if (mem == false) {
        return 0;
    }
}





/*int main() {
    // bool inputBool = false;
    char entry[30];
    runner("Testing2.nex");

    return 0;
}*/
