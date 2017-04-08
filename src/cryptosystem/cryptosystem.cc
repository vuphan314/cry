#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// global functions:

void padText(PaddedText &paddedText, const Text &text) {
  // std::cout << "Padding.\n";
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
  // std::cout << "Unpadding.\n";
  text.clear();
  BigInt paddedChar, remainingPaddedText = paddedText;
  while (remainingPaddedText > 0) {
    paddedChar = remainingPaddedText % ALPHABET_SIZE;
    text.push_back(getChar(paddedChar.get_ui()));
    remainingPaddedText /= ALPHABET_SIZE;
  }
}

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
