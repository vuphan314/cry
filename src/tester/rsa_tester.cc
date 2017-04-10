#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
}

void RsaTester::demo(SizeT minModulusLength, Text plainText) {
  std::cout << "method RsaTester::demo\n";

  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey,
    minModulusLength);
  std::cout << "key-generation:\n\tmodulus: " <<
    publicKey.at(0) << "\n\tpublic exponent: " <<
    publicKey.at(1) << "\n\tprivate exponent: " <<
    privateKey.at(1) << "\n";

  std::cout << "plaintext: \"" << plainText << "\"\n";

  Text cipherText;
  cryptosystem->encrypt(cipherText, plainText, publicKey);
  std::cout << "encryption:\n\tciphertext: \"" <<
    cipherText << "\"\n";

  cryptosystem->decrypt(plainText, cipherText,
    privateKey);
  std::cout << "decryption:\n\tplaintext: \"" <<
    plainText << "\"\n";

  // std::cout << "cryptanalysis:\n";
  // cryptosystem->cryptanalyze(plainText, cipherText,
  //   publicKey);
  // std::cout << "\tplaintext: \"" << plainText << "\"\n";
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
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  Text cipherText, plainText = "my plain text";
  cryptosystem->encrypt(cipherText, plainText, publicKey);
  return TRUE; // is cipherText set as expected?
}

Bool RsaTester::testDecryption() {
  std::cout << "method RsaTester::testDecryption\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  Text plainText, cipherText = "jkasUAYDSB823746?><&^";
  cryptosystem->decrypt(plainText, cipherText, privateKey);
  return TRUE; // is plainText set as expected?
}

Bool RsaTester::testCryptanalysis() {
  std::cout << "method RsaTester::testCryptanalysis\n";
  Key publicKey, privateKey;
  cryptosystem->generateKeys(publicKey, privateKey);
  Text plainText, cipherText = "jkasUAYDSB823746?><&^";
  cryptosystem->decrypt(plainText, cipherText, publicKey);
  return TRUE; // is plainText set as expected?
}
