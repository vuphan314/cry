#ifndef PARTY_PARTY_H
#define PARTY_PARTY_H

////////////////////////////////////////////////////////////

#include <fstream>
#include <unordered_set>

#include "../tester/dummy_tester.h"
#include "../tester/rsa_tester.h"

////////////////////////////////////////////////////////////

using CryptosystemName = string;

using ArgV = vector<string>;

////////////////////////////////////////////////////////////

const string EXECUTABLE = "./cry";

const string KEY_GENERATION = "g";
const string ENCRYPTION = "e";
const string DECRYPTION = "d";
const string CRYPTANALYSIS = "c";
const unordered_set<string> ACTIONS{KEY_GENERATION,
  ENCRYPTION, DECRYPTION, CRYPTANALYSIS};

const string COMMUNICATION_DIR = "./";
const string PUBLIC_EXTENSION = ".public";
const string PRIVATE_EXTENSION = ".private";

const string DEFAULT_SENDER = "sender";
const string DEFAULT_RECEIVER = "receiver";

const CryptosystemName DUMMY = "dummy";
const CryptosystemName RSA = "rsa";
const unordered_set<CryptosystemName> CRYPTOSYSTEM_NAMES{
  DUMMY, RSA};

////////////////////////////////////////////////////////////

class Party {
protected:
  Tester *tester;
  Cryptosystem *cryptosystem;

  void setDataMembers(
    const CryptosystemName &cryptosystemName);

public:
  Party(const CryptosystemName &cryptosystemName = DUMMY);
    // constructor

  Bool test();

// command-line argument parsing:
  void doAction(int argc, const char *argv[]);

  void doKeyGeneration(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const SizeT &strength);

  void doEncryption(const string &senderName,
    const string &receiverName);

  void doDecryption(const string &receiverName,
    const string &senderName);

  void doCryptanalysis(const string &receiverName,
    const string &senderName);

// file IO:
  // key-generation 1/1:
  void writeReceiverFiles(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const SizeT &strength, const Key &publicKey,
    const Key &privateKey);

  // decryption 1/2:
  void readReceiverFiles(
    CryptosystemName &cryptosystemName, // set this
    Key &privateKey, // set this
    const string &receiverName);

  // encryption 1/3, cryptanalysis 1/2:
  void readReceiverPublicFile(
    CryptosystemName &cryptosystemName, // set this
    SizeT &strength, Key &publicKey, // set these
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

void helpActions();

void helpKeyGeneration();

void helpEncryption();

void helpDecryption();

void helpCryptanalysis();

void setArgV(ArgV &argV, int argc, const char *argv[]);

void verifyCryptosystemName(
  const CryptosystemName& cryptosystemName);

void verifyInputStreamOpening(const ifstream &inputStream);

// testing:

void testCryptosystems();

void testActions();

void testInputOutput();

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
