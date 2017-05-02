#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester(SizeT minModulusLength) {
  cryptosystem = new RsaCryptosystem(minModulusLength);
}

Bool RsaTester::testCryptosystem(Text plainText) {
  std::cout << "method RsaTester::testCryptosystem\n";

  std::cout << "key-generation:\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  std::cout << "\tmodulus: " << publicKey.at(0) <<
    "\n\tpublic exponent: " << publicKey.at(1) <<
    "\n\tprivate exponent: " << privateKey.at(1) << "\n";

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
