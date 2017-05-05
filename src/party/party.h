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

const string PUBLIC_EXTENSION = ".pu";
const string PRIVATE_EXTENSION = ".pr";

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

  void doKeyGeneration(string &receiverName,
    CryptosystemName &cryptosystemName, const char *argv[]);

  void doEncryption(string &senderName,
    string &receiverName, const char *argv[]);

  void doDecryption(string &receiverName,
    string &senderName, const char *argv[]);

  void doCryptanalysis(string &receiverName,
    string &senderName, const char *argv[]);

// file input/output:
  void writeReceiverFiles(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey);

  void readReceiverPublicFile(
    CryptosystemName &cryptosystemName, // set this
    Key &publicKey, // set this
    const string &receiverName);

  void readSenderPrivateFile(Text &plainText, // set this
    const string &senderName);

  void writeSenderPublicFile(const string &senderName,
    const PaddedText &paddedCipherText);

  void readSenderPublicFile(
    PaddedText &paddedCipherText, // set this
    const string &senderName);
};

////////////////////////////////////////////////////////////
// global function:

Tester *getTester(CryptosystemName cryptosystemName);

void verifyCryptosystemName(const CryptosystemName&
  cryptosystemName);

void verifyInputStreamOpening(const ifstream &inputStream);

// testing:

void testCryptosystems();

void testInputOutput();

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
