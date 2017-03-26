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

  void setPublicKeyElements(const Key &publicKey);

  void setPrivateKeyElements(const Key &privateKey);

// private overloaded methods:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent

  void encrypt();
    // set: cipherText
    // given: plainText, modulus, publicExponent

  void decrypt();
    // set: plainText
    // given: cipherText, modulus, privateExponent

  void cryptanalyze();
    // set: plainText
    // given: cipherText, modulus, publicExponent

public:
// public overloaded methods:
  void generateKeys(Key &publicKey, Key &privateKey);
    // set these

  void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey);

  void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey);
};

////////////////////////////////////////////////////////////

class RsaCryptosystemTester : public CryptosystemTester {
public:
  RsaCryptosystemTester();

  Bool testKeyGeneration();

  Bool testEncryption();

  Bool testDecryption();

  Bool testCryptanalysis();
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
