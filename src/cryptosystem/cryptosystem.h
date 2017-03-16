#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include <gmp.h>
#include <gmpxx.h>

////////////////////////////////////////////////////////////

using BigInt = mpz_class; // multiple-precision integer

using KeyComponent = BigInt;
using Key = vector<KeyComponent>;

using Text = string; // unpadded
using PaddedText = BigInt;

////////////////////////////////////////////////////////////

class Cryptosystem {
// private:
//   Key publicKey, privateKey;
//   Text plainText, cipherText;
//   PaddedText paddedPlainText, paddedCipherText;

public:
// purely virtual:
  virtual void generateKeys(Key &publicKey, Key &privateKey) = 0;
    // set these

  virtual void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey) = 0;

  virtual void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey) = 0;

  virtual void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey) = 0;

// impurely virtual:
  virtual void testCryptosystem();

// nonvirtual:
  void padText(PaddedText &paddedText, const Text &text);

  void unpadText(Text &text, const PaddedText &paddedText);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
