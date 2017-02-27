#include "rsa.h"

////////////////////////////////////////////////////////////

void Rsa::generateKeys(Key publicKey, Key privateKey) {};

void Rsa::encrypt(Text ciphertext,
  const Text plaintext, const Key publicKey) {};

void Rsa::decrypt(Text plaintext,
  const Text ciphertext, const Key privateKey) {};

void Rsa::cryptanalyze(Text plaintext,
  const Text ciphertext, const Key publicKey) {};
