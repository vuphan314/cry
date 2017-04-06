#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
private:
  KeyElement modulus, // n, cryptographically public
    publicExponent, // e, cryptographically public
    privateExponent; // d, cryptographically private
  Text plainText, cipherText;
  PaddedText paddedPlainText, paddedCipherText;

// private helper methods:
  void setPublicKeyElements(const Key &publicKey);

  void setPrivateKeyElements(const Key &privateKey);

// private overloaded methods:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent

  void encrypt();
    // set: cipherText
    // read: plainText, modulus, publicExponent

  void decrypt();
    // set: plainText
    // read: cipherText, modulus, privateExponent

  void cryptanalyze();
    // set: plainText
    // read: cipherText, modulus, publicExponent

public:
// public overloaded methods:
  void generateKeys(
    Key &publicKey, Key &privateKey); // set these

  void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey);

  void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
