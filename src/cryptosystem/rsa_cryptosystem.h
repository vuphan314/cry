#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

const SizeT DEFAULT_PUBLIC_EXPONENT = 65537;

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
protected:
  SizeT minModulusLength;
  KeyElement modulus, // n
    publicExponent, // e
    privateExponent; // d
    // publicKey = (n, d)
    // privateKey = (n, e)
  PaddedText paddedPlainText, paddedCipherText;

// protected helper methods:
  void setPublicKeyElements(const Key &publicKey);
    // set: modulus, publicExponent

  void setPrivateKeyElements(const Key &privateKey);
    // set: modulus, privateExponent

  void recoverPrivateKeyElements();
    // set: privateExponent
    // read: modulus, publicExponent

// protected overloaded methods:
  void generateKeys();
    // set: modulus, publicExponent, privateExponent
    // read: minModulusLength

  void encrypt();
    // set: paddedCipherText
    // read: paddedPlainText, modulus, publicExponent

  void decrypt();
    // set: paddedPlainText
    // read: paddedCipherText, modulus, privateExponent

  void cryptanalyze();
    // set: paddedPlainText
    // read: paddedCipherText, modulus, publicExponent

public:
// public overloaded methods:
  void generateKeys(
    Key &publicKey, Key &privateKey, // set these
    const SizeT &strength = TRIVIAL_STRENGTH);
    // set minModulusLength

  void encrypt(PaddedText &paddedCipherText, // set this
    const Text &plainText, const Key &publicKey,
    const SizeT &strength = TRIVIAL_STRENGTH);
    // check plainText.size() against strength

  void decrypt(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &publicKey);
};

////////////////////////////////////////////////////////////
// global functions:

SizeT getMaxTextLength(const SizeT &strength);

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
