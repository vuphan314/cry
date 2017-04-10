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

  mpz_t n, e, d, p, q, l, mod, TWO_EXP_PRIME_LENGTH;
  mpz_inits(n, e, d, p, q, l, mod, TWO_EXP_PRIME_LENGTH,
    NULL);

  mpz_set_ui(e, DEFAULT_PUBLIC_EXPONENT);

  mpz_set_ui(TWO_EXP_PRIME_LENGTH, 1);
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

  setTotient(l, p, q);

  mpz_invert(d, e, l);

  //******************************************************//
  //   The remaining code is just for testing purposes    //
  //******************************************************//
  if (verbosity) {
    std::cout << "p: " << std::hex << p << std::endl;
    std::cout << std::dec << "number is this big: "
      << mpz_sizeinbase(p, 2) << std::endl;

    std::cout << "q: " << std::hex << q << std::endl;
    std::cout << std::dec << "number is this big: "
      << mpz_sizeinbase(q, 2) << std::endl;

    std::cout << "n: " << std::hex << n << std::endl;
    std::cout << std::dec << "number is this big: "
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
  Time startTime = getTime();

  mpz_t n, e, d, p, q, l;
  mpz_inits(n, e, d, p, q, l, NULL);

  mpf_t pFloat, nFloat, rootN, currentRatio;
  mpf_inits(pFloat, nFloat, rootN, currentRatio, NULL);

  mpz_set(n, modulus.get_mpz_t());

  mpf_set_z(nFloat, n);
  mpf_sqrt(rootN, nFloat);
  mpz_set_ui(p, 1);
  SizeT cc = 0; // currentCount
  std::cout << "\tprivate method " <<
    "RsaCryptosystem::cryptanalyze started\n";
  do {
    mpz_nextprime(p, p);
    mpf_set_z(pFloat, p);
    mpf_div(currentRatio, pFloat, rootN);
    cc++;
    if (!(cc & COUT_PERIOD)) {
      double currentPercentage = 100 *
        mpf_get_d(currentRatio);
      Duration remainingDuration = getRemainingDuration(
        startTime, currentPercentage);
      cout << COUT_WIDTH << COUT_PRECISION << std::fixed <<
        currentPercentage << "%" <<
        COUT_WIDTH << remainingDuration << "h left\n";
    }
  } while (!(mpz_divisible_p(n, p)));
  Duration totalDuration = getDuration(startTime);
  std::cout << "\tprivate method " <<
    "RsaCryptosystem::cryptanalyze ended in " <<
    totalDuration << "s\n";

  mpz_divexact(q, n, p);

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
