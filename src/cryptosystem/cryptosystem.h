#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <gmp.h>
#include <gmpxx.h>

#include "../../cplusplus/src/timing.h"

////////////////////////////////////////////////////////////

using SizeT = unsigned long long;

using BigInt = mpz_class; // multiple-precision integer

using KeyElement = BigInt;
using Key = std::vector<KeyElement>;

using PaddedText = BigInt;

using Text = std::string; // unpadded

using Bool = char;
  // 1-byte char is more efficient than 2-byte bool

////////////////////////////////////////////////////////////

const unsigned char TWO_EXP_7 = 128;
const unsigned int TWO_EXP_8 = 256;

const unsigned char CHAR_LENGTH = 8;
const BigInt ALPHABET_SIZE = TWO_EXP_8;

const Bool TRUE = true;
const Bool FALSE = false;

const SizeT COUT_PERIOD = (2 << 15) - 1;
  // &-mask to get least significant bits
const auto COUT_WIDTH = std::setw(15);
const auto COUT_PRECISION = std::setprecision(4);

////////////////////////////////////////////////////////////

class Cryptosystem { // abstract
public:
  Bool verbosity = FALSE;

// purely virtual methods,
// must be defined by non-abstract derived class:
  virtual void generateKeys(
    Key &publicKey, Key &privateKey // set these
    ) = 0;

  virtual void encrypt(Text &cipherText, // set this
    const Text &plainText, const Key &publicKey) = 0;

  virtual void decrypt(Text &plainText, // set this
    const Text &cipherText, const Key &privateKey) = 0;

  virtual void cryptanalyze(Text &plainText, // set this
    const Text &cipherText, const Key &publicKey) = 0;
};

////////////////////////////////////////////////////////////
// global functions:

void setTotient(mpz_t l, mpz_t p, mpz_t q);

// padding/unpadding:

void padText(PaddedText &paddedText, // set this
  const Text &text);

void unpadText(Text &text, // set this
  const PaddedText &paddedText);

// char conversion:

unsigned char getUnsignedChar(char ch);

char getChar(unsigned char uCh);

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
