#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// impurely virtual

void Cryptosystem::testCryptosystem() {
  cout << "Testing cryptosystem.\n";
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
