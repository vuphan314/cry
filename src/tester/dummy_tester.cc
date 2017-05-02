#include "dummy_tester.h"

////////////////////////////////////////////////////////////
// class DummyTester:

DummyTester::DummyTester(SizeT minModulusLength) {
  cryptosystem = new DummyCryptosystem(minModulusLength);
}

Bool DummyTester::testCryptosystem(Text plainText) {
  std::cout << "method DummyTester::testCryptosystem\n";

  std::cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  std::cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) <<
    "\n\tpublic addend: " << publicKey.at(2) <<
    "\n\tsecret addend: " << privateKey.at(2) << "\n";

  std::cout << "plaintext: \"" << plainText << "\"\n";

  std::cout << "encryption:\n";
  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey);
  std::cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

  cryptosystem->decrypt(plainText, paddedCipherText,
    privateKey);
  std::cout << "decryption:\n\tplaintext: \"" <<
    plainText << "\"\n";

  std::cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(plainText, paddedCipherText,
    publicKey);
  std::cout << "\tplaintext: \"" << plainText << "\"\n";

  return TRUE;
}
