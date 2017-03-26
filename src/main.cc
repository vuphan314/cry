#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = DUMMY;
  Party party(cryptosystemName);
  if (party.testParty()) {
    std::cout << "All tests passed.\n";
  } else {
    std::cout << "Some test failed.\n";
  }
}
