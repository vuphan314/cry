#include "tester.h"

////////////////////////////////////////////////////////////
// class Tester:

Bool Tester::testAll() {
  std::cout << "method Tester::testAll\n";
  return testKeyGeneration() && testEncryption() &&
    testDecryption() && testCryptanalysis();
}

////////////////////////////////////////////////////////////
// global functions:

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
  for (int ch = -TWO_EXP_7; ch < TWO_EXP_7; ch++) {
      // `char ch` would do 127++ == -128, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      std::cout << "Test failed.\n";
      return FALSE;
    }
  }
  for (unsigned int uCh = 0; uCh < TWO_EXP_8; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      std::cout << "Test failed.\n";
      return FALSE;
    }
  }
  std::cout << "Test passed.\n";
  return TRUE;
}
