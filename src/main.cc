#include "party/party.h"

////////////////////////////////////////////////////////////

void demoRsa() {
  std::cout << "function demoRsa\n";
  RsaTester rsaTester;
  rsaTester.demo();
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

void testCryptosystems() {
  std::cout << "function testCryptosystems\n";
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
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

int main() {
  std::cout << "\n";
  demoRsa();
  // testCryptosystems();
  // testPaddingUnpadding();
  // testCharConversion();
}
