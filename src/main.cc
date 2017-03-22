#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = RSA;
  Party party(cryptosystemName);
  if (party.testParty()) {
    std::cout << "Test passed.\n";
  } else {
    std::cout << "Test failed.\n";
  }
}
