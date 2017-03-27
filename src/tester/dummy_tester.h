#ifndef TESTER_DUMMYTESTER_H
#define TESTER_DUMMYTESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/dummy_cryptosystem.h"
#include "tester.h"

////////////////////////////////////////////////////////////

class DummyTester : public Tester {
public:
  DummyTester();

  Bool testKeyGeneration();

  Bool testEncryption();

  Bool testDecryption();

  Bool testCryptanalysis();
};

////////////////////////////////////////////////////////////

#endif
