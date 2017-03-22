#include "cryptosystem.h"

////////////////////////////////////////////////////////////

void Cryptosystem::padText(PaddedText &paddedText,
    const Text &text) {
  std::cout << "Padding.\n";
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
  std::cout << "Unpadding.\n";
  text.clear();
  BigInt paddedChar;
  while (paddedText>0) {
    paddedChar = paddedText % ALPHABET_SIZE;
    text.push_back(getChar(paddedChar.get_ui()));
    paddedText /= ALPHABET_SIZE;
  }
}

////////////////////////////////////////////////////////////
// testing

Bool Cryptosystem::testCryptosystem() {
  std::cout << "Testing class Cryptosystem.\n";

  Text text("this string is my original text");
  std::cout << "Text: ";
  printText(text);
  std::cout << ".\n";

  PaddedText paddedText;
  padText(paddedText, text);
  std::cout << "Padded text: " << paddedText << ".\n";

  Text unpaddedText;
  unpadText(unpaddedText, paddedText);
  std::cout << "Unpadded text: ";
  printText(unpaddedText);
  std::cout << ".\n";

  if (unpaddedText == text) {
    return TRUE;
  } else {
    return FALSE;
  }
}

////////////////////////////////////////////////////////////

void printText(const Text &text) {
  std::cout << "\"" << text << "\"";
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
  std::cout << "Testing char conversion.\n";
  for (int ch = -128; ch < 128; ch++) {
      // `char ch` would do 127++ == -128, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      std::cout << "Incorrect.\n";
      return FALSE;
    }
  }
  for (unsigned int uCh = 0; uCh < 256; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      std::cout << "Incorrect.\n";
      return FALSE;
    }
  }
  std::cout << "Correct.\n";
  return TRUE;
}
