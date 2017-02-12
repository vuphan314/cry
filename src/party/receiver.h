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

  void setKeys();
    // {cryptosystem.generateKeys(publicKey, privateKey)}

  void setPlaintext(const Text ciphertext);
    // {cryptosystem.decrypt(plaintext, ciphertext, privateKey)}
}

////////////////////////////////////////////////////////////

#endif // PARTY_RECEIVER
