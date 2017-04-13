#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester(SizeT minModulusLength) {
  cryptosystem = new RsaCryptosystem(minModulusLength);
}

void RsaTester::demo(Text plainText) {
  std::cout << "method RsaTester::demo\n";

  std::cout << "key-generation ";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  std::cout << "\tmodulus: " <<
    publicKey.at(0) << "\n\tpublic exponent: " <<
    publicKey.at(1) << "\n\tprivate exponent: " <<
    privateKey.at(1) << "\n";

  std::cout << "plaintext: " << plainText << "\n";

  std::cout << "encryption ";
  PaddedText paddedCipherText;
  cryptosystem->encrypt(paddedCipherText, plainText,
    publicKey);
  std::cout << "\tpadded ciphertext: " <<
    paddedCipherText << "\n";

  cryptosystem->decrypt(plainText, paddedCipherText,
    privateKey);
  std::cout << "decryption:\n\tplaintext: " << plainText <<
    "\n";

  std::cout << "cryptanalysis:\n";
  cryptosystem->cryptanalyze(plainText, paddedCipherText,
    publicKey);
  std::cout << "\tplaintext: " << plainText << "\n";
}

Bool RsaTester::testKeyGeneration() {
  std::cout << "method RsaTester::testKeyGeneration\n";
  Key publicKey, privateKey;
  cryptosystem->verbosity = TRUE;
  cryptosystem->generateKeys(publicKey, privateKey);
  cryptosystem->verbosity = FALSE;
  return TRUE; // are publicKey/privateKey set as expected?
}

Bool RsaTester::testEncryption() {
  std::cout << "method RsaTester::testEncryption\n";
  // Key publicKey, privateKey;
  // cryptosystem->generateKeys(publicKey, privateKey);
  // Text plainText = "my plain text";
  // PaddedText paddedCipherText;
  // cryptosystem->encrypt(paddedCipherText, plainText,
  //   publicKey);
  return TRUE; // is cipherText set as expected?
}

Bool RsaTester::testDecryption() {
  std::cout << "method RsaTester::testDecryption\n";
  // Key publicKey, privateKey;
  // cryptosystem->generateKeys(publicKey, privateKey);
  // PaddedText paddedCipherText = DEFAULT_PADDED_CIPHER_TEXT;
  // Text plainText;
  // cryptosystem->decrypt(plainText, paddedCipherText,
  //   privateKey);
  return TRUE; // is plainText set as expected?
}

Bool RsaTester::testCryptanalysis() {
  std::cout << "method RsaTester::testCryptanalysis\n";
  // Key publicKey, privateKey;
  // cryptosystem->generateKeys(publicKey, privateKey);
  // PaddedText paddedCipherText = DEFAULT_PADDED_CIPHER_TEXT;
  // Text plainText;
  // cryptosystem->decrypt(plainText, paddedCipherText,
  //   publicKey);
  return TRUE; // is plainText set as expected?
}
