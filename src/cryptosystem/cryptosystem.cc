#include "cryptosystem.h"

////////////////////////////////////////////////////////////

void Cryptosystem::padText(PaddedText &paddedText,
    const Text &text) {
  cout << "Padding.\n";
  paddedText = 0;
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
    PaddedText paddedText) {
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
// testing

Bool Cryptosystem::testCryptosystem() {
  cout << "Testing class Cryptosystem.\n";

  Text text("this string is my original text");
  cout << "Text: ";
  printText(text);
  cout << ".\n";

  PaddedText paddedText;
  padText(paddedText, text);
  cout << "Padded text: " << paddedText << ".\n";

  Text unpaddedText;
  unpadText(unpaddedText, paddedText);
  cout << "Unpadded text: ";
  printText(unpaddedText);
  cout << ".\n";

  if (unpaddedText == text) {
    return TRUE;
  } else {
    return FALSE;
  }
}

////////////////////////////////////////////////////////////

void printText(const Text &text) {
  cout << "\"" << text << "\"";
}

////////////////////////////////////////////////////////////

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

Bool testCharConversion() {
  cout << "Testing char conversion.\n";
  for (int ch = -128; ch < 128; ch++) {
      // `char ch` would do 127++ == -128, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      cout << "Incorrect.\n";
      return FALSE;
    }
  }
  for (unsigned int uCh = 0; uCh < 256; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      cout << "Incorrect.\n";
      return FALSE;
    }
  }
  cout << "Correct.\n";
  return TRUE;
}
