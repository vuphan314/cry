#include "tester.h"

////////////////////////////////////////////////////////////
// class Tester:

Bool Tester::testAll() {
  std::cout << "Testing cryptosystem.\n";
  return testKeyGeneration() && testEncryption() &&
    testDecryption() && testCryptanalysis();
}

////////////////////////////////////////////////////////////
// helpers:

Bool testPaddingUnpadding() {
  std::cout << "Testing padding/unpadding.\n";

  Text text("this string is my original text");
  std::cout << "Text: \"" << text << "\".\n";

  PaddedText paddedText;
  padText(paddedText, text);
  std::cout << "Padded text: " << paddedText << ".\n";

  Text unpaddedText;
  unpadText(unpaddedText, paddedText);
  std::cout << "Unpadded Text: \"" << unpaddedText <<
    "\".\n";

  return unpaddedText == text;
}

Bool testCharConversion() {
  std::cout << "Testing char conversion.\n";
  for (int ch = -128; ch < 128; ch++) {
      // `char ch` would do 127++ == -128, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      std::cout << "Test failed.\n";
      return FALSE;
    }
  }
  for (unsigned int uCh = 0; uCh < 256; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      std::cout << "Test failed.\n";
      return FALSE;
    }
  }
  std::cout << "Test passed.\n";
  return TRUE;
}
