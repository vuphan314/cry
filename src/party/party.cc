#include "party.h"

////////////////////////////////////////////////////////////
// class Party:

Party::Party(CryptosystemName cryptosystemName) {
  tester = getTester(cryptosystemName);
}

Bool Party::test() {
  std::cout << "method Party::test\n";
  return tester->testCryptosystem();
}

////////////////////////////////////////////////////////////
// global function:

Tester *getTester(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case DUMMY:
      return new DummyTester;
    case RSA:
      return new RsaTester;
    default:
      std::cout << "Wrong cryptosystem name.\n";
      throw std::exception();
  }
}
