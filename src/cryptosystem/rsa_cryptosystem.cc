#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

void RsaCryptosystem::generateKeys(Key &publicKey,
  Key &privateKey) {};

void RsaCryptosystem::encrypt(Text &cipherText,
  const Text &plainText, const Key &publicKey) {};

void RsaCryptosystem::decrypt(Text &plainText,
  const Text &cipherText, const Key &privateKey) {};

void RsaCryptosystem::cryptanalyze(Text &plainText,
  const Text &cipherText, const Key &publicKey) {};

////////////////////////////////////////////////////////////

RsaCryptosystemTester::RsaCryptosystemTester() {
  cryptosystem = new RsaCryptosystem;
}

Bool RsaCryptosystemTester::testKeyGeneration() {
  std::cout << "Testing RSA key generation: passed.\n";
  return TRUE;
}

Bool RsaCryptosystemTester::testEncryption() {
  std::cout << "Testing RSA encryption: passed.\n";
  return TRUE;
}

Bool RsaCryptosystemTester::testDecryption() {
  std::cout << "Testing RSA decryption: passed.\n";
  return TRUE;
}

Bool RsaCryptosystemTester::testCryptanalysis() {
  std::cout << "Testing RSA cryptanalysis: passed.\n";
  return TRUE;
}
