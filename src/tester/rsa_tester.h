#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "tester.h"

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester(SizeT minModulusLength =
    BREAKABLE_MIN_MODULUS_LENGTH);
    // constructor to set data member cryptosystem

  Bool testCryptosystem(Text plainText =
    BREAKABLE_PLAIN_TEXT);
};

////////////////////////////////////////////////////////////

#endif
