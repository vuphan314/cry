#ifndef TESTBED_H
#define TESTBED_H

////////////////////////////////////////////////////////////

#include "../party/eavesdropper.h"
#include "../party/receiver.h"
#include "../party/sender.h"

////////////////////////////////////////////////////////////

class Testbed {
public:
  Receiver receiver;
  Sender sender;
  Eavesdropper eavesdropper;

  Testbed(CryptosystemName cryptosystemName);

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

#endif // TESTBED_H
