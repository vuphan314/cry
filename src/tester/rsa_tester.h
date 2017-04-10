#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"
#include "tester.h"

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester();
    // constructor to set data member cryptosystem

  void demo(SizeT modulusLength, Text plainText);

  Bool testKeyGeneration();

  Bool testEncryption();

  Bool testDecryption();

  Bool testCryptanalysis();
};

////////////////////////////////////////////////////////////

#endif
