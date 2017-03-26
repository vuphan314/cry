#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////

void DummyCryptosystem::generateKeys(Key &publicKey,
  Key &privateKey) {};

void DummyCryptosystem::encrypt(Text &cipherText,
  const Text &plainText, const Key &publicKey) {};

void DummyCryptosystem::decrypt(Text &plainText,
  const Text &cipherText, const Key &privateKey) {};

void DummyCryptosystem::cryptanalyze(Text &plainText,
  const Text &cipherText, const Key &publicKey) {};

////////////////////////////////////////////////////////////

DummyCryptosystemTester::DummyCryptosystemTester() {
  cryptosystem = new DummyCryptosystem;
}

Bool DummyCryptosystemTester::testKeyGeneration() {
  std::cout << "Testing dummy key generation: passed.\n";
  return TRUE;
}

Bool DummyCryptosystemTester::testEncryption() {
  std::cout << "Testing dummy encryption: passed.\n";
  return TRUE;
}

Bool DummyCryptosystemTester::testDecryption() {
  std::cout << "Testing dummy decryption: passed.\n";
  return TRUE;
}

Bool DummyCryptosystemTester::testCryptanalysis() {
  std::cout << "Testing dummy cryptanalysis: passed.\n";
  return TRUE;
}
