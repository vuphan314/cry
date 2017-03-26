#include "party.h"

////////////////////////////////////////////////////////////

Cryptosystem *getCryptosystem(
    CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA:
      return new RsaCryptosystem;
    case DUMMY:
      return new DummyCryptosystem;
    default:
      std::cout << "Wrong cryptosystem name.\n";
      throw std::exception();
  }
}

CryptosystemTester *getCryptosystemTester(
    CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA:
      return new RsaCryptosystemTester;
    case DUMMY:
      return new DummyCryptosystemTester;
    default:
      std::cout << "Wrong cryptosystem name.\n";
      throw std::exception();
  }
}

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  cryptosystem = getCryptosystem(cryptosystemName);
  cryptosystemTester = getCryptosystemTester(
    cryptosystemName);
}

////////////////////////////////////////////////////////////
// testing

Bool Party::testParty() {
  std::cout << "Testing class Party.\n";
  return cryptosystemTester->testAll();
}
