#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  std::vector<CryptosystemName>
    cryptosystemNames{RSA, DUMMY};
  for (CryptosystemName cryptosystemName :
      cryptosystemNames) {
    std::cout << "\n";
    Party party(cryptosystemName);
    if (party.testParty()) {
      std::cout << "All tests passed.\n";
    } else {
      std::cout << "Some test failed.\n";
    }
  }
}
