#include "party/party.h"

////////////////////////////////////////////////////////////

void testInputOutput() {
  cout << "testInputOutput:\n\n";

  Party party;
  string receiverName("party_receiver");
  CryptosystemName cryptosystemName(RSA);
  KeyElement n("172014975789562774694897382365563045699"),
    e("65537"), d("7542263449887751984019792124906530513");
  Key publicKey{n, e}, privateKey{n, d};

  party.writeReceiverFiles(receiverName, cryptosystemName,
    publicKey, privateKey);
  cout << "writeReceiverFiles wrote:\n\t"
    "./" << receiverName << ".*\n";

  party.readReceiverPublicFile(cryptosystemName, publicKey,
    receiverName);
  cout << "readReceiverPublicFile read:\n\t"
    "cryptosystemName: " << cryptosystemName << "\n\t"
    "publicKey:\n";
  for (const KeyElement &keyElement : publicKey) {
    cout << "\t\t" << keyElement << "\n";
  }

  Text plainText;
  string senderName("party_sender");

  party.readSenderPrivateFile(plainText, senderName);
  cout << "readSenderPrivateFile read:\n\t"
    "plainText: " << plainText << "\n";

  PaddedText paddedCipherText(
    "45150111034551695356553471309655905870");

  party.writeSenderPublicFile(senderName, paddedCipherText);
  cout << "writeSenderPublicFile wrote:\n\t"
    "./" << senderName << PUBLIC_EXTENSION << "\n";

  party.readSenderPublicFile(paddedCipherText, senderName);
  cout << "readSenderPublicFile read:\n\t"
    "paddedCipherText: " << paddedCipherText << "\n";
}

////////////////////////////////////////////////////////////

void breakRsa(SizeT minModulusLength =
    BREAKABLE_MIN_MODULUS_LENGTH,
    Text plainText = BREAKABLE_PLAIN_TEXT) {
  std::cout << "function breakRsa\n";
  RsaTester rsaTester(minModulusLength);
  rsaTester.testCryptosystem(plainText);
  std::cout << "\n";
}

////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////

int main(int argc, const char *argv[]) {
  std::cout << "\n";
  testInputOutput();
  // switch (argc) {
  //   case 1:
  //     breakRsa();
  //     break;
  //   case 3:
  //     breakRsa(atoi(argv[1]), argv[2]);
  //     break;
  //   default:
  //     cout << "wrong argc\n";
  //     throw std::exception();
  // }
  // testCryptosystems();
  // testPaddingUnpadding();
  // testCharConversion();
}
