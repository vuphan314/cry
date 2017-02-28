#include "cryptosystem.h"

////////////////////////////////////////////////////////////

void Cryptosystem::generateKeys(Key publicKey,
  Key privateKey) {};

void Cryptosystem::encrypt(Text ciphertext,
  const Text plaintext, const Key publicKey) {};

void Cryptosystem::decrypt(Text plaintext,
  const Text ciphertext, const Key privateKey) {};

void Cryptosystem::cryptanalyze(Text plaintext,
  const Text ciphertext, const Key publicKey) {};
