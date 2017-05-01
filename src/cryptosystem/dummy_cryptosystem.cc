#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////
// class DummyCryptosystem:

void DummyCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  RsaCryptosystem::generateKeys();
  privateAddend = DEFAULT_PRIVATE_ADDEND;
  paddedPlainText = privateAddend;
  RsaCryptosystem::encrypt();
  publicAddend = paddedCipherText;
  publicKey.push_back(publicAddend);
  privateKey.push_back(privateAddend);
}

void DummyCryptosystem::encrypt(
  PaddedText &paddedCipherText, const Text &plainText,
  const Key &publicKey) {}

void DummyCryptosystem::decrypt(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &privateKey) {}

void DummyCryptosystem::cryptanalyze(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &publicKey) {}
