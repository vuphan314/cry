#ifndef TESTER_DUMMYTESTER_H
#define TESTER_DUMMYTESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/dummy_cryptosystem.h"
#include "rsa_tester.h"

////////////////////////////////////////////////////////////

class DummyTester : public RsaTester {
public:
  DummyTester(SizeT minModulusLength =
    BREAKABLE_MIN_MODULUS_LENGTH);
    // constructor to set data member cryptosystem

  Bool testCryptosystem(Text plainText =
    BREAKABLE_PLAIN_TEXT);
};

////////////////////////////////////////////////////////////

#endif
