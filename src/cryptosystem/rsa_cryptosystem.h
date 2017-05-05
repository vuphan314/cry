#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

const SizeT DEFAULT_PUBLIC_EXPONENT = 65537;
const SizeT DEFAULT_MIN_MODULUS_LENGTH = 256;

// const SizeT BREAKABLE_MIN_MODULUS_LENGTH = 32;
const SizeT BREAKABLE_MIN_MODULUS_LENGTH = 46;
const Text BREAKABLE_PLAIN_TEXT = "four";

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
  SizeT getMaxTextLength();
    // read: minModulusLength

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
  RsaCryptosystem(SizeT minModulusLength =
    BREAKABLE_MIN_MODULUS_LENGTH);

// public overloaded methods:
  void generateKeys(
    Key &publicKey, Key &privateKey); // set these

  void encrypt(PaddedText &paddedCipherText, // set this
    const Text &plainText, const Key &publicKey);
    // check minModulusLength

  void decrypt(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &privateKey);

  void cryptanalyze(Text &plainText, // set this
    const PaddedText &paddedCipherText,
    const Key &publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
