#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

const SizeT DEFAULT_PRIVATE_ADDEND = 42;

////////////////////////////////////////////////////////////

#include "cryptosystem.h"
#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

class DummyCryptosystem : public Cryptosystem {
private:
  KeyElement modulus, // n
    publicExponent, // e
    privateExponent, // d
    publicAddend, // E
    privateAddend; // D
    // publicKey = (n, d, D)
    // privateKey = (n, e, E)

public:
  void generateKeys(
    Key &publicKey, Key &privateKey, // set these
    SizeT keyElementLength);

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
