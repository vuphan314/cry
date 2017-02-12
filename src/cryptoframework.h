#ifndef CRYPTOFRAMEWORK_H_
#define CRYPTOFRAMEWORK_H_

////////////////////////////////////////////////////////////

#include "party/sender.h"
#include "party/receiver.h"
#include "party/eavesdropper.h"

////////////////////////////////////////////////////////////

class Cryptoframework {
public:
  Sender sender;
  Receiver receiver;
  Eavesdropper eavesdropper;

  Cryptoframework(EnumeratedCryptosystem enumeratedCryptosystem);

  void testKeyGeneration();
    // {receiver.setKeys()}

  void testEncryption();
    // {sender.setCiphertext(receiver.publicKey)}

  void testDecryption();
  // {receiver.setPlaintext(sender.ciphertext)}

  void testCryptanalysis();
    // {eavesdropper.setPlaintext(sender.ciphertext, receiver.publicKey)}
};

////////////////////////////////////////////////////////////

#endif // CRYPTOFRAMEWORK_H_
