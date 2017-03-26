#ifndef DUMMY_TESTER
#define DUMMY_TESTER

////////////////////////////////////////////////////////////

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
