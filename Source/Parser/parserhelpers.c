//
// Created by steviexx on 9/21/26.
//
#include "parserhelpers.h"
#include "Parser.h"
int exp_free(Export *export) {
    if (export) {
        free(export->memKey.data);
        free(export->assoc.data);
        free(export->associators.data);
        free(export->encodedMorpheme.data);
        free(export);
        export = NULL;
        return 0;
    }
    else {
        return -1;
    }
}
int builder_free(Builder *builder) {
    if (builder) {
        free(builder->associatorScratch.data);
        free(builder->assocScratch.data);
        free(builder->memKeyScratch.data);
        free(builder->wC.data);
        free(builder);
        builder = NULL;
        return 0;
    }
    else {
        return -1;
    }
}
int pbuff_free(ParserBuffers *pbuffers) {
    if (pbuffers) {
        free(pbuffers->compArray.data);
        free(pbuffers->Buffers.data);
        free(pbuffers->compBuffer.data);
        free(pbuffers);
        pbuffers = NULL;
        return 0;
    }
    else {
        return -1;
    }
}


int exp_ensure_capacity(Export *export, size_t extra, int control)
{
    size_t needed;
    size_t capacity;

    switch (control) {
        case 0: {
            needed = export->memKey.length + extra;
            if (needed <= export->memKey.capacity) {
                return 0;
            }
            capacity = export->memKey.capacity ? export->memKey.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->memKey.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->memKey.data = tmp;
            export->memKey.capacity = capacity;
            return 0;
        }
        case 1: {
            needed = export->assoc.length + extra;
            if (needed <= export->assoc.capacity) {
                return 0;
            }
            capacity = export->assoc.capacity ? export->assoc.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->assoc.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->assoc.data = tmp;
            export->assoc.capacity = capacity;
            return 0;
            break;
        }
        case 2: {
            needed = export->associators.length + extra;
            if (needed <= export->associators.capacity) {
                return 0;
            }
            capacity = export->associators.capacity ? export->associators.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->associators.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->associators.data = tmp;
            export->associators.capacity = capacity;
            return 0;

            break;
        }
        case 3: {
            needed = export->encodedMorpheme.length + extra;
            if (needed <= export->encodedMorpheme.capacity) {
                return 0;
            }
            capacity = export->encodedMorpheme.capacity ? export->encodedMorpheme.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(export->encodedMorpheme.data, capacity);
            if (!tmp) {
                return -1;
            }
            export->encodedMorpheme.data = tmp;
            export->encodedMorpheme.capacity = capacity;
            return 0;
            break;
        }
        default:
            return -1;
            break;
    }
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



// append_bytes is for appending raw bytes from the given input
int exp_append_bytes(Export *export, char *byte, size_t x, int control)
{
    if (exp_ensure_capacity(export, x, control) != 0) {
        return -1; // failure
    }
    switch (control) {
        case 0:
            memcpy(export->memKey.data + export->memKey.length, byte, x);
            export->memKey.length += x;
            return 0;
            break;
        case 1:
            memcpy(export->associators.data + export->associators.length, byte, x);
            export->associators.length += x;
            return 0;
            break;
        case 2:
            memcpy(export->assoc.data + export->assoc.length, byte, x);
            export->assoc.length += x;
            return 0;
            break;
        case 3:
            memcpy(export->encodedMorpheme.data + export->encodedMorpheme.length, byte, x);
            export->encodedMorpheme.length += x;
            return 0;
            break;
        default:
            perror("Default error");
            exit(EXIT_FAILURE);
    }
}

// This is an interface for passing a string to append bytes
int exp_append_string(Export *export, char *string, size_t x, int control) {
    return (exp_append_bytes(export, string, strlen(string), control));
}
// This is an interface for passing chars to append_bytes
int exp_append_char(Export *export, char c, int control) {
    return (exp_append_bytes(export, &c, 1),control);
}

// for builder
int builder_ensure_capacity(Builder *builderr, size_t extra, int control)
{
    size_t needed;
    size_t capacity;

    switch (control) {
        case 0: {
            needed = builderr->memKeyScratch.length + extra;
            if (needed <= builderr->memKeyScratch.capacity) {
                return 0;
            }
            capacity = builderr->memKeyScratch.capacity ? builderr->memKeyScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->memKeyScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->memKeyScratch.data = tmp;
            builderr->memKeyScratch.capacity = capacity;
            return 0;
        }
        case 1: {
            needed = builderr->assocScratch.length + extra;
            if (needed <= builderr->assocScratch.capacity) {
                return 0;
            }
            capacity = builderr->assocScratch.capacity ? builderr->assocScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->assocScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->assocScratch.data = tmp;
            builderr->assocScratch.capacity = capacity;
            return 0;
            break;
        }
        case 2: {
            needed = builderr->associatorScratch.length + extra;
            if (needed <= builderr->associatorScratch.capacity) {
                return 0;
            }
            capacity = builderr->associatorScratch.capacity ? builderr->associatorScratch.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->associatorScratch.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->associatorScratch.data = tmp;
            builderr->associatorScratch.capacity = capacity;
            return 0;

            break;
        }
        case 3: {
            needed = builderr->wC.length + extra;
            if (needed <= builderr->wC.capacity) {
                return 0;
            }
            capacity = builderr->wC.capacity ? builderr->wC.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(builderr->wC.data, capacity);
            if (!tmp) {
                return -1;
            }
            builderr->wC.data = tmp;
            builderr->wC.capacity = capacity;
            return 0;
            break;
        }
        default:
            return -1;
            break;
    }
}

// builder appending
int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control)
{
    if (builder_ensure_capacity(builderr, x, control) != 0) {
        return -1; // failure
    }
    switch (control) {
        case 0:
            memcpy(builderr->memKeyScratch.data + builderr->memKeyScratch.length, byte, x);
            builderr->memKeyScratch.length += x;
            return 0;
            break;
        case 1:
            memcpy(builderr->associatorScratch.data + builderr->associatorScratch.length, byte, x);
            builderr->associatorScratch.length += x;
            return 0;
            break;
        case 2:
            memcpy(builderr->assocScratch.data + builderr->assocScratch.length, byte, x);
            builderr->assocScratch.length += x;
            return 0;
            break;
        case 3:
            memcpy(builderr->wC.data + builderr->wC.length, byte, x);
            builderr->wC.length += x;
            return 0;
            break;
        default:
            perror("Default error");
            exit(EXIT_FAILURE);
    }
}

