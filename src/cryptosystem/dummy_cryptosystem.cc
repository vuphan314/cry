#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////
// class DummyCryptosystem:

void DummyCryptosystem::generateKeys(Key &publicKey,
  Key &privateKey) {};

void DummyCryptosystem::encrypt(
  PaddedText &paddedCipherText, const Text &plainText,
  const Key &publicKey) {};

void DummyCryptosystem::decrypt(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &privateKey) {};

void DummyCryptosystem::cryptanalyze(Text &plainText,
  const PaddedText &paddedCipherText,
  const Key &publicKey) {};
