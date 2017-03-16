#include "cryptosystem.h"

////////////////////////////////////////////////////////////
// impurely virtual

void Cryptosystem::testCryptosystem() {
  cout << "Testing cryptosystem.\n";

  Text text("Hey Lex :). It's Vi.");
  // cout << "Text: \"" << text << "\".\n";

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

UnsignedChar getUnsignedChar(const Char ch) {
  if (ch < 0) {
    return ch + TOTAL_CHAR_COUNT;
  } else {
    return ch;
  }
}

Char getChar(const UnsignedChar uCh) {
  if (uCh >= 128) {
    return uCh - TOTAL_CHAR_COUNT;
  } else {
    return uCh;
  }
}
