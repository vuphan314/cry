#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include <fstream>
#include <unordered_set>

#include "../tester/dummy_tester.h"
#include "../tester/rsa_tester.h"

////////////////////////////////////////////////////////////

using CryptosystemName = string;

////////////////////////////////////////////////////////////

const CryptosystemName DUMMY = "dummy";
const CryptosystemName RSA = "rsa";

const unordered_set<CryptosystemName> CRYPTOSYSTEM_NAMES
  {DUMMY, RSA};

////////////////////////////////////////////////////////////

enum Action {KEY_GENERATION, ENCRYPTION, DECRYPTION,
  CRYPTANALYSIS}; // for command-line argument parsing

////////////////////////////////////////////////////////////

class Party {
protected:
  Tester *tester;

public:
  Party(CryptosystemName cryptosystemName = DUMMY);

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

void verifyCryptosystemName(const CryptosystemName&
  cryptosystemName);

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
