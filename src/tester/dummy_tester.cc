#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester() {
  cryptosystem = new DummyCryptosystem;
}

Bool DummyTester::testKeyGeneration() {
  std::cout << "method DummyTester::testKeyGeneration\n";
  return TRUE;
}

Bool DummyTester::testEncryption() {
  std::cout << "method DummyTester::testEncryption\n";
  return TRUE;
}

Bool DummyTester::testDecryption() {
  std::cout << "method DummyTester::testDecryption\n";
  return TRUE;
}

Bool DummyTester::testCryptanalysis() {
  std::cout << "method DummyTester::testCryptanalysis\n";
  return TRUE;
}
