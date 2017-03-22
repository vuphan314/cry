#include "party.h"

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA: cryptosystem = new RsaCryptosystem;
  }
}

////////////////////////////////////////////////////////////
// testing

Bool Party::testParty() {
  std::cout << "Testing class Party.\n";
  return cryptosystem->testCryptosystem();
}
