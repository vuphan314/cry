#include "party/party.h"

////////////////////////////////////////////////////////////

void demoRsa(SizeT modulusLength = BREAKABLE_MODULUS_LENGTH,
    Text plainText = BREAKABLE_PLAIN_TEXT) {
  std::cout << "function demoRsa\n";
  RsaTester rsaTester;
  rsaTester.demo(modulusLength, plainText);
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

int main(int argc, char const *argv[]) {
  std::cout << "\n";
  switch (argc) {
    case 3:
      demoRsa(atoi(argv[1]), argv[2]);
      break;
    case 1:
      demoRsa();
      break;
    default:
      cout << "wrong argc\n";
  }
  // testCryptosystems();
  // testPaddingUnpadding();
  // testCharConversion();
}
