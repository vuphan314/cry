#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "tester.h"

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester();
    // constructor to set data member cryptosystem

  Bool testCryptosystem(
    const SizeT &strength = TRIVIAL_STRENGTH,
    const Text &plainText = TRIVIAL_PLAIN_TEXT);
};

////////////////////////////////////////////////////////////

#endif
