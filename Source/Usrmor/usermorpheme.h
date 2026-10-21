//
// Created by steviexx on 9/19/26.
//

#ifndef NEXUMNTL_USERMORPHEME_H
#define NEXUMNTL_USERMORPHEME_H
#include "../Parser/Parser.h"

typedef struct {
    DynamicBuffers morpheme;
    DynamicBuffers memoryKey;
    DynamicBuffers associator;
    DynamicBuffers association;
} Unencoded;



inline void usrmor_match(InputForm *form, Export *export_form, FILE* export_file, ParserBuffers *pbuffers, Unencoded *unencoded, char first_letter, bool pCheck, int flag);
inline void usrmor_add_p(InputForm *form,Export *export,FILE* export_file,ParserBuffers *pbuffers,char *byte, int foundI, int flag);
inline bool terminal_to_nexc_usrmor_add_p(InputForm *form, Export *export_form, FILE* export_file,int foundI, bool add_p_check);
inline void usrmor_add(char *byte, int foundI);
#endif //NEXUMNTL_USERMORPHEME_H
