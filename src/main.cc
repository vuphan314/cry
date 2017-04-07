#include "party/party.h"

////////////////////////////////////////////////////////////

void testCryptosystems() {
  std::cout << "\nfunction testCryptosystems:\n";
  std::vector<CryptosystemName>
    cryptosystemNames{RSA, DUMMY};
  for (CryptosystemName cryptosystemName :
      cryptosystemNames) {
    std::cout << "\n";
    Party party(cryptosystemName);
    if (party.testParty()) {
      std::cout << "All tests passed.\n";
    } else {
      std::cout << "Some test failed.\n";
    }
  }
}

////////////////////////////////////////////////////////////

void demoRsa() {
  std::cout << "\nfunction demoRsa:\n\n";
  RsaCryptosystem rsaCryptosystem;

  Key publicKey, privateKey;
  rsaCryptosystem.generateKeys(publicKey, privateKey);
  std::cout << "key-generation:\n\tmodulus: " <<
    publicKey.at(0) << "\n\tpublic exponent: " <<
    publicKey.at(1) << "\n\tprivate exponent: " <<
    privateKey.at(1) << "\n";

  Text plainText = "my string", cipherText;
  std::cout << "plaintext: " << plainText << "\n";

  rsaCryptosystem.encrypt(cipherText, plainText, publicKey);
  std::cout << "encryption:\n\tciphertext: " <<
    cipherText << "\n";

  rsaCryptosystem.decrypt(plainText, cipherText,
    privateKey);
  std::cout << "decryption:\n\tplaintext: " << plainText <<
    "\n";

  rsaCryptosystem.cryptanalyze(plainText, cipherText,
    publicKey);
  std::cout << "cryptanalysis:\n\tplaintext: " <<
    plainText << "\n";
}

////////////////////////////////////////////////////////////

int main() {
  // testCryptosystems();
  demoRsa();
}
