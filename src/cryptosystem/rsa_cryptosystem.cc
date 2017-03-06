#include "rsaCryptosystem.h"

////////////////////////////////////////////////////////////

void RsaCryptosystem::generateKeys(Key publicKey,
  Key privateKey) {};

void RsaCryptosystem::encrypt(Text ciphertext,
  const Text plaintext, const Key publicKey) {};

void RsaCryptosystem::decrypt(Text plaintext,
  const Text ciphertext, const Key privateKey) {};

void RsaCryptosystem::cryptanalyze(Text plaintext,
  const Text ciphertext, const Key publicKey) {};
