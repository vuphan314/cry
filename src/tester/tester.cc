#include "tester.h"

////////////////////////////////////////////////////////////
// global functions:

Bool testPaddingUnpadding() {
  cout << "Testing padding/unpadding.\n";

  Text text("this is my string");
  cout << "Text: " << text << ".\n";

  PaddedText paddedText;
  padText(paddedText, text);
  cout << "Padded text: " << paddedText << ".\n";

  Text unpaddedText;
  unpadText(unpaddedText, paddedText);
  cout << "Unpadded text: " << unpaddedText <<
    ".\n";

  if (unpaddedText == text) {
    cout << "Test passed.\n\n";
    return TRUE;
  } else {
    cout << "Test failed.\n\n";
    return FALSE;
  }
}

Bool testCharConversion() {
  cout << "Testing char conversion.\n";
  for (int ch = -TWO_EXP_7; ch < TWO_EXP_7; ch++) {
      // `char ch` would do 127++ == -128, looping forever
    if (getChar(getUnsignedChar(ch)) != ch) {
      cout << "Test failed.\n\n";
      return FALSE;
    }
  }
  for (unsigned int uCh = 0; uCh < TWO_EXP_8; uCh++) {
    if (getUnsignedChar(getChar(uCh)) != uCh) {
      cout << "Test failed.\n\n";
      return FALSE;
    }
  }
  cout << "Test passed.\n\n";
  return TRUE;
}
