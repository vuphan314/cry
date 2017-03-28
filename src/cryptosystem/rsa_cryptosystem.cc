#include "rsa_cryptosystem.h"

// http://stackoverflow.com/questions/9791761/using-gmp-for
//  -cryptography-how-to-get-random-numbers

////////////////////////////////////////////////////////////
// class RsaCryptosystem:

// private helper methods:

void RsaCryptosystem::setPublicKeyElements(
    const Key &publicKey) {
  modulus = publicKey.at(0);
  publicExponent = publicKey.at(1);
}

void RsaCryptosystem::setPrivateKeyElements(
    const Key &privateKey) {
  modulus = privateKey.at(0);
  privateExponent = privateKey.at(1);
}

// private overloaded methods:

void RsaCryptosystem::generateKeys() {
  mpz_t rand_num;
  gmp_randstate_t r_state;
  mpz_init2(rand_num, 512);
  gmp_randinit_default(r_state);

  mpz_t r_min;
  mpz_init_set_ui(r_min, 256);

  mpz_t r_max;
  mpz_init_set_ui(r_max, 512);

  do{
    mpz_urandomm(rand_num, r_state, r_max);
  } while(mpz_cmp(rand_num, r_min) < 0);

  std::cout << rand_num << std::endl;

  // modulus = 3233;
  // publicExponent = 17;
  // privateExponent = 413;
// replace the lines above by RSA key-generation
}

void RsaCryptosystem::encrypt() {
  padText(paddedPlainText, plainText);
  std::cout << "Daniel got this!\n";
  paddedCipherText = paddedPlainText;
    // replace the line above by RSA encyption
  unpadText(cipherText, paddedCipherText);
}

void RsaCryptosystem::decrypt() {
  padText(paddedCipherText, cipherText);
  paddedPlainText = paddedCipherText;
    // replace the line above by RSA decryption
  unpadText(plainText, paddedPlainText);
}

void RsaCryptosystem::cryptanalyze() {
  padText(paddedCipherText, cipherText);
  paddedPlainText = paddedCipherText;
    // replace the line above by RSA cryptanalysis
  unpadText(plainText, paddedPlainText);
}

// public overloaded methods:

void RsaCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  generateKeys();
  publicKey = {modulus, publicExponent};
  privateKey = {modulus, privateExponent};
}

void RsaCryptosystem::encrypt(Text &cipherText,
    const Text &plainText, const Key &publicKey) {
  this->plainText = plainText;
  setPublicKeyElements(publicKey);
  encrypt();
  cipherText = this->cipherText;
}

void RsaCryptosystem::decrypt(Text &plainText,
    const Text &cipherText, const Key &privateKey) {
  this->cipherText = cipherText;
  setPrivateKeyElements(privateKey);
  decrypt();
  plainText = this->plainText;
}

void RsaCryptosystem::cryptanalyze(Text &plainText,
    const Text &cipherText, const Key &publicKey) {
  this->cipherText = cipherText;
  setPublicKeyElements(publicKey);
  cryptanalyze();
  plainText = this->plainText;
}
