#ifndef CRYPTOFRAMEWORK_H
#define CRYPTOFRAMEWORK_H

////////////////////////////////////////////////////////////

#include "party/eavesdropper.h"
#include "party/receiver.h"
#include "party/sender.h"

////////////////////////////////////////////////////////////

class Cryptoframework {
public:
  Receiver receiver;
  Sender sender;
  Eavesdropper eavesdropper;

  Cryptoframework(CryptosystemName cryptosystemName);

  void testKeyGeneration();
    // {receiver.generateKeys()}

  void testEncryption();
    // {sender.encrypt(receiver.publicKey)}

  void testDecryption();
    // {receiver.decrypt(sender.ciphertext)}

  void testCryptanalysis();
    // {eavesdropper.cryptanalyze(sender.ciphertext, receiver.publicKey)}
};

////////////////////////////////////////////////////////////

#endif // CRYPTOFRAMEWORK_H
