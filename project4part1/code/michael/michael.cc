#include <iostream>

#include <gmp.h>
#include <gmpxx.h>

int main(int argc, char const *argv[]) {
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

  mpz_mul_2exp(twoToThePowerOf512, twoToThePowerOf512, PRIME_LENGTH);

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
  mpz_mul(L, p-1, q-1);

  mpz_invert(d, e, L);

  //******************************************************//
  //   The remaining code is just for testing purposes    //
  //******************************************************//
  std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
  std::cout << "p: " << std::hex << p << std::endl;
  std::cout << std::dec << "Number is this big: " << mpz_sizeinbase(p, 2) << std::endl << std::endl;

  std::cout << "q: " << std::hex << q << std::endl;
  std::cout << std::dec << "Number is this big: " << mpz_sizeinbase(q, 2) << std::endl << std::endl;

  std::cout << "N: " << std::hex << N << std::endl;
  std::cout << std::dec << "Number is this big: " << mpz_sizeinbase(N, 2) << std::endl << std::endl;

  std::cout << "e: " << std::hex << e << std::endl << std::endl;

  std::cout << "d: " << std::hex << d << std::endl << std::endl << std::endl;
}
