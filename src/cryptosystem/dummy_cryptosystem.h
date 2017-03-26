#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class DummyCryptosystem : public Cryptosystem {
public:
  void generateKeys(
    Key &publicKey, Key &privateKey // set these
    );

  void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey);

  void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey);
};

////////////////////////////////////////////////////////////

class DummyCryptosystemTester : public CryptosystemTester {
public:
  // DummyCryptosystemTester();

  Bool testKeyGeneration();

  Bool testEncryption();

  Bool testDecryption();

  Bool testCryptanalysis();
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
