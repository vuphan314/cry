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
/* guide: */
  CryptosystemName cn;
  Key publicK;
  string receiver("receiver");

  ifstream myFile;
  myFile.open(receiver + ".public");

  string n;
  string e;
  string cryptoName;

  if (myFile.is_open()){
    getline(myFile, cryptoName);
    getline(myFile, n);
    getline(myFile, e);
  } else {
    throw DefaultException("file is not open");
  }
  if (cryptoName == RSA){
    cn = RSA;
  } else if (cryptoName == DUMMY){
    cn = DUMMY;
  } else {
    throw DefaultException("wrong cryptosystem name");
  }
  publicK[0] = stoi(n);
  publicK[1] = stoi(e);
  myFile.close();
/* readReceiversPublicFile(cn, publicK, receiver)
    reads file named "./receiver.public" and
    sets parameters cn, publicK;
  see examples in directory "../demo/"
*/
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
