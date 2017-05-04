#include "party/party.h"

////////////////////////////////////////////////////////////

void testIO() {
  Party party;

  string receiver("p_receiver");
  CryptosystemName cn(DUMMY);
  KeyElement n("172014975789562774694897382365563045699"),
    e("65537"), d("7542263449887751984019792124906530513");
  Key publicK{n, e}, privateK{n, d};

  party.writeReceiversFiles(receiver, cn, publicK, privateK);
}

////////////////////////////////////////////////////////////

void breakRsa(SizeT minModulusLength =
    BREAKABLE_MIN_MODULUS_LENGTH,
    Text plainText = BREAKABLE_PLAIN_TEXT) {
  std::cout << "function breakRsa\n";
  RsaTester rsaTester(minModulusLength);
  rsaTester.testCryptosystem(plainText);
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

void testCryptosystems() {
  std::cout << "function testCryptosystems\n";
  std::vector<CryptosystemName>cryptosystemNames;
  cryptosystemNames.push_back(DUMMY);
  // cryptosystemNames.push_back(RSA);
  for (CryptosystemName cryptosystemName :
      cryptosystemNames) {
    std::cout << "\n";
    Party party(cryptosystemName);
    if (party.test()) {
      std::cout << "Test passed.\n";
    } else {
      std::cout << "Test failed.\n";
    }
  }
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

int main(int argc, const char *argv[]) {
  std::cout << "\n";
  testIO();
  // switch (argc) {
  //   case 1:
  //     breakRsa();
  //     break;
  //   case 3:
  //     breakRsa(atoi(argv[1]), argv[2]);
  //     break;
  //   default:
  //     cout << "wrong argc\n";
  //     throw std::exception();
  // }
  // testCryptosystems();
  // testPaddingUnpadding();
  // testCharConversion();
}
