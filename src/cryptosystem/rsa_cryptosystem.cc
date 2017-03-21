#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////

void RsaCryptosystem::generateKeys(Key &publicKey,
  Key &privateKey) {};

void RsaCryptosystem::encrypt(Text &cipherText,
  const Text &plainText, const Key &publicKey) {};

void RsaCryptosystem::decrypt(Text &plainText,
  const Text &cipherText, const Key &privateKey) {};

void RsaCryptosystem::cryptanalyze(Text &plainText,
  const Text &cipherText, const Key &publicKey) {};

////////////////////////////////////////////////////////////
// testing

Bool RsaCryptosystem::testCryptosystem() {
  std::cout << "Testing class RsaCryptosystem.\n";
  return Cryptosystem::testCryptosystem();
}
