#ifndef __aries__did__included__
#define __aries__did__included__

#include <stdint.h>

extern int32_t aries_schema_validate(const char* const schema,
                                     const struct ExternError* err);

extern int32_t aries_schema_commit(int32_t wallet_handle,
                                   const char* const did,
                                   const char* schema_json,
                                   const struct ExternError* err);

extern int32_t aries_context_validate(const char* const context,
                                      const struct ExternError* err);

extern int32_t aries_context_commit(int32_t wallet_handle,
                                    const char* const did,
                                    const char* context_json,
                                    const struct ExternError* err);

extern int32_t aries_mapping_validate(const char* const mapping,
                                      const struct ExternError* err);

extern int32_t aries_mapping_commit(int32_t wallet_handle,
                                    const char* const did,
                                    const char* mapping_json,
                                    const struct ExternError* err);

extern int32_t aries_encoding_validate(const char* const encoding,
                                       const struct ExternError* err);

 /* Encodings:
 * UTF-8_SHA-256
 * DateRFC3339_SecondsSince1970
 * DateRFC3339_DaysSince1900
 * HeightISO18013_HeightInInches
 * Double_BigDecimal
 * 32Integer_256Integer
 */                                       
extern int32_t aries_encode_attribute(const char* const encoding,
                                      const char* const attribute,
                                      const char* encoded_attribute,
                                      const struct ExternError* err); 


extern int32_t aries_pres_def_validate(const char* const pres_def,
                                       const struct ExternError* err); 

extern int32_t aries_pres_def_commit(int32_t wallet_handle,
                                     const char* const did,
                                     const char* pres_def_json,
                                     const struct ExternError* err);

extern int32_t aries_cred_def_create(int32_t wallet_handle,
                                     const char* const cred_def_options_json,// mapping_id, schema_id, context_id,
                                     const char* const did,
                                     const char* cred_def,
                                     const struct ExternError* err);

extern int32_t aries_cred_def_commit(int32_t wallet_handle,
                                     const char* const did,
                                     const char* cred_def_json,
                                     const struct ExternError* err);
#endif
