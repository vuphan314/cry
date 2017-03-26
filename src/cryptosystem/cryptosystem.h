#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>

#include <gmp.h>
#include <gmpxx.h>

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

const BigInt ALPHABET_SIZE(256);

const Bool TRUE = true;
const Bool FALSE = false;

////////////////////////////////////////////////////////////

class Cryptosystem {
public:
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

void padText(PaddedText &paddedText, // set this
  const Text &text);

void unpadText(Text &text, // set this
  PaddedText paddedText); // pass this by value

unsigned char getUnsignedChar(char ch);

char getChar(unsigned char uCh);

Bool testPaddingUnpadding();

Bool testCharConversion();

void printText(const Text &text);

////////////////////////////////////////////////////////////

class CryptosystemTester {
protected:
  Cryptosystem *cryptosystem;

public:
  Bool testAll();

  virtual Bool testKeyGeneration() = 0;

  virtual Bool testEncryption() = 0;

  virtual Bool testDecryption() = 0;

  virtual Bool testCryptanalysis() = 0;
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
