#ifndef __aries__did__included__
#define __aries__did__included__

#include <stdint.h>

extern int32_t aries_did_create(int32_t wallet_handle,
                         const char* const did_options_json,
                         const char* did,
                         const char* vk,
                         const struct ExternError* err);
 
extern int32_t aries_did_store(int32_t wallet_handle,
                        const char* const did_json,
                        const struct ExternError* err);
 
extern int32_t aries_did_update(int32_t wallet_handle,
                         const char* const did_update_json,
                         const struct ExternError* err);
 
extern int32_t aries_did_delete(int32_t wallet_handle,
                         const char* const did,
                         const struct ExternError* err);
 
// Originally wanted to combine ledger reads and wallet reads into one
// method. This is unreasonable since we need to have both wallet and ledger
// info passed in when only one of the two will be used. Splitting it up.
// what if ledger info is optional?
int32_t aries_did_read(int32_t wallet_handle,
                       const char* const did,
                       const char* did_doc,
                       const struct ExternError* err);

/**
 * Resolve a DID Doc from a ledger.
 */
int32_t aries_did_resolve(int32_t resolver_handle,
                          const char* const did,
                          const char* did_doc,
                          const struct ExternError* err); 
 
int32_t aries_did_commit(int32_t wallet_handle,
                         int32_t resolver_handle,
                         const char* const did,
                         const char* did_doc,
                         const struct ExternError* err);
 
// not mutable
//did_context_set()
// Don't think this makes sense to include. It is always the same.
//int32_t did_context_get()
int32_t aries_did_authentication_add(int32_t wallet_handle,
                                     const char* const did,
                                     const char* const authentication,
                                     const struct ExternError* err);
 
int32_t aries_did_authentication_get(int32_t wallet_handle,
                                     const char* const did,
                                     const char* const index, // should this be auth key id?
                                     const struct ExternError* err);
 
int32_t aries_did_authentication_remove(int32_t wallet_handle,
                                        const char* const did,
                                        const char* const authentication, //object or string to be removed
                                        const struct ExternError* err);
 
int32_t aries_did_authentication_list(int32_t wallet_handle,
                                      const char* const did,
                                      const struct ExternError* err);
 
int32_t aries_did_key_add(int32_t wallet_handle,
                          const char* const did,
                          const char* const key,
                          const struct ExternError* err);
 
int32_t aries_did_key_get(int32_t wallet_handle,
                          const char* const did,
                          const char* const key_id, // should this be a index
                          const char* key, 
                          const struct ExternError* err);
 
int32_t aries_did_key_remove(int32_t wallet_handle,
                             const char* const did,
                             const char* const key_id,
                             const struct ExternError* err);
 
int32_t aries_did_key_list(int32_t wallet_handle,
                           const char* const did,
                           const char* keys,
                           const struct ExternError* err);
 
int32_t aries_did_service_add(int32_t wallet_handle,
                              const char* const did,
                              const char* const service,
                              const struct ExternError* err);
 
int32_t aries_did_service_get(int32_t wallet_handle,
                              const char* const did, 
                              const char* const service_id, // should this be a index
                              const char* service, 
                              const struct ExternError* err);
 
int32_t aries_did_service_remove(int32_t wallet_handle,
                                 const char* const did, 
                                 const char* const service_id, // should this be a index or object
                                 const struct ExternError* err);
 
int32_t aries_did_service_list(int32_t wallet_handle,
                               const char* const did,
                               const char* services,
                               const struct ExternError* err);
 
int32_t aries_abbreviate_verkey(const char* const verkey,
                                const char* abbreviated_key,
                                const struct ExternError* err);
#endif