// This is an interface for passing a string to append bytes
int builder_append_string(Builder *builderr, char *string, size_t x, int control) {
    return (builder_append_bytes(builderr, string, strlen(string), control));
}
// This is an interface for passing chars to append_bytes
int builder_append_char(Builder *builderr, char c, int control) {
    return (builder_append_bytes(builderr, &c,sizeof(&c), control));
}

// pbuffers appending
int pbuff_ensure_capacity(ParserBuffers *pbuffer, size_t extra, int control)
{
    size_t needed;
    size_t capacity;

    switch (control) {
        case 0: {
            needed = pbuffer->compArray.length + extra;
            if (needed <= pbuffer->compArray.capacity) {
                return 0;
            }
            capacity = pbuffer->compArray.capacity ? pbuffer->compArray.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(pbuffer->compArray.data, capacity);
            if (!tmp) {
                return -1;
            }
            pbuffer->compArray.data = tmp;
            pbuffer->compArray.capacity = capacity;
            return 0;
        }
        case 1: {
            needed = pbuffer->compBuffer.length + extra;
            if (needed <= pbuffer->compBuffer..capacity) {
                return 0;
            }
            capacity = pbuffer->compBuffer.capacity ? pbuffer->compBuffer..capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(pbuffer->compBuffer.data, capacity);
            if (!tmp) {
                return -1;
            }
            pbuffer->compBuffer.data = tmp;
            pbuffer->compBuffer.capacity = capacity;
            return 0;
            break;
        }
        case 2: {
            needed = pbuffer->Buffers.length + extra;
            if (needed <= pbuffer->Buffers.capacity) {
                return 0;
            }
            capacity = pbuffer->Buffers.capacity ? pbuffer->Buffers.capacity : 16;
            while (needed > capacity) {
                capacity *= 2;
            }
            char *tmp = realloc(pbuffer->Buffers.data, capacity);
            if (!tmp) {
                return -1;
            }
            pbuffer->Buffers.data = tmp;
            pbuffer->Buffers.capacity = capacity;
            return 0;

            break;
        }
        default:
            return -1;
            break;
    }
}

// builder appending
int builder_append_bytes(Builder *builderr, char *byte, size_t x, int control)
{
    if (builder_ensure_capacity(builderr, x, control) != 0) {
        return -1; // failure
    }
    switch (control) {
        case 0:
            memcpy(builderr->memKeyScratch.data + builderr->memKeyScratch.length, byte, x);
            builderr->memKeyScratch.length += x;
            return 0;
            break;
        case 1:
            memcpy(builderr->associatorScratch.data + builderr->associatorScratch.length, byte, x);
            builderr->associatorScratch.length += x;
            return 0;
            break;
        case 2:
            memcpy(builderr->assocScratch.data + builderr->assocScratch.length, byte, x);
            builderr->assocScratch.length += x;
            return 0;
            break;
        case 3:
            memcpy(builderr->wC.data + builderr->wC.length, byte, x);
            builderr->wC.length += x;
            return 0;
            break;
        default:
            perror("Default error");
            exit(EXIT_FAILURE);
    }
}

// This is an interface for passing a string to append bytes
int builder_append_string(Builder *builderr, char *string, size_t x, int control) {
    return (builder_append_bytes(builderr, string, strlen(string), control));
}
// This is an interface for passing chars to append_bytes
int builder_append_char(Builder *builderr, char c, int control) {
    return (builder_append_bytes(builderr, &c,sizeof(&c), control));
}