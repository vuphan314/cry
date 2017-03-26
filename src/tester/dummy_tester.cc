#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester() {
  cryptosystem = new DummyCryptosystem;
}

Bool DummyTester::testKeyGeneration() {
  std::cout << "Testing dummy key generation: passed.\n";
  return TRUE;
}

Bool DummyTester::testEncryption() {
  std::cout << "Testing dummy encryption: passed.\n";
  return TRUE;
}

Bool DummyTester::testDecryption() {
  std::cout << "Testing dummy decryption: passed.\n";
  return TRUE;
}

Bool DummyCryptosystemTester::testCryptanalysis() {
  std::cout << "Testing dummy cryptanalysis: passed.\n";
  return TRUE;
}
