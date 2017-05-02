#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester(SizeT minModulusLength) {
  cryptosystem = new DummyCryptosystem(minModulusLength);
}

Bool DummyTester::testCryptosystem(Text plainText) {
  std::cout << "method DummyTester::testCryptosystem\n";

  std::cout << "key-generation\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  std::cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) <<
    "\n\tpublic addend: " << publicKey.at(2) <<
    "\n\tsecret addend: " << privateKey.at(2) << "\n";

  return TRUE;
}
