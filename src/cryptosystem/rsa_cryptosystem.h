#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
public:
  void generateKeys(Key publicKey, Key privateKey); // set these

  void encrypt(Text ciphertext, // set this
    const Text plaintext, const Key publicKey);

  void decrypt(Text plaintext, // set this
    const Text ciphertext, const Key privateKey);

  void cryptanalyze(Text plaintext, // set this
    const Text ciphertext, const Key publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
