#ifndef CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
#define CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

const SizeT DEFAULT_MAX_SECRET_FACTOR_LENGTH = 24;

////////////////////////////////////////////////////////////

class DummyCryptosystem : public RsaCryptosystem {
protected:
  KeyElement publicFactor, // E
    secretFactor; // D
    // publicKey = (n, e, E)
    // privateKey = (n, d, D)

// protected helper methods:
  void setPublicKeyElements(const Key &publicKey);
    // set: modulus, publicExponent, publicFactor

  void setPrivateKeyElements(const Key &privateKey);
    // set: modulus, privateExponent, secretFactor

  void recoverPrivateKeyElements();
    // set: privateExponent, secretFactor
    // read: modulus, publicExponent, publicFactor

// protected overloaded methods:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent,
    //  publicFactor, secretFactor

  void encrypt();
    // set: paddedCipherText
    // read: paddedPlainText, secretFactor

  void decrypt();
    // set: paddedPlainText
    // read: paddedCipherText, secretFactor

  void cryptanalyze();
    // set: paddedPlainText
    // read: paddedCipherText, modulus, publicExponent,
    //  publicFactor

public:
// public overloaded methods:
  void generateKeys(
    Key &publicKey, Key &privateKey, // set these
    const SizeT &strength = TRIVIAL_STRENGTH);
    // set minModulusLength

  void encrypt(PaddedText &paddedCipherText, // set this
    const Text &plainText, const Key &publicKey,
    const SizeT &strength = TRIVIAL_STRENGTH);

  void decrypt(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_DUMMYCRYPTOSYSTEM_H
