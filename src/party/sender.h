#ifndef PARTY_SENDER
#define PARTY_SENDER

////////////////////////////////////////////////////////////

#include "party.h"

////////////////////////////////////////////////////////////

class Sender : public Party {
public:
  Text cipherText;

private:
  Text plainText;

  void encrypt(const Key publicKey);
    // {cryptosystem->encrypt(cipherText, plainText, publicKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_SENDER
