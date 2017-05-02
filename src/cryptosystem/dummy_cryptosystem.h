#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

const long DEFAULT_SECRET_ADDEND = 42;
  // constructor mpz_class rejects long long

////////////////////////////////////////////////////////////

class DummyCryptosystem : public RsaCryptosystem {
protected:
  KeyElement publicAddend, // E
    secretAddend; // D
    // publicKey = (n, d, D)
    // privateKey = (n, e, E)

// protected helper methods:
  void setPublicKeyElements(const Key &publicKey);
    // set: modulus, publicExponent, publicAddend

  void setPrivateKeyElements(const Key &privateKey);
    // set: modulus, privateExponent, secretAddend

  void recoverPrivateKeyElements();
    // set: privateExponent, secretAddend
    // read: modulus, publicExponent, publicAddend

// protected overloaded methods:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent,
    // publicAddend, secretAddend

  void encrypt();
    // set: paddedCipherText
    // read: paddedPlainText, secretAddend

  void decrypt();
    // set: paddedPlainText
    // read: paddedCipherText, secretAddend

  // void cryptanalyze();
    // set: paddedPlainText
    // read: paddedCipherText, modulus, publicExponent,
    // publicAddend

public:
// public overloaded methods:
  void generateKeys(
    Key &publicKey, Key &privateKey); // set these

  void encrypt(PaddedText &paddedCipherText, // set this
    const Text &plainText, const Key &publicKey);

  // void decrypt(Text &plainText, // set this
  //   const PaddedText &paddedCipherText,
  //   const Key &privateKey);

  // void cryptanalyze(Text &plainText, // set this
  //   const PaddedText &paddedCipherText,
  //   const Key &publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
