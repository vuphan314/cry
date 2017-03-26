#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include "../cryptosystem/rsa_cryptosystem.h"
#include "../cryptosystem/dummy_cryptosystem.h"

////////////////////////////////////////////////////////////

enum CryptosystemName {DUMMY, RSA};

Cryptosystem *getCryptosystem(
  CryptosystemName cryptosystemName);

CryptosystemTester *getCryptosystemTester(
  CryptosystemName cryptosystemName);

////////////////////////////////////////////////////////////

class Party {
protected:
  Cryptosystem *cryptosystem;
  CryptosystemTester *cryptosystemTester;

public:
  Party(CryptosystemName cryptosystemName);

// testing:
  Bool testParty();
};

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
