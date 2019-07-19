
/// Creates keys (signing and encryption keys) for a new
/// DID (owned by the caller of the library).
/// Identity's DID must be either explicitly provided, or taken as the first 16 bit of verkey.
/// Saves the Identity DID with keys in a secured Wallet, so that it can be used to sign
/// and encrypt transactions.
///
/// #Params
/// wallet_handle: wallet handler (created by open_wallet).
/// command_handle: command handle to map callback to user context.
/// did_info: Identity information as json. See domain::crypto::did::MyDidInfo
/// Example:
/// {
///     "did": string, (optional;
///             if not provided and cid param is false then the first 16 bit of the verkey will be used as a new DID;
///             if not provided and cid is true then the full verkey will be used as a new DID;
///             if provided, then keys will be replaced - key rotation use case)
///     "seed": string, (optional) Seed that allows deterministic did creation (if not set random one will be created).
///                                Can be UTF-8, base64 or hex string.
///     "crypto_type": string, (optional; if not set then ed25519 curve is used;
///               currently only 'ed25519' value is supported for this field)
///     "cid": bool, (optional; if not set then false is used;)
/// }
/// cb: Callback that takes command result as parameter.
///
/// #Returns
/// Error Code
/// cb:
/// - command_handle_: Command handle to map callback to caller context.
/// - err: Error code.
///   did: DID generated and stored in the wallet
///   verkey: The DIDs verification key
///
/// #Errors
/// Common*
/// Wallet*
/// Crypto*
/// int32_t wallet_handle,
                         const char* const did_options_json,
                         const char* did,
                         const char* vk,
                         const struct ExternError* err
#[no_mangle]
pub  extern fn indy_create_and_store_my_did(wallet_handle: WalletHandle,
                                            did_options_json: *const c_char,
                                            did: *const c_char,
                                            vk: *const c_char
                                            err: *const c_struct) -> ErrorCode {

}