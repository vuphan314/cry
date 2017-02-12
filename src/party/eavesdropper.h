#ifndef PARTY_EAVESDROPPER
#define PARTY_EAVESDROPPER

////////////////////////////////////////////////////////////

#include "party.h"

////////////////////////////////////////////////////////////

class Eavesdropper : public Party {
private:
  Text plaintext;

  void cryptanalyze(const Text ciphertext, const Key publicKey);
    // {cryptosystem.cryptanalyze(plaintext, ciphertext, publicKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_EAVESDROPPER
