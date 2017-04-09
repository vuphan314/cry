#include "party/party.h"

////////////////////////////////////////////////////////////

void testCryptosystems() {
  std::cout << "\nfunction testCryptosystems:\n";
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

////////////////////////////////////////////////////////////

void demoRsa() {
  RsaTester rsaTester;
  rsaTester.demo();
}

////////////////////////////////////////////////////////////

int main() {
  std::cout << "\n";
  // testPaddingUnpadding();
  // testCharConversion();
  // testCryptosystems();
  demoRsa();
}
