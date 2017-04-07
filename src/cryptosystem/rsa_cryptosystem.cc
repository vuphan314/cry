/*
http://stackoverflow.com/questions/9791761/using-gmp-for-cryptography-how-to-get-random-numbers
*/

////////////////////////////////////////////////////////////

#include "rsa_cryptosystem.h"

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
  unsigned int MINIMUM_MODULUS_LENGTH = 1024;
  unsigned int PRIME_LENGTH = (MINIMUM_MODULUS_LENGTH/2)-1;
  unsigned int seed = 672087;

  mpz_t p;
  mpz_t q;
  mpz_t N;
  mpz_t L;
  mpz_t d;
  mpz_t e;
  mpz_t twoToThePowerOf512;
  mpz_t mod;
  mpz_t testValue;

  mpz_init(p);
  mpz_init(q);
  mpz_init(N);
  mpz_init(L);
  mpz_init(d);
  mpz_init_set_ui(e, 65537);
  mpz_init(mod);
  mpz_init_set_ui(twoToThePowerOf512, 1);

  mpz_mul_2exp(twoToThePowerOf512, twoToThePowerOf512,
    PRIME_LENGTH);

  //******************************************************//
  //  THIS MAKES THE ALGORITHM CRYPTOGRAHICALLY INSECURE  //
  /**/           gmp_randstate_t state;                   //
  /**/           gmp_randinit_default(state);             //
  /**/           gmp_randseed_ui(state, seed);            //
  //******************************************************//

  do{
    mpz_urandomb(p, state, PRIME_LENGTH);
    mpz_add(p, p, twoToThePowerOf512);

    mpz_urandomb(q, state, PRIME_LENGTH);
    mpz_add(q, q, twoToThePowerOf512);

    do{
      mpz_nextprime(p, p);
      mpz_mod(mod, p, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    do{
      mpz_nextprime(q, q);
      mpz_mod(mod, q, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    mpz_mul(N, p, q);
  } while (mpz_sizeinbase(N, 2) < MINIMUM_MODULUS_LENGTH);

  //******************************************************//
  //                  !!!!!WARNING!!!!!                   //
  // NOT SURE IF THIS IS LEGAL BUT IT DOESN'T COMPLAIN!!  //
  //******************************************************//
  mpz_t p1, q1;
  mpz_init_set(p1, p);
  mpz_init_set(q1, q);
  mpz_sub_ui(p1, p1, 1);
  mpz_sub_ui(q1, q1, 1);
  mpz_mul(L, p1, q1);
  mpz_clear(p1);
  mpz_clear(q1);

  mpz_invert(d, e, L);

  //******************************************************//
  //   The remaining code is just for testing purposes    //
  //******************************************************//
  std::cout << "p: " << std::hex << p << std::endl;
  std::cout << std::dec << "Number is this big: "
    << mpz_sizeinbase(p, 2) << std::endl;

  std::cout << "q: " << std::hex << q << std::endl;
  std::cout << std::dec << "Number is this big: "
    << mpz_sizeinbase(q, 2) << std::endl;

  std::cout << "N: " << std::hex << N << std::endl;
  std::cout << std::dec << "Number is this big: "
    << mpz_sizeinbase(N, 2) << std::endl;

  std::cout << "e: " << std::hex << e << std::endl;

  std::cout << "d: " << std::hex << d << std::endl;

  modulus = KeyElement(N);
  publicExponent = KeyElement(e);
  privateExponent = KeyElement(d);
}

void RsaCryptosystem::encrypt() {
  padText(paddedPlainText, plainText);
  //std::cout << "Daniel got this!\n";
  //paddedCipherText = paddedPlainText;
    // replace the line above by RSA encyption
    
  mpz_powm(paddedCipherText, paddedPlainText, e, N);
  unpadText(cipherText, paddedCipherText);
}

void RsaCryptosystem::decrypt() {
  padText(paddedCipherText, cipherText);
  //paddedPlainText = paddedCipherText;
    // replace the line above by RSA decryption
    
  mpz_powm(paddedPlainText, paddedCipherText, d, N);
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
