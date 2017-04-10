#ifndef CRYPTOSYSTEM_RSACRYPTOSYSTEM_H
#define CRYPTOSYSTEM_RSACRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include "cryptosystem.h"

////////////////////////////////////////////////////////////

const Text BREAKABLE_PLAIN_TEXT = "0123"; // 01234
const SizeT BREAKABLE_MIN_MODULUS_LENGTH = 32; // 46

const SizeT DEFAULT_MIN_MODULUS_LENGTH = 256;
const SizeT DEFAULT_PUBLIC_EXPONENT = 65537;
const SizeT DEFAULT_SEED = 672087;

////////////////////////////////////////////////////////////

class RsaCryptosystem : public Cryptosystem {
private:
  KeyElement modulus, // n, cryptographically public
    publicExponent, // e, cryptographically public
    privateExponent; // d, cryptographically private
  PaddedText paddedPlainText, paddedCipherText;

// private helper methods:
  void setPublicKeyElements(const Key &publicKey);
    // set: modulus, publicExponent

  void setPrivateKeyElements(const Key &privateKey);
    // set: modulus, privateExponent

// private overloaded methods:
  void generateKeys(SizeT minModulusLength);
    // set: modulus, publicExponent, privateExponent

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
    SizeT minModulusLength);

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
