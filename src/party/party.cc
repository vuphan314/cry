#include "party.h"

////////////////////////////////////////////////////////////
// class Party:

Party::Party(CryptosystemName cryptosystemName) {
  tester = getTester(cryptosystemName);
}

Bool Party::testParty() {
  std::cout << "Testing class Party.\n";
  return tester->testAll();
}

////////////////////////////////////////////////////////////
// global function:

Tester *getTester(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA:
      return new RsaTester;
    case DUMMY:
      return new DummyTester;
    default:
      std::cout << "Wrong cryptosystem name.\n";
      throw std::exception();
  }
}
