#ifndef CRYPTOSYSTEM_RSA_H_
#define CRYPTOSYSTEM_RSA_H_

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class Rsa : public Cryptosystem {
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

#endif // CRYPTOSYSTEM_RSA_H_
