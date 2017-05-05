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
  if (argv[1].compare("generatekeys")) { // replace by proper condition
    // $ cry generatekeys <receiver> <cryptosystem>
    return KEY_GENERATION;
  } else if (argv[1].compare("encrypt")) { // replace by proper condition
    // $ cry encrypt <sender> <receiver>
    return ENCRYPTION;
  } else if (argv[1].compare("decrypt")) { // replace by proper condition
    // $ cry decrypt <receiver> <sender>
    return DECRYPTION;
  } else if (argv[1].compare("cryptanalyze")) { // replace by proper condition
    // $ cry cryptanalyze <receiver> <sender>
    return CRYPTANALYSIS;
  } else {
    std::cout << "wrong command\n";
    throw exception();
  }
}

void Party::doKeyGeneration(string &receiversName,
    CryptosystemName &cryptosystemName,
    const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, cryptosystemName
*/
    receiversName = argv[2]
    cryptosystemName = argv[3]
}

void Party::doEncryption(string &sendersName,
    string &receiversName, const char *argv[]) {
/* read parameter argv and
    set parameters sendersName, receiversName
*/
    sendersName = argv[2]
    receiversName = argv[3]
}

void Party::doDecryption(string &receiversName,
    string &sendersName, const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, sendersName
*/
    receiversName = argv[2]
    sendersName = argv[3]
}

void Party::doCryptanalysis(string &receiversName,
    string &sendersName, const char *argv[]) {
/* read parameter argv and
    set parameters receiversName, sendersName
*/
    receiversName = argv[2]
    sendersName = argv[3]
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
