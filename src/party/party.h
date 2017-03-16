#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

enum CryptosystemName {RSA}; // more to come

////////////////////////////////////////////////////////////

class Party {
protected:
  Cryptosystem *cryptosystem;

public:
  Party(CryptosystemName cryptosystemName);

  void testParty();
};

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
