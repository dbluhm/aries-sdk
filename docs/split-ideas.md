Aries SDK Split Ideas
=====================

*Idea:* Aries "core" library, "Optional" wallet

At its core, the Aries library performs the cryptographic operations needed for
Identity Owners to represent themselves in a Self-Sovereign Identity world.
Ultimately, these core cryptographic operations are quite simple (or, rather,
our crypto libraries make them simple) -- creating a DID and Keys, ECDSA, ECDHE,
Symmetric Encryption (only one type for now, a need to expand to support
other encryption types), AnonCreds (made simpler, at least, thanks to Ursa),
etc.

While making the crypto calls are relatively simple, the process of storing and
recalling the information across sessions is not. The wallet is arguably the
most complex component of the Indy SDK that needs to be moved to the Aries SDK.
This complexity is not an unnecessary burden -- there is obviously a need for
secure, persistent storage on which we build the foundations of cryptographic
trust which, in turn, leads to human trust. However, here it is proposed that
the core cryptographic functionality of the SDK and Wallet be split to make two
distinct components that, separated, are more easily maintained. In addition,
this split accommodates more Agent/Aries use cases.

Aries Core Library
------------------
The Aries Core Library is a stateless library responsible for creating crypto
objects and then performing operations with those objects. For example, creating
a DID with the Core library might look something like this (in Python):

```python
from aries import did

my_did, my_vk, my_sk = did.create({'seed': '...', 'type': '...'})
```

Then, using the core library to, for instance, pack a message:

```python
from aries import crypto

packed_msg = crypto.pack_message(msg, [their_vk], my_vk, my_sk)
```

If you're familiar with the Aries Static Agent Python library, these kinds of
calls look very familiar. Static Agents are an excellent example of where having
a separate artifact with just core cryptographic functions is very convenient.
Instead of having multiple implementations in multiple languages, a core library
could create a path to more unified crypto across languages. Additionally, the
slimmed down nature of this core library means fewer dependencies and a higher
likelihood of being able to create more portable binaries and a WASM build.

> **Note:** The example shown here is quite simple and recreating the crypto in
> each language is truthfully not very complicated. However, potentially giving
> each static agent implementation the ability to verify a credential along with
> other interesting crypto operations are a compelling possibilities.

Optional Wallet
---------------
The wallet is an optional cargo feature of the Aries Library. It is proposed
that this feature disables the standard C Callable API of the core library and
enables another C Callable API that provides the full functionality of the Aries
Library with secure data persistence. The Wallet Enabled API essentially wraps
the Core API, providing data for the API calls to achieve certain actions and
storing the results of the calls as necessary.

It is proposed that the Wallet be maintained as a separate codebase from the
Aries Core. Separating the Wallet from the Core allows us to cleanly separate
the complexities of successfully executing the crypto from the complexities of
storing and recalling information. In the near future, the wallet needs support
for more structurally complex Schemas as part of the Rich Schema effort, DID
Docs and DID Doc update deltas as part of the peer DID method effort, and other
convenience improvements. A separate codebase that can rev independent of the
Core can make the addition of these features simpler.
