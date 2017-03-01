#ifndef PARTY_RECEIVER
#define PARTY_RECEIVER

////////////////////////////////////////////////////////////

#include "party.h"

////////////////////////////////////////////////////////////

class Receiver : public Party {
public:
  Key publicKey;

private:
  Key privateKey;
  Text plaintext;

  void generateKeys();
    // {cryptosystem->generateKeys(publicKey, privateKey)}

  void decrypt(const Text ciphertext);
    // {cryptosystem->decrypt(plaintext, ciphertext, privateKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_RECEIVER
