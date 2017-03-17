#include "party.h"

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA: cryptosystem = new RsaCryptosystem;
  }
}

////////////////////////////////////////////////////////////
// testing

void Party::testParty() {
  cout << "Testing class Party.\n";
  cryptosystem->testCryptosystem();
}
