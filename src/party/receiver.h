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
  Text plainText;

  void generateKeys();
    // {cryptosystem->generateKeys(publicKey, privateKey)}

  void decrypt(const Text cipherText);
    // {cryptosystem->decrypt(plainText, cipherText, privateKey)}
};

////////////////////////////////////////////////////////////

#endif // PARTY_RECEIVER
