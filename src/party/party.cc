#include "party.h"

////////////////////////////////////////////////////////////
// class Party:

Party::Party(const CryptosystemName &cryptosystemName) {
  setDataMembers(cryptosystemName);
} // constructor

void Party::setDataMembers(
    const CryptosystemName &cryptosystemName) {
  if (cryptosystemName == DUMMY) {
    tester = new DummyTester;
    cryptosystem = new DummyCryptosystem;
  } else if (cryptosystemName == RSA) {
    tester = new RsaTester;
    cryptosystem = new RsaCryptosystem;
  } else {
      throw DefaultException("wrong cryptosystem name");
  }
}

Bool Party::test() {
  std::cout << "method Party::test\n";
  return tester->testCryptosystem();
}

// command-line argument parsing:

void Party::doAction(int argc, const char *argv[]) {
  if (argc != 4) {
    throw DefaultException("argc must be 4");
  }
  string action = argv[1];
  if (action == KEY_GENERATION) {
    string receiverName = argv[2];
    CryptosystemName cryptosystemName = argv[3];
    doKeyGeneration(receiverName, cryptosystemName);
  } else if (action == ENCRYPTION) {
    string senderName = argv[2], receiverName = argv[3];
    doEncryption(senderName, receiverName);
  } else if (action == DECRYPTION) {
    string receiverName = argv[2], senderName = argv[3];
    doDecryption(receiverName, senderName);
  } else if (action == CRYPTANALYSIS) {
    string receiverName = argv[2], senderName = argv[3];
    doCryptanalysis(receiverName, senderName);
  } else {
    throw DefaultException("argv[1]: wrong Cry action");
  }
}

void Party::doKeyGeneration(const string &receiverName,
    const CryptosystemName &cryptosystemName) {
  cout << "doKeyGeneration started\n";

  verifyCryptosystemName(cryptosystemName);
  setDataMembers(cryptosystemName);
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  writeReceiverFiles(receiverName, cryptosystemName,
    publicKey, privateKey);

  cout << "doKeyGeneration ended\n";
}

void Party::doEncryption(const string &senderName,
    const string &receiverName) {
  cout << "doEncryption started\n";

  CryptosystemName cryptosystemName;
  Key publicKey;
  readReceiverPublicFile(cryptosystemName, publicKey,
    receiverName);
  setDataMembers(cryptosystemName);

  Text plainText;
  readSenderPrivateFile(plainText, senderName);

  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey);
  writeSenderPublicFile(senderName, paddedCipherText);

  cout << "doEncryption ended\n";
}

void Party::doDecryption(const string &receiverName,
    const string &senderName) {
  cout << "doDecryption started\n";

  CryptosystemName cryptosystemName;
  Key privateKey;
  readReceiverFiles(cryptosystemName, privateKey,
    receiverName);
  setDataMembers(cryptosystemName);

  PaddedText paddedCipherText;
  readSenderPublicFile(paddedCipherText, senderName);
  Text plainText;
  cryptosystem->decrypt(plainText, paddedCipherText,
    privateKey);
  cout << "\tplaintext: " << plainText << "\n";

  cout << "doDecryption ended\n";
}

void Party::doCryptanalysis(const string &receiverName,
    const string &senderName) {
  cout << "doCryptanalysis started\n";

  CryptosystemName cryptosystemName;
  Key publicKey;
  readReceiverPublicFile(cryptosystemName, publicKey,
    receiverName);
  setDataMembers(cryptosystemName);

  PaddedText paddedCipherText;
  readSenderPublicFile(paddedCipherText, senderName);
  Text plainText;
  cryptosystem->cryptanalyze(plainText, paddedCipherText,
    publicKey);
  cout << "\tplaintext: " << plainText << "\n";

  cout << "doCryptanalysis ended\n";
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
  outputStream.close(); // needed for re-opening

  outputStream.open(receiverName + PRIVATE_EXTENSION);
  for (const KeyElement &keyElement : privateKey) {
    outputStream << keyElement << endl;
  }

  cout << "writeReceiverFiles wrote files: ./" <<
    receiverName << PUBLIC_EXTENSION << ", ./" <<
    receiverName << PRIVATE_EXTENSION << "\n";
}

void Party::readReceiverFiles(
    CryptosystemName &cryptosystemName,
    Key &privateKey,
    const string &receiverName) {
  ifstream inputStream;
  inputStream.open(receiverName + PUBLIC_EXTENSION);
  verifyInputStreamOpening(inputStream);
  getline(inputStream, cryptosystemName);
  verifyCryptosystemName(cryptosystemName);
  inputStream.close(); // needed for re-opening

  inputStream.open(receiverName + PRIVATE_EXTENSION);
  verifyInputStreamOpening(inputStream);
  privateKey.clear();
  string s;
  while (getline(inputStream, s)) {
    privateKey.push_back(KeyElement(s));
  }
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
}

