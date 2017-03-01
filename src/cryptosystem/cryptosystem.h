#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <utility>

#include <gmp.h>

////////////////////////////////////////////////////////////

using Key = mpz_t; // GNU Multiple Precision Integer Type
using Text = string;

////////////////////////////////////////////////////////////

class Cryptosystem {
public:
  virtual void generateKeys(Key publicKey, Key privateKey) = 0;
    // set these

  virtual void encrypt(Text ciphertext, // set this
    const Text plaintext, const Key publicKey) = 0;

  virtual void decrypt(Text plaintext, // set this
    const Text ciphertext, const Key privateKey) = 0;

  virtual void cryptanalyze(Text plaintext, // set this
    const Text ciphertext, const Key publicKey) = 0;
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
