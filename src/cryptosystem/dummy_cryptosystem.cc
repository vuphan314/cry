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

void DummyCryptosystem::cryptanalyze() {

}

// public:
// public overloaded methods:

void DummyCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  publicKey.push_back(publicAddend);
  privateKey.push_back(secretAddend);
}

void DummyCryptosystem::encrypt(
  PaddedText &paddedCipherText, const Text &plainText,
  const Key &publicKey) {

}

void DummyCryptosystem::decrypt(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &privateKey) {}

void DummyCryptosystem::cryptanalyze(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &publicKey) {}
