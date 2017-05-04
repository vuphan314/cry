#include "party.h"

////////////////////////////////////////////////////////////
// class Party:

Party::Party(CryptosystemName cryptosystemName) {
  tester = getTester(cryptosystemName);
}

Bool Party::test() {
  std::cout << "method Party::test\n";
  return tester->testCryptosystem();
}

// command-line argument parsing:

Action Party::getAction(int argc, const char *argv[]) {
  Bool condition;
  if (condition) { // replace by proper condition
    // $ cry generatekeys <receiver> <cryptosystem>
    return KEY_GENERATION;
  } else if (condition) { // replace by proper condition
    // $ cry encrypt <sender> <receiver>
    return ENCRYPTION;
  } else if (condition) { // replace by proper condition
    // $ cry decrypt <receiver> <sender>
    return DECRYPTION;
  } else if (condition) { // replace by proper condition
    // $ cry cryptanalyze <receiver> <sender>
    return CRYPTANALYSIS;
  } else {
    throw DefaultException("wrong command");
  }
}

void Party::doKeyGeneration(string &receiverName,
    CryptosystemName &cryptosystemName,
    const char *argv[]) {
/* read parameter argv and
    set parameters receiverName, cryptosystemName
*/
}

void Party::doEncryption(string &senderName,
    string &receiverName, const char *argv[]) {
/* read parameter argv and
    set parameters senderName, receiverName
*/
}

void Party::doDecryption(string &receiverName,
    string &senderName, const char *argv[]) {
/* read parameter argv and
    set parameters receiverName, senderName
*/
}

void Party::doCryptanalysis(string &receiverName,
    string &senderName, const char *argv[]) {
/* read parameter argv and
    set parameters receiverName, senderName
*/
}

// file input/output:

void Party::writeReceiverFiles(const string &receiverName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey) {
  ofstream myFile;

  myFile.open(receiverName + ".public");
  myFile << cryptosystemName << endl;
  for (const KeyElement &keyElement : publicKey) {
    myFile << keyElement << endl;
  }
  myFile.close();

  myFile.open(receiverName + ".private");
  for (const KeyElement &keyElement : privateKey) {
    myFile << keyElement << endl;
  }
  myFile.close();
}

void Party::readReceiverPublicFile(
    CryptosystemName &cryptosystemName, Key &publicKey,
    const string &receiverName) {
  ifstream myFile;
  myFile.open(receiverName + ".public");
  if (myFile.is_open()){
    getline(myFile, cryptosystemName);
    verifyCryptosystemName(cryptosystemName);

    publicKey.clear();
    string s;
    while (getline(myFile, s)) {
      publicKey.push_back(KeyElement(s));
    }

    myFile.close();
  } else {
    throw DefaultException("file is not open");
  }
}

void Party::readSenderPrivateFile(Text &plainText,
    const string &senderName) {
  ifstream myFile;
  myFile.open(senderName + ".private");

  if (myFile.is_open()){
    getline(myFile, plainText);
  } else {
    throw DefaultException("file is not open");
  }
  myFile.close();
}

void Party::writeSenderPublicFile(const string &senderName,
    const PaddedText &paddedCipherText) {
/* guide: */
  string sender("sender");
  PaddedText cipher(
    "45150111034551695356553471309655905870");

  ofstream myFile;
  myFile.open(sender + ".public");
  myFile << cipher;
  myFile.close();
/* writeSenderPublicFile(sender, cipher)
    (over)writes file named "./sender.public";
  see examples in directory "../demo/"
*/
}

////////////////////////////////////////////////////////////
// global function:

Tester *getTester(CryptosystemName cryptosystemName) {
  if (cryptosystemName == DUMMY) {
    return new DummyTester;
  } else if (cryptosystemName == RSA) {
      return new RsaTester;
  } else {
      throw DefaultException("wrong cryptosystem name");
  }
}

void verifyCryptosystemName(const CryptosystemName&
    cryptosystemName) {
  if (CRYPTOSYSTEM_NAMES.find(cryptosystemName) ==
      CRYPTOSYSTEM_NAMES.end()) {
    throw DefaultException("wrong cryptosystem name");
  }
}
