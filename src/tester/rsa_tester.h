#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "tester.h"

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester();
    // constructor to set data member cryptosystem

  void testCryptosystem(const SizeT &strength,
    const Text &plainText);
};

////////////////////////////////////////////////////////////

#endif
