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

const string TEST = "t";
const string KEY_GENERATION = "g";
const string ENCRYPTION = "e";
const string DECRYPTION = "d";
const string CRYPTANALYSIS = "c";
const unordered_set<string> ACTIONS{TEST, KEY_GENERATION,
  ENCRYPTION, DECRYPTION, CRYPTANALYSIS};

const string EXECUTABLE = "./cry ";
const string TESTING = EXECUTABLE + TEST + " ";
const string KEY_GENERATING = EXECUTABLE + KEY_GENERATION +
  " ";
const string ENCRYPTING = EXECUTABLE + ENCRYPTION + " ";
const string DECRYPTING = EXECUTABLE + DECRYPTION + " ";
const string CRYPTANALYZING = EXECUTABLE + CRYPTANALYSIS +
  " ";

const string SPECIFIC_SENDER = "send";
const string SPECIFIC_RECEIVER = "receive";

const string SENDER = "<sender>";
const string RECEIVER = "<receiver>";

const string DIR = "./";
const string PUBLIC = ".public";
const string PRIVATE = ".private";

const string SENDER_PUBLIC = DIR + SENDER + PUBLIC;
const string SENDER_PRIVATE = DIR + SENDER + PRIVATE;
const string RECEIVER_PUBLIC = DIR + RECEIVER + PUBLIC;
const string RECEIVER_PRIVATE = DIR + RECEIVER + PRIVATE;

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

  void testParty(const SizeT &strength,
    const Text &plainText);

// command-line argument parsing:
  void doAction(int argc, const char *argv[]);

  void doAction(const ArgV &argv);

  void doTesting(const Text &plainText,
    const CryptosystemName &cryptosystemName,
    const SizeT &strength);

  void doKeyGeneration(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const SizeT &strength);
    // write: RECEIVER_PUBLIC, RECEIVER_PRIVATE

  void doEncryption(const string &senderName,
    const string &receiverName);
    // read: RECEIVER_PUBLIC, SENDER_PRIVATE
    // write: SENDER_PUBLIC

  void doDecryption(const string &receiverName,
    const string &senderName);
    // read: RECEIVER_PUBLIC, RECEIVER_PRIVATE,
    //  SENDER_PUBLIC

  void doCryptanalysis(const string &receiverName,
    const string &senderName);
    // read: RECEIVER_PUBLIC, SENDER_PUBLIC

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
void helpTesting();
void helpKeyGeneration();
void helpEncryption();
void helpDecryption();
void helpCryptanalysis();

void setArgV(ArgV &argV, int argc, const char *argv[]);

void verifyCryptosystemName(
  const CryptosystemName& cryptosystemName);

void verifyInputStreamOpening(const ifstream &inputStream);

void testCryptosystem(const Text &plainText,
  const CryptosystemName &cryptosystemName,
  const SizeT &strength);

// testing:

void testActions();

void testInputOutput();

////////////////////////////////////////////////////////////

#endif // PARTY_PARTY_H
