#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
private:
  KeyElement modulus, // n, public
    publicExponent, // e, public
    privateExponent; // d, private
  Text plainText, cipherText;
  PaddedText paddedPlainText, paddedCipherText; // temporary

// overloaded:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent

  void encrypt();
    // set: cipherText
    // get: plainText, modulus, publicExponent

  void decrypt();
    // set: plainText
    // get: cipherText, modulus, privateKey

  void cryptanalyze();
    // set: plainText
    // get: cipherText, modulus, publicKey

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
  Bool testCryptosystem();
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
