#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// global functions:

void seedRandomState(gmp_randstate_t randomState) {
  gmp_randinit_default(randomState);
  gmp_randseed_ui(randomState, DEFAULT_RANDOM_SEED);
}
// https://stackoverflow.com/questions/9791761/using-gmp-for-cryptography-how-to-get-random-numbers

void setTotient(mpz_t l, mpz_t p, mpz_t q) {
  mpz_t p1, q1;
  mpz_init_set(p1, p);
  mpz_init_set(q1, q);
  mpz_sub_ui(p1, p1, 1);
  mpz_sub_ui(q1, q1, 1);
  mpz_lcm(l, p1, q1); // yes: Carmichael totient
  // mpz_mul(l, p1, q1); // no: Euler totient
}

// padding/unpadding:

void padText(PaddedText &paddedText, const Text &text) {
  // cout << "Padding.\n";
  paddedText = 0;
  BigInt multiplier(1);
  SizeT i = 0, n = text.size();
  if (n > 0) {
    do {
      paddedText += getUnsignedChar(text.at(i)) *
        multiplier;
      multiplier *= ALPHABET_SIZE;
      i++;
    } while (i < n);
  }
}

void unpadText(Text &text, const PaddedText &paddedText) {
  // cout << "Unpadding.\n";
  text.clear();
  BigInt paddedChar, remainingPaddedText = paddedText;
  while (remainingPaddedText > 0) {
    paddedChar = remainingPaddedText % ALPHABET_SIZE;
    text.push_back(getChar(paddedChar.get_ui()));
    remainingPaddedText /= ALPHABET_SIZE;
  }
}

// char conversion:

unsigned char getUnsignedChar(char ch) {
  if (ch < 0) {
    return ch + TWO_EXP_8;
  } else {
    return ch;
  }
}

char getChar(unsigned char uCh) {
  if (uCh >= 128) {
    return uCh - TWO_EXP_8;
  } else {
    return uCh;
  }
}
