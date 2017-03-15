#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

#include <gmp.h>
#include <gmpxx.h>

////////////////////////////////////////////////////////////

using BigInt = mpz_class; // multiple-precision integer
using Key = BigInt;
using Text = BigInt; // padded

using UnpaddedText = string;

////////////////////////////////////////////////////////////

class Cryptosystem {
// private:
//   Key publicKey, privateKey;
//   Text plainText, cipherText;
//   UnpaddedText unpaddedPlainText, unpaddedCipherText;

public:
  virtual void generateKeys(Key &publicKey, Key &privateKey) = 0;
    // set these

  virtual void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey) = 0;

  virtual void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey) = 0;

  virtual void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey) = 0;

  void padText(Text &text, const UnpaddedText &UnpaddedText);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
