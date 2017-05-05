#include "party/party.h"

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

int main(int argc, const char *argv[]) {
  std::cout << "\n";

  // testCryptosystems();
  // testAction(argc, argv);
  testInputOutput();

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

  // testPaddingUnpadding();
  // testCharConversion();
}
