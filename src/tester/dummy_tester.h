#ifndef TESTER_DUMMYTESTER_H
#define TESTER_DUMMYTESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/dummy_cryptosystem.h"
#include "rsa_tester.h"

////////////////////////////////////////////////////////////

class DummyTester : public RsaTester {
public:
  Bool testCryptosystem(Text plainText);
};

////////////////////////////////////////////////////////////

#endif
