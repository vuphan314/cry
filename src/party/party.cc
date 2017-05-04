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
  ofstream outputStream;

  outputStream.open(receiverName + PUBLIC_EXTENSION);
  outputStream << cryptosystemName << endl;
  for (const KeyElement &keyElement : publicKey) {
    outputStream << keyElement << endl;
  }
  outputStream.close();

  outputStream.open(receiverName + PRIVATE_EXTENSION);
  for (const KeyElement &keyElement : privateKey) {
    outputStream << keyElement << endl;
  }
  outputStream.close();
}

void Party::readReceiverPublicFile(
    CryptosystemName &cryptosystemName, Key &publicKey,
    const string &receiverName) {
  ifstream inputStream;
  inputStream.open(receiverName + PUBLIC_EXTENSION);
  verifyInputStreamOpening(inputStream);

  getline(inputStream, cryptosystemName);
  verifyCryptosystemName(cryptosystemName);

  publicKey.clear();
  string s;
  while (getline(inputStream, s)) {
    publicKey.push_back(KeyElement(s));
  }

  inputStream.close();
}

void Party::readSenderPrivateFile(Text &plainText,
    const string &senderName) {
  ifstream inputStream;
  inputStream.open(senderName + PRIVATE_EXTENSION);
  verifyInputStreamOpening(inputStream);

  getline(inputStream, plainText);

  inputStream.close();
}

void Party::writeSenderPublicFile(const string &senderName,
    const PaddedText &paddedCipherText) {
  ofstream outputStream;
  outputStream.open(senderName + PUBLIC_EXTENSION);

  outputStream << paddedCipherText << endl;

  outputStream.close();
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

void verifyInputStreamOpening(const ifstream &inputStream) {
  if (!inputStream.is_open()) {
    throw DefaultException("opening input-file failed");
  }
}
