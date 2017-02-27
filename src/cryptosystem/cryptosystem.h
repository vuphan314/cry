#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H

////////////////////////////////////////////////////////////

enum CryptosystemName {rsa}; // more to come

////////////////////////////////////////////////////////////

using Key = mpz_t; // GNU Multiple Precision Integer Type
using Text = string;

////////////////////////////////////////////////////////////

class Cryptosystem {
public:
  virtual void generateKeys(Key publicKey, Key privateKey);
    // set these

  virtual void encrypt(Text ciphertext, // set this
    const Text plaintext, const Key publicKey);

  virtual void decrypt(Text plaintext, // set this
    const Text ciphertext, const Key privateKey);

  virtual void cryptanalyze(Text plaintext, // set this
    const Text ciphertext, const Key publicKey);
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H
