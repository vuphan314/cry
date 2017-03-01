#ifndef PARTY_SENDER
#define PARTY_SENDER

////////////////////////////////////////////////////////////

#include "party.h"

////////////////////////////////////////////////////////////

class Sender : public Party {
public:
  Text ciphertext;

private:
  Text plaintext;

  void encrypt(const Key publicKey);
    // {cryptosystem->encrypt(ciphertext, plaintext, publicKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_SENDER
