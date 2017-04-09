#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/cryptosystem.h"

////////////////////////////////////////////////////////////

class Tester { // abstract
protected:
  Cryptosystem *cryptosystem;
    // set by constructor of non-abstract derived class

public:
  virtual void demo();

  Bool testAll();

// purely virtual methods,
// must be defined by non-abstract derived class:
  virtual Bool testKeyGeneration() = 0;

  virtual Bool testEncryption() = 0;

  virtual Bool testDecryption() = 0;

  virtual Bool testCryptanalysis() = 0;
};

////////////////////////////////////////////////////////////
// global functions:

Bool testPaddingUnpadding();

Bool testCharConversion();

////////////////////////////////////////////////////////////

#endif // TESTER_TESTER_H
