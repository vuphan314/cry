#ifndef TESTER_RSATESTER_H
#define TESTER_RSATESTER_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"
#include "tester.h"

////////////////////////////////////////////////////////////

const PaddedText DEFAULT_PADDED_CIPHER_TEXT("2376487326");

////////////////////////////////////////////////////////////

class RsaTester : public Tester {
public:
  RsaTester(SizeT minModulusLength =
    DEFAULT_MIN_MODULUS_LENGTH);
    // constructor to set data member cryptosystem

  void demo(Text plainText);

  Bool testKeyGeneration();

  Bool testEncryption();

  Bool testDecryption();

  Bool testCryptanalysis();
};

////////////////////////////////////////////////////////////

#endif
