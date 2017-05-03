#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include "../tester/dummy_tester.h"
#include "../tester/rsa_tester.h"

////////////////////////////////////////////////////////////

enum CryptosystemName {DUMMY, RSA};

////////////////////////////////////////////////////////////

class Party {
protected:
  Tester *tester;

public:
  Party(CryptosystemName cryptosystemName = RSA);

  Bool test();

// file input/output:
  void writeReceiversFiles(const string &receiversName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey);

  void readReceiversPublicFile(
    CryptosystemName &cryptosystemName, Key &publicKey,
    const string &receiversName);

  void readSendersPrivateFile(Text &plainText,
    const string &sendersName);

  void writeSendersPublicFile(const string &sendersName,
    const PaddedText &paddedCipherText);
};

////////////////////////////////////////////////////////////
// global function:

Tester *getTester(CryptosystemName cryptosystemName);

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
