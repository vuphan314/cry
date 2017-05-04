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

void Party::doKeyGeneration(string &receiversName,
    CryptosystemName &cryptosystemName,
    const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, cryptosystemName
*/
}

void Party::doEncryption(string &sendersName,
    string &receiversName, const char *argv[]) {
/* read parameter argv and
    set parameters sendersName, receiversName
*/
}

void Party::doDecryption(string &receiversName,
    string &sendersName, const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, sendersName
*/
}

void Party::doCryptanalysis(string &receiversName,
    string &sendersName, const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, sendersName
*/
}

// file input/output:

void Party::writeReceiversFiles(const string &receiversName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey) {
  ofstream myFile;

  myFile.open(receiversName + ".public");
  myFile << cryptosystemName << endl;
  for (const KeyElement &keyElement : publicKey) {
    myFile << keyElement << endl;
  }
  myFile.close();

  myFile.open(receiversName + ".private");
  for (const KeyElement &keyElement : privateKey) {
    myFile << keyElement << endl;
  }
  myFile.close();
}

void Party::readReceiversPublicFile(
    CryptosystemName &cryptosystemName, Key &publicKey,
    const string &receiversName) {
  ifstream myFile;
  myFile.open(receiversName + ".public");
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

void Party::readSendersPrivateFile(Text &plainText,
    const string &sendersName) {
/* guide: */
  Text plain;
  string sender("sender");

  ifstream myFile;
  myFile.open(sender + ".private");

  if (myFile.is_open()){
    getline(myFile, plain);
  } else {
    throw DefaultException("file is not open");
  }
  myFile.close();
/* readSendersPrivateFile(plain, sender)
    reads file named "./sender.private" and
    sets parameter plain;
  see examples in directory "../demo/"
*/
}

void Party::writeSendersPublicFile(const string &sendersName,
    const PaddedText &paddedCipherText) {
/* guide: */
  string sender("sender");
  PaddedText cipher(
    "45150111034551695356553471309655905870");

  ofstream myFile;
  myFile.open(sender + ".public");
  myFile << cipher;
  myFile.close();
/* writeSendersPublicFile(sender, cipher)
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
