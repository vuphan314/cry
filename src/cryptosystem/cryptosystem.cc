#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// global functions:

void padText(PaddedText &paddedText, const Text &text) {
  std::cout << "Padding.\n";
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

void unpadText(Text &text, PaddedText paddedText) {
  std::cout << "Unpadding.\n";
  text.clear();
  BigInt paddedChar;
  while (paddedText > 0) {
    paddedChar = paddedText % ALPHABET_SIZE;
    text.push_back(getChar(paddedChar.get_ui()));
    paddedText /= ALPHABET_SIZE;
  }
}

unsigned char getUnsignedChar(char ch) {
  if (ch < 0) {
    return ch + 256;
  } else {
    return ch;
  }
}

char getChar(unsigned char uCh) {
  if (uCh >= 128) {
    return uCh - 256;
  } else {
    return uCh;
  }
}
