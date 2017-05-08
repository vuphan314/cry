#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
}

void RsaTester::testCryptosystem(const SizeT &strength,
    const Text &plainText) {
  cout << "method RsaTester::testCryptosystem\n";

// key-generation:
  cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey,
    strength);
  cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) << "\n";

// plaintext:
  cout << "plaintext: " << plainText << "\n";

// encryption:
  cout << "encryption:\n";
  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey, strength);
  cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

// decryption:
  cout << "decryption:\n";
  Text t;
  cryptosystem->decrypt(t, paddedCipherText, privateKey);
  cout << "\tplaintext: " << t << "\n";

// cryptanalysis:
  cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(t, paddedCipherText,
    publicKey);
  cout << "\tplaintext: " << t;
}
