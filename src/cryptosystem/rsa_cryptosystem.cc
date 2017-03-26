#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

void RsaCryptosystem::setPublicKeyElements(
    const Key &publicKey) {
  modulus = publicKey.at(0);
  publicExponent = publicKey.at(1);
}

void RsaCryptosystem::setPrivateKeyElements(
    const Key &privateKey) {
  modulus = privateKey.at(0);
  privateExponent = privateKey.at(1);
}

////////////////////////////////////////////////////////////
// private overloaded methods

void RsaCryptosystem::generateKeys() {
// add actual key generation:
  modulus = 3233;
  publicExponent = 17;
  privateExponent = 413;
}

void RsaCryptosystem::encrypt() {
  padText(paddedPlainText, plainText);
  paddedCipherText = paddedPlainText;
    // replace the line above by actual encyption
  unpadText(cipherText, paddedCipherText);
}

void RsaCryptosystem::decrypt() {
  padText(paddedCipherText, cipherText);
  paddedPlainText = paddedCipherText;
    // replace the line above by actual decryption
  unpadText(plainText, paddedPlainText);
}

void RsaCryptosystem::cryptanalyze() {
  padText(paddedCipherText, cipherText);
  paddedPlainText = paddedCipherText;
    // replace the line above by actual cryptanalysis
  unpadText(plainText, paddedPlainText);
}

////////////////////////////////////////////////////////////
// public overloaded methods

void RsaCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  generateKeys();
  publicKey = {modulus, publicExponent};
  privateKey = {modulus, privateExponent};
}

void RsaCryptosystem::encrypt(Text &cipherText,
    const Text &plainText, const Key &publicKey) {
  this->plainText = plainText;
  setPublicKeyElements(publicKey);
  encrypt();
  cipherText = this->cipherText;
}

void RsaCryptosystem::decrypt(Text &plainText,
    const Text &cipherText, const Key &privateKey) {
  this->cipherText = cipherText;
  setPrivateKeyElements(privateKey);
  decrypt();
  plainText = this->plainText;
}

void RsaCryptosystem::cryptanalyze(Text &plainText,
    const Text &cipherText, const Key &publicKey) {
  this->cipherText = cipherText;
  setPublicKeyElements(publicKey);
  cryptanalyze();
  plainText = this->plainText;
}

////////////////////////////////////////////////////////////

RsaCryptosystemTester::RsaCryptosystemTester() {
  cryptosystem = new RsaCryptosystem;
}

Bool RsaCryptosystemTester::testKeyGeneration() {
  std::cout << "Testing RSA key generation: passed.\n";
  return TRUE; // add actual test
}

Bool RsaCryptosystemTester::testEncryption() {
  std::cout << "Testing RSA encryption: passed.\n";
  return TRUE; // add actual test
}

Bool RsaCryptosystemTester::testDecryption() {
  std::cout << "Testing RSA decryption: passed.\n";
  return TRUE; // add actual test
}

Bool RsaCryptosystemTester::testCryptanalysis() {
  std::cout << "Testing RSA cryptanalysis: passed.\n";
  return TRUE; // add actual test
}
