#ifndef TESTER_TESTER_H
#define TESTER_TESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

class Tester { // abstract
protected:
  Cryptosystem *cryptosystem;
    // set by constructor of non-abstract derived class

public:
// purely virtual methods,
// must be defined by non-abstract derived class:
  virtual void testCryptosystem(const SizeT &strength,
    const Text &plainText) = 0;
};

////////////////////////////////////////////////////////////
// global functions:

Bool testPaddingUnpadding();

Bool testCharConversion();

////////////////////////////////////////////////////////////

#endif // TESTER_TESTER_H
