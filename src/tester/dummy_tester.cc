#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester() {
  cryptosystem = new DummyCryptosystem;
}

Bool DummyTester::testCryptosystem(const SizeT &strength,
    const Text &plainText) {
  cout << "method DummyTester::testCryptosystem\n";

// key-generation:
  cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey,
    strength);
  cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) <<
    "\n\tpublic factor: " << publicKey.at(2) <<
    "\n\tsecret factor: " << privateKey.at(2) << "\n";

// plaintext:
  cout << "plaintext: " << plainText << "\n";

// encryption:
  cout << "encryption:\n";

  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey, strength);

  PaddedText paddedPlainText;
  padText(paddedPlainText, plainText);
  cout << "\tpadded plaintext: " << paddedPlainText <<
    "\n";

  cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

  Text cipherText;
  unpadText(cipherText, paddedCipherText);
  cout << "\tciphertext: " << cipherText << "\n";

// decryption:
  cout << "decryption:\n";
  Text t;
  cryptosystem->decrypt(t, paddedCipherText, privateKey);
  cout << "\tplaintext: " << t << "\n";

// cryptanalysis:
  cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(t, paddedCipherText,
    publicKey);
  cout << "\tplaintext: " << t << "\n";

// return:
  return TRUE;
}
