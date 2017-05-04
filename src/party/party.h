#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include <fstream>

#include "../tester/dummy_tester.h"
#include "../tester/rsa_tester.h"

////////////////////////////////////////////////////////////

enum Action {KEY_GENERATION, ENCRYPTION, DECRYPTION,
  CRYPTANALYSIS}; // for command-line argument parsing

enum CryptosystemName {DUMMY, RSA};

////////////////////////////////////////////////////////////

const string IO_DUMMY = "dummy";
const string IO_RSA = "rsa";

////////////////////////////////////////////////////////////

class Party {
protected:
  Tester *tester;

public:
  Party(CryptosystemName cryptosystemName = RSA);

  Bool test();

// command-line argument parsing:
  Action getAction(int argc, const char *argv[]);

  void doKeyGeneration(string &receiversName,
    CryptosystemName &cryptosystemName, const char *argv[]);

  void doEncryption(string &sendersName,
    string &receiversName, const char *argv[]);

  void doDecryption(string &receiversName,
    string &sendersName, const char *argv[]);

  void doCryptanalysis(string &receiversName,
    string &sendersName, const char *argv[]);

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
