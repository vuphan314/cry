#include "rsa_cryptosystem.h"

////////////////////////////////////////////////////////////
// class RsaCryptosystem:

// protected:

// protected helper methods:

SizeT RsaCryptosystem::getMaxTextLength() {
  return minModulusLength / CHAR_LENGTH;
}

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

void RsaCryptosystem::recoverPrivateKeyElements() {
  mpz_t n, e, d, p, q, l;
  mpz_inits(n, e, d, p, q, l, NULL);

  mpf_t pFloat, nFloat, rootN, currentRatio;
  mpf_inits(pFloat, nFloat, rootN, currentRatio, NULL);

  mpz_set(n, modulus.get_mpz_t());
  mpf_set_z(nFloat, n);
  mpf_sqrt(rootN, nFloat);

  Time startTime = getTime();
  std::cout << "\tmethod RsaCryptosystem::"
    "recoverPrivateKeyElements started\n";
  mpz_set_ui(p, 1);
  SizeT cc = 0; // current count
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
  std::cout << "\tmethod RsaCryptosystem::"
    "recoverPrivateKeyElements ended in " <<
    totalDuration << "s\n";

  mpz_divexact(q, n, p);

  setTotient(l, p, q);

  mpz_set(e, publicExponent.get_mpz_t());

  mpz_invert(d, e, l);

  privateExponent = PaddedText(d);
}

// protected overloaded methods:

void RsaCryptosystem::generateKeys() {
  SizeT minPrimeLength = (minModulusLength / 2) - 1;

  mpz_t n, e, d, p, q, l, mod, twoExpMinPrimeLength;
  mpz_inits(n, e, d, p, q, l, mod, twoExpMinPrimeLength,
    NULL);

  mpz_set_ui(e, DEFAULT_PUBLIC_EXPONENT);

  mpz_set_ui(twoExpMinPrimeLength, 1);
  mpz_mul_2exp(twoExpMinPrimeLength, twoExpMinPrimeLength,
    minPrimeLength);

  //******************************************************//
  // THIS MAKES THE ALGORITHM CRYPTOGRAPHICALLY INSECURE  //
  /**/           gmp_randstate_t randomState;             //
  /**/           seedRandomState(randomState);            //
  //******************************************************//

  do {
    mpz_urandomb(p, randomState, minPrimeLength);
    mpz_add(p, p, twoExpMinPrimeLength);

    mpz_urandomb(q, randomState, minPrimeLength);
    mpz_add(q, q, twoExpMinPrimeLength);

    do {
      mpz_nextprime(p, p);
      mpz_mod(mod, p, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    do {
      mpz_nextprime(q, q);
      mpz_mod(mod, q, e);
    } while (mpz_cmp_ui(mod, 1) == 0);

    mpz_mul(n, p, q);
  } while (mpz_sizeinbase(n, 2) < minModulusLength);

  setTotient(l, p, q);

  mpz_invert(d, e, l);

  //******************************************************//
  //   This code block is just for testing purposes       //
  //******************************************************//
  if (verbosity) {
    std::cout << "p: 0x" << std::hex << p << endl;
    std::cout << "bit-count: " << std::dec <<
      mpz_sizeinbase(p, 2) << endl;

    std::cout << "q: 0x" << std::hex << q << endl;
    std::cout << "bit-count: " << std::dec <<
      mpz_sizeinbase(q, 2) << endl;

    std::cout << "n: 0x" << std::hex << n << endl;
    std::cout << "bit-count: " << std::dec <<
      mpz_sizeinbase(n, 2) << endl;

    std::cout << "e: 0x" << std::hex << e << endl;

    std::cout << "d: 0x" << d << endl <<
      std::dec; // decimal for the next cout
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
  recoverPrivateKeyElements();
  decrypt();
}

// public:

RsaCryptosystem::RsaCryptosystem(SizeT minModulusLength) {
  this->minModulusLength = minModulusLength;
}

// public overloaded methods:

void RsaCryptosystem::generateKeys(Key &publicKey,
    Key &privateKey) {
  generateKeys();
  publicKey = {modulus, publicExponent};
  privateKey = {modulus, privateExponent};
  std::cout << "\tmin modulus length: " <<
    minModulusLength << "-bit\n\tmax text length: " <<
    getMaxTextLength() << "-char\n";
}

void RsaCryptosystem::encrypt(PaddedText &paddedCipherText,
    const Text &plainText, const Key &publicKey) {
  SizeT plainTextLength = plainText.size();
  std::cout << "\tplaintext length: " << plainTextLength <<
    "-char\n";
  long long excessiveLength = plainTextLength -
    getMaxTextLength();
  if (excessiveLength > 0) {
    std::cout << excessiveLength << " char(s) too long\n";
    throw exception();
  } else {
    setPublicKeyElements(publicKey);
    padText(paddedPlainText, plainText);
    encrypt();
    paddedCipherText = this->paddedCipherText;
  }
}

void RsaCryptosystem::decrypt(Text &plainText,
    const PaddedText &paddedCipherText,
    const Key &privateKey) {
  setPrivateKeyElements(privateKey);
  this->paddedCipherText = paddedCipherText;
  decrypt();
  unpadText(plainText, paddedPlainText);
}

void RsaCryptosystem::cryptanalyze(Text &plainText,
    const PaddedText &paddedCipherText,
    const Key &publicKey) {
  setPublicKeyElements(publicKey);
  this->paddedCipherText = paddedCipherText;
  cryptanalyze();
  unpadText(plainText, paddedPlainText);
}
