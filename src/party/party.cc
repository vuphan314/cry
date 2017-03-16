#include "party.h"

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA: cryptosystem = new RsaCryptosystem;
  }
}

void Party::testParty() {
  cout << "Testing party.\n";
  cryptosystem->testCryptosystem();
}
