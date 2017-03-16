#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
public:
  void generateKeys(Key &publicKey, Key &privateKey);
    // set these

  void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey);

  void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey);

// testing:
  // void testCryptosystem();
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
