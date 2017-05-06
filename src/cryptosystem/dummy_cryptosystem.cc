#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////
// class DummyCryptosystem:

// protected:

// protected helper methods:

void DummyCryptosystem::setPublicKeyElements(
    const Key &publicKey) {
  RsaCryptosystem::setPublicKeyElements(publicKey);
  publicFactor = publicKey.at(2);
}

void DummyCryptosystem::setPrivateKeyElements(
    const Key &privateKey) {
  RsaCryptosystem::setPrivateKeyElements(privateKey);
  secretFactor = privateKey.at(2);
}

void DummyCryptosystem::recoverPrivateKeyElements() {
  RsaCryptosystem::recoverPrivateKeyElements();

  PaddedText tmp = paddedCipherText;
    // previously set by public method cryptanalyze

  paddedCipherText = publicFactor;
  RsaCryptosystem::decrypt();
  secretFactor = paddedPlainText;

  paddedCipherText = tmp;
}

// protected overloaded methods:

void DummyCryptosystem::generateKeys() {
  RsaCryptosystem::generateKeys();

  gmp_randstate_t randomState;
  seedRandomState(randomState);
  mpz_t newSecretFactor;
  mpz_init(newSecretFactor);
  mpz_urandomb(newSecretFactor, randomState,
    DEFAULT_MAX_SECRET_FACTOR_LENGTH);

  paddedPlainText = PaddedText(newSecretFactor);
  RsaCryptosystem::encrypt();
  publicFactor = paddedCipherText;
  secretFactor = paddedPlainText;
}

void DummyCryptosystem::encrypt() {
  paddedCipherText = paddedPlainText * secretFactor;
}

void DummyCryptosystem::decrypt() {
  paddedPlainText = paddedCipherText / secretFactor;
}

void DummyCryptosystem::cryptanalyze() {
  recoverPrivateKeyElements();
  decrypt();
}

// public:

// public overloaded methods:

void DummyCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey, const SizeT &strength) {
  this->minModulusLength = strength;
  generateKeys();
  publicKey = {modulus, publicExponent, publicFactor};
  privateKey = {modulus, privateExponent, secretFactor};
}

void DummyCryptosystem::encrypt(
    PaddedText &paddedCipherText, const Text &plainText,
    const Key &publicKey) {
  setPublicKeyElements(publicKey);
  padText(paddedPlainText, plainText);
  encrypt();
  paddedCipherText = this->paddedCipherText;
}

void DummyCryptosystem::decrypt(Text &plainText,
    const PaddedText &paddedCipherText,
    const Key &privateKey) {
  setPrivateKeyElements(privateKey);
  this->paddedCipherText = paddedCipherText;
  decrypt();
  unpadText(plainText, paddedPlainText);
}

void DummyCryptosystem::cryptanalyze(Text &plainText,
    const PaddedText &paddedCipherText,
    const Key &publicKey) {
  setPublicKeyElements(publicKey);
  this->paddedCipherText = paddedCipherText;
  cryptanalyze();
  unpadText(plainText, paddedPlainText);
}
