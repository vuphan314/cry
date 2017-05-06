#include "party/party.h"

////////////////////////////////////////////////////////////

void breakRsa(
    SizeT strength = BREAKABLE_MIN_MODULUS_LENGTH,
    Text plainText = BREAKABLE_PLAIN_TEXT) {
  std::cout << "function breakRsa\n";
  RsaTester rsaTester;
  rsaTester.testCryptosystem(strength, plainText);
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

int main(int argc, const char *argv[]) {
  std::cout << "\n";

  Party party;
  party.doAction(argc, argv);

  // switch (argc) {
  //   case 1:
  //     breakRsa(); break;
  //   case 3:
  //     breakRsa(atoi(argv[1]), argv[2]); break;
  //   default:
  //     throw DefaultException("wrong argc");
  // }

  // testCryptosystems();
  // testActions();
  // testInputOutput();

  // testPaddingUnpadding();
  // testCharConversion();
}
