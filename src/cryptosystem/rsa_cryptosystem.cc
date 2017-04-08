/*
http://stackoverflow.com/questions/9791761/using-gmp-for-cryptography-how-to-get-random-numbers
*/

////////////////////////////////////////////////////////////

#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////
// class RsaCryptosystem:

// private:

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

void RsaCryptosystem::generateKeys(
    SizeT modulusLength) {
  const SizeT PRIME_LENGTH = (modulusLength / 2) - 1;

  mpz_t p;
  mpz_t q;
  mpz_t n;
  mpz_t l;
  mpz_t d;
  mpz_t e;
  mpz_t mod;
  mpz_t TWO_EXP_PRIME_LENGTH;

  mpz_init(p);
  mpz_init(q);
  mpz_init(n);
  mpz_init(l);
  mpz_init(d);
  mpz_init_set_ui(e, DEFAULT_PUBLIC_EXPONENT);
  mpz_init(mod);
  mpz_init_set_ui(TWO_EXP_PRIME_LENGTH, 1);
  mpz_mul_2exp(TWO_EXP_PRIME_LENGTH, TWO_EXP_PRIME_LENGTH,
    PRIME_LENGTH);
    // TWO_EXP_PRIME_LENGTH is const afterward

  //******************************************************//
  // THIS MAKES THE ALGORITHM CRYPTOGRAPHICALLY INSECURE  //
  /**/           gmp_randstate_t state;                   //
  /**/           gmp_randinit_default(state);             //
  /**/           gmp_randseed_ui(state, DEFAULT_SEED);    //
  //******************************************************//

  do {
    mpz_urandomb(p, state, PRIME_LENGTH);
    mpz_add(p, p, TWO_EXP_PRIME_LENGTH);

    mpz_urandomb(q, state, PRIME_LENGTH);
    mpz_add(q, q, TWO_EXP_PRIME_LENGTH);

    do {
      mpz_nextprime(p, p);
      mpz_mod(mod, p, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    do {
      mpz_nextprime(q, q);
      mpz_mod(mod, q, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    mpz_mul(n, p, q);
  } while (mpz_sizeinbase(n, 2) < modulusLength);

  mpz_t p1, q1;
  mpz_init_set(p1, p);
  mpz_init_set(q1, q);
  mpz_sub_ui(p1, p1, 1);
  mpz_sub_ui(q1, q1, 1);

  mpz_mul(l, p1, q1);
  mpz_invert(d, e, l);

  //******************************************************//
  //   The remaining code is just for testing purposes    //
  //******************************************************//
  if (verbosity) {
    std::cout << "p: " << std::hex << p << std::endl;
    std::cout << std::dec << "Number is this big: "
      << mpz_sizeinbase(p, 2) << std::endl;

    std::cout << "q: " << std::hex << q << std::endl;
    std::cout << std::dec << "Number is this big: "
      << mpz_sizeinbase(q, 2) << std::endl;

    std::cout << "n: " << std::hex << n << std::endl;
    std::cout << std::dec << "Number is this big: "
      << mpz_sizeinbase(n, 2) << std::endl;

    std::cout << "e: " << std::hex << e << std::endl;

    std::cout << "d: " << std::hex << d << std::endl;
  }

  modulus = KeyElement(n);
  publicExponent = KeyElement(e);
  privateExponent = KeyElement(d);
}

void RsaCryptosystem::encrypt() {
  mpz_powm(paddedCipherText.get_mpz_t(),
    paddedPlainText.get_mpz_t(),
    publicExponent.get_mpz_t(),
    modulus.get_mpz_t());
}

void RsaCryptosystem::decrypt() {
  mpz_powm(paddedPlainText.get_mpz_t(),
    paddedCipherText.get_mpz_t(),
    privateExponent.get_mpz_t(),
    modulus.get_mpz_t());
}

void RsaCryptosystem::cryptanalyze() {
  mpz_t n, e, d, p, q, l;
  mpz_inits(n, e, d, p, q, l, NULL);

  mpz_set(n, modulus.get_mpz_t());

  mpz_set_ui(p, 2);
  do {
    mpz_nextprime(p, p);
  } while (!(mpz_divisible_p(n, p)));

  mpz_tdiv_q(q, n, p);

  setTotient(l, p, q);

  mpz_set(e, publicExponent.get_mpz_t());

  mpz_invert(d, e, l);

  mpz_powm(paddedPlainText.get_mpz_t(),
    paddedCipherText.get_mpz_t(), d, n);
}

// public:

// public overloaded methods:

void RsaCryptosystem::generateKeys(
    Key &publicKey, Key &privateKey, SizeT modulusLength) {
  generateKeys(modulusLength);
  publicKey = {modulus, publicExponent};
  privateKey = {modulus, privateExponent};
}

void RsaCryptosystem::generateKeys(
    Key &publicKey, Key &privateKey) {
  generateKeys(publicKey, privateKey,
    DEFAULT_MODULUS_LENGTH);
}

void RsaCryptosystem::encrypt(Text &cipherText,
    const Text &plainText, const Key &publicKey) {
  padText(paddedPlainText, plainText);
  setPublicKeyElements(publicKey);
  encrypt();
  unpadText(cipherText, paddedCipherText);
}

void RsaCryptosystem::decrypt(Text &plainText,
    const Text &cipherText, const Key &privateKey) {
  padText(paddedCipherText, cipherText);
  setPrivateKeyElements(privateKey);
  decrypt();
  unpadText(plainText, paddedPlainText);
}

void RsaCryptosystem::cryptanalyze(Text &plainText,
    const Text &cipherText, const Key &publicKey) {
  padText(paddedCipherText, cipherText);
  setPublicKeyElements(publicKey);
  cryptanalyze();
  unpadText(plainText, paddedPlainText);
}

////////////////////////////////////////////////////////////
// global functions:

void setTotient(mpz_t l, mpz_t p, mpz_t q) {
  mpz_t p1, q1;
  mpz_init_set(p1, p);
  mpz_init_set(q1, q);
  mpz_sub_ui(p1, p1, 1);
  mpz_sub_ui(q1, q1, 1);
  mpz_lcm(l, p1, q1); // yes: Carmichael totient
  // mpz_mul(l, p1, q1); // no: Euler totient
}
