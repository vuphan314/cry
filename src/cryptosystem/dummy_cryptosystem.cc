#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////
// class DummyCryptosystem:

// protected:

// protected helper methods:

void DummyCryptosystem::setPublicKeyElements(
    const Key &publicKey) {
  RsaCryptosystem::setPublicKeyElements(publicKey);
  publicAddend = publicKey.at(2);
}

void DummyCryptosystem::setPrivateKeyElements(
    const Key &privateKey) {
  RsaCryptosystem::setPrivateKeyElements(privateKey);
  secretAddend = privateKey.at(2);
}

void DummyCryptosystem::recoverPrivateKeyElements() {
  RsaCryptosystem::recoverPrivateKeyElements();
  paddedCipherText = publicAddend;
  RsaCryptosystem::decrypt();
  secretAddend = paddedPlainText;
}

// protected overloaded methods:

void DummyCryptosystem::generateKeys() {
  DummyCryptosystem::generateKeys();
  paddedPlainText = DEFAULT_SECRET_ADDEND;
  DummyCryptosystem::encrypt();
  publicAddend = paddedCipherText;
  secretAddend = paddedPlainText;
}

void DummyCryptosystem::encrypt() {
  paddedCipherText = paddedPlainText + secretAddend;
}

void DummyCryptosystem::decrypt() {
  paddedPlainText = paddedCipherText - secretAddend;
}

// void DummyCryptosystem::cryptanalyze() {
//   recoverPrivateKeyElements();
//   decrypt();
// }

// public:

// public overloaded methods:

void DummyCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  generateKeys();
  publicKey = {modulus, publicExponent, publicAddend};
  privateKey = {modulus, privateExponent, secretAddend};
}

void DummyCryptosystem::encrypt(
    PaddedText &paddedCipherText, const Text &plainText,
    const Key &publicKey) {
  setPublicKeyElements(publicKey);
  padText(paddedPlainText, plainText);
  encrypt();
  paddedCipherText = this->paddedCipherText;
}

// void DummyCryptosystem::decrypt(Text &plainText,
//     const PaddedText &paddedCipherText,
//     const Key &privateKey) {
//   setPrivateKeyElements(privateKey);
//   this->paddedCipherText = paddedCipherText;
//   decrypt();
//   unpadText(plainText, paddedPlainText);
// }

// void DummyCryptosystem::cryptanalyze(Text &plainText,
//     const PaddedText &paddedCipherText,
//     const Key &publicKey) {
//   setPublicKeyElements(publicKey);
//   this->paddedCipherText = paddedCipherText;
//   cryptanalyze();
//   unpadText(plainText, paddedPlainText);
// }
