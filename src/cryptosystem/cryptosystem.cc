#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// impurely virtual

void Cryptosystem::testCryptosystem() {
  cout << "Testing cryptosystem.\n";
  Text text = "unpadded";

  mpz_t x;
  mpz_init(x);
  // mpz_clear(x);

  // mpz_class s = mpz_class("31");

  cout << text << "\n";
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
