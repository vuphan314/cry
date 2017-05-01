#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

const SizeT DEFAULT_PRIVATE_ADDEND = 42;

////////////////////////////////////////////////////////////

class DummyCryptosystem : public RsaCryptosystem {
private:
  KeyElement publicAddend, // E
    privateAddend; // D
    // publicKey = (n, d, D)
    // privateKey = (n, e, E)

public:
  void generateKeys(Key &publicKey, Key &privateKey);
    // set these

  void encrypt(PaddedText &paddedCipherText, // set this
    const Text &plainText, const Key &publicKey);

  void decrypt(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
