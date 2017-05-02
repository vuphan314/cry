#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"
#include "tester.h"

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester(SizeT minModulusLength =
    DEFAULT_MIN_MODULUS_LENGTH);
    // constructor to set data member cryptosystem

  Bool testCryptosystem(Text plainText);
};

////////////////////////////////////////////////////////////

#endif
