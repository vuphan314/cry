#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = RSA;
  Party party(cryptosystemName);
  if (party.testParty()) {
    cout << "Test passed.\n";
  } else {
    cout << "Test failed.\n";
  }
}
