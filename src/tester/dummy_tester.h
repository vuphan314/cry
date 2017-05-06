#ifndef TESTER_DUMMYTESTER_H
#define TESTER_DUMMYTESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/dummy_cryptosystem.h"
#include "rsa_tester.h"

////////////////////////////////////////////////////////////

class DummyTester : public RsaTester {
public:
  DummyTester();
    // constructor to set data member cryptosystem

  Bool testCryptosystem(
    const SizeT &strength = TRIVIAL_STRENGTH,
    const Text &plainText = TRIVIAL_PLAIN_TEXT);
};

////////////////////////////////////////////////////////////

#endif
