#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
}

Bool RsaTester::testCryptosystem(SizeT strength,
    Text plainText) {
  std::cout << "method RsaTester::testCryptosystem\n";

// key-generation:
  std::cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey,
    strength);
  std::cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) << "\n";

// plaintext:
  std::cout << "plaintext: " << plainText << "\n";

// encryption:
  std::cout << "encryption:\n";
  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey, strength);
  std::cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

// decryption:
  cryptosystem->decrypt(plainText, paddedCipherText,
    privateKey);
  std::cout << "decryption:\n\tplaintext: " <<
    plainText << "\n";

// cryptanalysis:
  std::cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(plainText, paddedCipherText,
    publicKey);
  std::cout << "\tplaintext: " << plainText << "\n";

  return TRUE;
}
