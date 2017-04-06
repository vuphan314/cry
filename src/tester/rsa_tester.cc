#include "rsa_tester.h"

////////////////////////////////////////////////////////////
// class RsaTester:

RsaTester::RsaTester() {
  cryptosystem = new RsaCryptosystem;
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
