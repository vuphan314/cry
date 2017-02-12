using IntRef = mpz_t; // GNU Multiple Precision Integer Type
using Key = IntRef;
using Text = IntRef;

////////////////////////////////////////////////////////////

class Cryptosystem {
public:
  void generateKeys(Key publickey, Key privatekey); // set these

  void encrypt(Text ciphertext, // set this
    const Text plaintext, const Key publickey);

  void decrypt(Text plaintext, // set this
    const Text ciphertext, const Key privatekey);

  void cryptanalyze(Text plaintext, // set this
    const Text ciphertext, const Key publickey);
};
