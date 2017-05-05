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
const unordered_set<CryptosystemName> CRYPTOSYSTEM_NAMES{
  DUMMY, RSA};

const string KEY_GENERATION = "generatekeys";
const string ENCRYPTION = "encrypt";
const string DECRYPTION = "decrypt";
const string CRYPTANALYSIS = "cryptanalyze";
const unordered_set<string> ACTIONS{KEY_GENERATION,
  ENCRYPTION, DECRYPTION, CRYPTANALYSIS};

const string PUBLIC_EXTENSION = ".pu";
const string PRIVATE_EXTENSION = ".pr";

////////////////////////////////////////////////////////////

class Party {
protected:
  Tester *tester;
  Cryptosystem *cryptosystem;

  void setDataMembers(
    const CryptosystemName &cryptosystemName);

public:
  Party(const CryptosystemName &cryptosystemName = DUMMY);

  Bool test();

// command-line argument parsing:
  void doAction(int argc, const char *argv[]);

  void doKeyGeneration(string &receiverName,
    CryptosystemName &cryptosystemName);

  void doEncryption(string &senderName,
    string &receiverName);

  void doDecryption(string &receiverName,
    string &senderName);

  void doCryptanalysis(string &receiverName,
    string &senderName);

// file input/output:
  // key-generation:
  void writeReceiverFiles(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey);

  // decryption 1/2:
  void readReceiverFiles(
    CryptosystemName &cryptosystemName, // set this
    Key &privateKey, // set this
    const string &receiverName);

  // encryption 1/3, cryptanalysis 1/2:
  void readReceiverPublicFile(
    CryptosystemName &cryptosystemName, // set this
    Key &publicKey, // set this
    const string &receiverName);

  // encryption 2/3:
  void readSenderPrivateFile(Text &plainText, // set this
    const string &senderName);

  // encryption 3/3:
  void writeSenderPublicFile(const string &senderName,
    const PaddedText &paddedCipherText);

  // decryption 2/2, cryptanalysis 2/2:
  void readSenderPublicFile(
    PaddedText &paddedCipherText, // set this
    const string &senderName);
};

////////////////////////////////////////////////////////////
// global function:

void verifyCryptosystemName(const CryptosystemName&
  cryptosystemName);

void verifyInputStreamOpening(const ifstream &inputStream);
// testing:

void testCryptosystems();

void testInputOutput();

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
