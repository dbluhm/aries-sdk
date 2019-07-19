#ifndef __indy__resolver__included__
#define __indy__resolver__included__

#include <stdint.h>

typedef enum {
    SUCCESS = 0,
    CONTEXT_CREATE_FAIL = 1,
    INVALID_DID = 2,
} indy_res_status_t;

struct ByteBuffer {
    int64_t len;
    uint8_t *data;
};

struct ExternError {
    indy_res_status_t code;
    char* message;
};


#ifdef __cplusplus
extern "C" {
#endif
}

//Put other header file includes here
#include "aries_sdk_did.h"

#ifdef __cplusplus

#endif

#endif
