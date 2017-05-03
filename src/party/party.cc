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
    return KEY_GENERATION;
  } else if (condition) { // replace by proper condition
    return ENCRYPTION;
  } else if (condition) { // replace by proper condition
    return DECRYPTION;
  } else if (condition) { // replace by proper condition
    return CRYPTANALYSIS;
  } else {
    std::cout << "wrong action\n";
    throw exception();
  }
}

// file input/output:

void Party::writeReceiversFiles(const string &receiversName,
    const CryptosystemName &cryptosystemName,
    const Key &publicKey, const Key &privateKey) {
/* guide: */
  string receiver("receiver");
  CryptosystemName cn(RSA);
  KeyElement n("172014975789562774694897382365563045699"),
    e("65537"), d("7542263449887751984019792124906530513");
  Key publicK{n, e}, privateK{n, d};

  ofstream myFile;
  myFile.open(receiver + ".public");
  myFile << cn << endl << n << endl << e;
  myFile.close();
  myFile.open(receiver + ".private");
  myFile << cn << endl << n << endl << d;
  myFile.close();
/* writeReceiversFiles(receiver, cn, publicK, privateK)
    (over)writes files named "./receiver.public",
    "./receiver.private";
  see examples in directory "../demo/"
*/
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
    cout << "NOPE" << endl;
  }
  if (cryptoName == "RSA"){
    cn = RSA;
  } else if (cryptoName == "DUMMY"){
    cn = DUMMY;
  } else {
    throw "unknown cryptosystem";
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
    cout << "NOPE" << endl;
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
  switch (cryptosystemName) {
    case DUMMY:
      return new DummyTester;
    case RSA:
      return new RsaTester;
    default:
      std::cout << "Wrong cryptosystem name.\n";
      throw std::exception();
  }
}
