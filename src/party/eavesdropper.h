#ifndef PARTY_EAVESDROPPER
#define PARTY_EAVESDROPPER

////////////////////////////////////////////////////////////

#include "party.h"

////////////////////////////////////////////////////////////

class Eavesdropper : public Party {
private:
  Text plainText;

  void cryptanalyze(const Text cipherText, const Key publicKey);
    // {cryptosystem->cryptanalyze(plainText, cipherText, publicKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_EAVESDROPPER
