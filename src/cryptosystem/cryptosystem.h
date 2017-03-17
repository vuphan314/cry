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

using Int = unsigned long long; // small

using BigInt = mpz_class; // multiple-precision integer

using KeyElement = BigInt;
using Key = vector<KeyElement>;

using PaddedText = BigInt;

using Text = string; // unpadded

////////////////////////////////////////////////////////////

const BigInt ALPHABET_SIZE(256);

////////////////////////////////////////////////////////////

class Cryptosystem {
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

// non-virtual:
  void padText(PaddedText &paddedText, const Text &text);

  void unpadText(Text &text,
    PaddedText paddedText); // pass by value
};

////////////////////////////////////////////////////////////

void printText(const Text &text);

////////////////////////////////////////////////////////////

void testCharConversion();

unsigned char getUnsignedChar(char ch);

char getChar(unsigned char uCh);

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
