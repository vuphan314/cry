#include "dummy_cryptosystem.h"

////////////////////////////////////////////////////////////

void DummyCryptosystem::generateKeys(Key &publicKey,
  Key &privateKey) {};

void DummyCryptosystem::encrypt(Text &cipherText,
  const Text &plainText, const Key &publicKey) {};

void DummyCryptosystem::decrypt(Text &plainText,
  const Text &cipherText, const Key &privateKey) {};

void DummyCryptosystem::cryptanalyze(Text &plainText,
  const Text &cipherText, const Key &publicKey) {};
