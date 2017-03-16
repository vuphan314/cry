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

using PaddedText = BigInt;

using KeyElement = BigInt;
using Key = vector<KeyElement>;

using UnsignedChar = unsigned char;

using Char = char; // signed
using String = basic_string<Char>;
using Text = String; // unpadded

////////////////////////////////////////////////////////////

const unsigned int TOTAL_CHAR_COUNT = 256;

const BigInt ALPHABET_SIZE(TOTAL_CHAR_COUNT);

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

  void unpadText(Text &text, PaddedText &paddedText);
};

////////////////////////////////////////////////////////////

void testCharSign();

UnsignedChar getUnsignedChar(const Char ch);

Char getChar(const UnsignedChar uCh);

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
