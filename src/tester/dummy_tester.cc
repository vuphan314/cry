#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester() {
  cryptosystem = new DummyCryptosystem;
}

Bool DummyTester::testCryptosystem(const SizeT &strength,
    const Text &plainText) {
  std::cout << "method DummyTester::testCryptosystem\n";

// key-generation:
  std::cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey,
    strength);
  std::cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) <<
    "\n\tpublic factor: " << publicKey.at(2) <<
    "\n\tsecret factor: " << privateKey.at(2) << "\n";

// plaintext:
  std::cout << "plaintext: " << plainText << "\n";

// encryption:
  std::cout << "encryption:\n";
  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey, strength);

  PaddedText paddedPlainText;
  padText(paddedPlainText, plainText);
  std::cout << "\tpadded plaintext: " << paddedPlainText <<
    "\n";

  std::cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

  Text cipherText;
  unpadText(cipherText, paddedCipherText);
  std::cout << "\tciphertext: " << cipherText << "\n";

// decryption:
  std::cout << "decryption:\n";
  Text t;
  cryptosystem->decrypt(t, paddedCipherText, privateKey);
  std::cout << "\tplaintext: " << t << "\n";

// cryptanalysis:
  std::cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(t, paddedCipherText,
    publicKey);
  std::cout << "\tplaintext: " << t << "\n";

  return TRUE;
}
