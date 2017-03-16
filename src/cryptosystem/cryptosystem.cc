#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// impurely virtual

void Cryptosystem::testCryptosystem() {
  cout << "Testing cryptosystem.\n";

  Text text = "nicole";
  cout << "text: " << text << "\n";

  PaddedText paddedText("1000000000000000000000000000000000");
  cout << "padded text: " << paddedText << "\n";
}

////////////////////////////////////////////////////////////
// non-virtual

void Cryptosystem::padText(PaddedText &paddedText,
    const Text &text) {
  cout << "padding\n";
}

void Cryptosystem::unpadText(Text &text,
    const PaddedText &paddedText) {
  cout << "unpadding\n";
}
