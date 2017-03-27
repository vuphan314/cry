#include "rsa_tester.h"

////////////////////////////////////////////////////////////

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
}

Bool RsaTester::testKeyGeneration() {
  std::cout << "method RsaTester::testKeyGeneration\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testEncryption() {
  std::cout << "method RsaTester::testEncryption\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testDecryption() {
  std::cout << "method RsaTester::testDecryption\n";
  return TRUE; // replace by RSA test
}

Bool RsaTester::testCryptanalysis() {
  std::cout << "method RsaTester::testCryptanalysis\n";
  return TRUE; // replace by RSA test
}
