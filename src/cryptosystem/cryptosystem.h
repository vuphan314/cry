#ifndef CRYPTOSYSTEM_CRYPTOSYSTEM_H_
#define CRYPTOSYSTEM_CRYPTOSYSTEM_H_

////////////////////////////////////////////////////////////

using IntPtr = mpz_t; // GNU Multiple Precision Integer Type
using Key = IntPtr;
using Text = IntPtr;

////////////////////////////////////////////////////////////

class Cryptosystem {
public:
  virtual void generateKeys(Key publicKey, Key privateKey) // set these
    = 0;

  virtual void encrypt(Text ciphertext, // set this
    const Text plaintext, const Key publicKey) = 0;

  virtual void decrypt(Text plaintext, // set this
    const Text ciphertext, const Key privateKey) = 0;

  virtual void cryptanalyze(Text plaintext, // set this
    const Text ciphertext, const Key publicKey) = 0;
};

////////////////////////////////////////////////////////////

#endif // CRYPTOSYSTEM_CRYPTOSYSTEM_H_
