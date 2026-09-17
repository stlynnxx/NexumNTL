//
// Created by steviexx on 9/16/26.
//

#include "compressor.h"

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

void input_collect(Input *input) {
    match(0,1, input);
    // this will need to get the input from python, get it translated into nexcode from NTL,
    // and then append it into the input buff
}
void collect() {
    Input *in = in_init();
}