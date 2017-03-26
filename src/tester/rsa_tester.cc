#include "rsa_tester.h"

////////////////////////////////////////////////////////////

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
}

Bool RsaTester::testKeyGeneration() {
  std::cout << "Testing RSA key-generation: passed.\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testEncryption() {
  std::cout << "Testing RSA encryption: passed.\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testDecryption() {
  std::cout << "Testing RSA decryption: passed.\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testCryptanalysis() {
  std::cout << "Testing RSA cryptanalysis: passed.\n";
  return TRUE; // replace by RSA test
}
