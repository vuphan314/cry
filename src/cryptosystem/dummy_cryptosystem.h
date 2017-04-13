#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class DummyCryptosystem : public Cryptosystem {
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
