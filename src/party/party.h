#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsaCryptosystem.h"

////////////////////////////////////////////////////////////

enum CryptosystemName {RSA}; // more to come

////////////////////////////////////////////////////////////

class Party {
protected:
  Cryptosystem *cryptosystem;

public:
  Party(CryptosystemName cryptosystemName);
};

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
