/// writes a context to a ledger.
/// TODO: document this...
///
#[no_mangle]
pub  extern fn aries_context_commit(wallet_handle: WalletHandle,
                                            did: *const c_char,
                                            context_json: *const c_char,
                                            err: *const c_struct) -> ErrorCode {
// TODO: write this code... 
}
