#include "party/party.h"

////////////////////////////////////////////////////////////

void breakRsa(
    SizeT strength = BREAKABLE_MIN_MODULUS_LENGTH,
    Text plainText = BREAKABLE_PLAIN_TEXT) {
  cout << "function breakRsa\n";
  RsaTester rsaTester;
  rsaTester.testCryptosystem(strength, plainText);
  cout << "\n";
}

////////////////////////////////////////////////////////////

int main(int argc, const char *argv[]) {
  cout << "\n";

  Party party; party.doAction(argc, argv);

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

  cout << "\n";
}
