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
  unsigned int MINIMUM_MODULUS_LENGTH = 1024;
  unsigned int PRIME_LENGTH = (MINIMUM_MODULUS_LENGTH/2)-1;
  unsigned int seed = 672087;

  mpz_t prime1;
  mpz_t prime2;
  mpz_t N;
  mpz_t L;
  mpz_t d;
  mpz_t e;
  mpz_t twoToThePowerOf512;
  mpz_t mod;
  mpz_t testValue;

  mpz_init(prime1);
  mpz_init(prime2);
  mpz_init(N);
  mpz_init(L);
  mpz_init(d);
  mpz_init(e);
  mpz_init(mod);
  mpz_init(twoToThePowerOf512);
  mpz_init(testValue);

  mpz_add_ui(e, e, 65537);

  mpz_add_ui(twoToThePowerOf512, twoToThePowerOf512, 1);
  mpz_mul_2exp(twoToThePowerOf512, twoToThePowerOf512, PRIME_LENGTH);

  //******************************************************//
  //  THIS MAKES THE ALGORITHM CRYPTOGRAHICALLY INSECURE  //
  /**/           gmp_randstate_t state;                   //
  /**/           gmp_randinit_default(state);             //
  /**/           gmp_randseed_ui(state, seed);            //
  //******************************************************//

  do{
    mpz_urandomb(prime1, state, PRIME_LENGTH);
    mpz_add(prime1, prime1, twoToThePowerOf512);

    mpz_urandomb(prime2, state, PRIME_LENGTH);
    mpz_add(prime2, prime2, twoToThePowerOf512);

    do{
      mpz_nextprime(prime1, prime1);
      mpz_mod(mod, prime1, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    do{
      mpz_nextprime(prime2, prime2);
      mpz_mod(mod, prime2, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    mpz_mul(N, prime1, prime2);
  } while (mpz_sizeinbase(N, 2) < MINIMUM_MODULUS_LENGTH);


  //******************************************************//
  //                  !!!!!WARNING!!!!!                   //
  // NOT SURE IF THIS IS LEGAL BUT IT DOESN't COMPLAIN!!  //
  //******************************************************//
  mpz_mul(L, prime1-1, prime2-1);

  mpz_invert(d, e, L);

  std::cout << "p: " << prime1 << std::endl;
  std::cout << "Number is this big: " << mpz_sizeinbase(prime1, 2) << std::endl;

  std::cout << "q: " << prime2 << std::endl;
  std::cout << "Number is this big: " << mpz_sizeinbase(prime2, 2) << std::endl;

  std::cout << "N: " << N << std::endl;
  std::cout << "Number is this big: " << mpz_sizeinbase(N, 2) << std::endl;

  std::cout << "e: " << e << std::endl;

  std::cout << "d: " << d << std::endl;

  // pseudocode
  // generate two random 512 bit numbers (as in, the number
  // requires at least 512 bits to store
  // The most significant bit is not random, so I add that
  // manually
  // NOTE: 512 = MINIMUM_MODULUS_LENGTH/2)
  // use mpz_urandomb for this
  // get the next prime number using mpz_nextprime
  // keep generating until (number%e) != 1
  // once primes p and q have been generated,
  // N = pq
  // L=(p-1)(q-1)
  // d = inverse modulus of (e, L)
  // de = 1 (mod (p-1) (q-1))
  // In other words, d=(1/e)%((p-1)(q-1))

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
