#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// impurely virtual

void Cryptosystem::testCryptosystem() {
  cout << "Testing cryptosystem.\n";

  Text text("\n\n\n\tHey Lex :)\n\n\tIt's Vi ;)\n\n\n");

  PaddedText paddedText;
  padText(paddedText, text);
  cout << "Padded text: " << paddedText << ".\n";

  unpadText(text, paddedText);
  cout << "Text: \"" << text << "\".\n";
}

////////////////////////////////////////////////////////////
// non-virtual

void Cryptosystem::padText(PaddedText &paddedText,
    const Text &text) {
  cout << "Padding.\n";
  BigInt multiplier(1);
  Int i = 0, n = text.size();
  if (n) {
    do {
      paddedText += getUnsignedChar(text.at(i)) * multiplier;
      multiplier *= ALPHABET_SIZE;
      i++;
    } while (i < n);
  }
}

void Cryptosystem::unpadText(Text &text,
    PaddedText &paddedText) {
  cout << "Unpadding.\n";
  text.clear();
  BigInt paddedChar;
  while (paddedText) {
    paddedChar = paddedText % ALPHABET_SIZE;
    text.push_back(getChar(paddedChar.get_ui()));
    paddedText /= ALPHABET_SIZE;
  }
}

////////////////////////////////////////////////////////////

void testCharConversion() {
  cout << "Testing char conversion.\n";
  for (int ch = -128; ch < 128; ch++) { // `char ch` would wrap, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      cout << "Incorrect.\n";
      return;
    }
  }
  for (unsigned int uCh = 0; uCh < 256; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      cout << "Incorrect.\n";
      return;
    }
  }
  cout << "Correct.\n";
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