void Party::readSenderPrivateFile(Text &plainText,
    const string &senderName) {
  ifstream inputStream;
  inputStream.open(senderName + PRIVATE_EXTENSION);
  verifyInputStreamOpening(inputStream);
  getline(inputStream, plainText);
}

void Party::writeSenderPublicFile(const string &senderName,
    const PaddedText &paddedCipherText) {
  ofstream outputStream;
  outputStream.open(senderName + PUBLIC_EXTENSION);
  outputStream << paddedCipherText << endl;

  cout << "writeSenderPublicFile wrote file: ./" <<
    senderName << PUBLIC_EXTENSION << "\n";
}

void Party::readSenderPublicFile(
    PaddedText &paddedCipherText,
    const string &senderName) {
  ifstream inputStream;
  inputStream.open(senderName + PUBLIC_EXTENSION);
  verifyInputStreamOpening(inputStream);
  string s;
  getline(inputStream, s);
  paddedCipherText = PaddedText(s);
}

////////////////////////////////////////////////////////////
// global function:

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

// testing:

void testCryptosystems() {
  std::cout << "function testCryptosystems\n";
  std::vector<CryptosystemName>cryptosystemNames;
  cryptosystemNames.push_back(DUMMY);
  // cryptosystemNames.push_back(RSA);
  for (CryptosystemName cryptosystemName :
      cryptosystemNames) {
    std::cout << "\n";
    Party party(cryptosystemName);
    if (party.test()) {
      std::cout << "Test passed.\n";
    } else {
      std::cout << "Test failed.\n";
    }
  }
  std::cout << "\n";
}

void testActions() {
  cout << "testActions\n\n";

  Party party;
  const int argc = 4;
  const char *executable = "filler",
    *sender = DEFAULT_SENDER.c_str(),
    *receiver = DEFAULT_RECEIVER.c_str(),
    *cryptosystem = "rsa";

  const char *argvG[argc] = {executable,
    KEY_GENERATION.c_str(), receiver, cryptosystem};
  party.doAction(argc, argvG);
  cout << "\n";

  const char *argvE[argc] = {executable, ENCRYPTION.c_str(),
    sender, receiver};
  party.doAction(argc, argvE);
  cout << "\n";

  const char *argvD[argc] = {executable, DECRYPTION.c_str(),
    receiver, sender};
  party.doAction(argc, argvD);
  cout << "\n";

  const char *argvC[argc] = {executable,
    CRYPTANALYSIS.c_str(), receiver, sender};
  party.doAction(argc, argvC);
}

void testInputOutput() {
  cout << "testInputOutput\n\n";

  Party party;
  string receiverName(DEFAULT_RECEIVER);
  CryptosystemName cryptosystemName(RSA);
  KeyElement n("172014975789562774694897382365563045699"),
    e("65537"), d("7542263449887751984019792124906530513");
  Key publicKey{n, e}, privateKey{n, d};

  party.writeReceiverFiles(receiverName, cryptosystemName,
    publicKey, privateKey);

  party.readReceiverFiles(cryptosystemName, privateKey,
    receiverName);
  cout << "readReceiverFiles read:\n\t"
    "cryptosystemName: " << cryptosystemName << "\n\t"
    "privateKey:\n";
  for (const KeyElement &keyElement : privateKey) {
    cout << "\t\t" << keyElement << "\n";
  }

  party.readReceiverPublicFile(cryptosystemName, publicKey,
    receiverName);
  cout << "readReceiverPublicFile read:\n\t"
    "cryptosystemName: " << cryptosystemName << "\n\t"
    "publicKey:\n";
  for (const KeyElement &keyElement : publicKey) {
    cout << "\t\t" << keyElement << "\n";
  }

  Text plainText;
  string senderName(DEFAULT_SENDER);

  party.readSenderPrivateFile(plainText, senderName);
  cout << "readSenderPrivateFile read:\n\t"
    "plainText: " << plainText << "\n";

  PaddedText paddedCipherText(
    "45150111034551695356553471309655905870");

  party.writeSenderPublicFile(senderName, paddedCipherText);

  party.readSenderPublicFile(paddedCipherText, senderName);
  cout << "readSenderPublicFile read:\n\t"
    "paddedCipherText: " << paddedCipherText << "\n";
}
