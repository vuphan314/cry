#include "tutorial.h"

////////////////////////////////////////////////////////////

void testTutorial() {
  cout << "\ntesting tutorial\n";
  testTypes();
  testOperators();
}

void testTypes() {
  cout << "\ntesting types\n";
  string s("1000000000000000000000000000000000000000000");

  // long long ll = stoll(s);
    // terminate called after throwing
    // an instance of 'std::out_of_range'

  mpz_class z(s);
  cout << "big int: " << z << "\n";
}

void testOperators() {
  cout << "\ntesting operators\n";
  mpz_class a("2748932749872983478927398478923784723988"),
    d(7831672283),
    q = a / d,
    r = a % d;
  cout << "dividend: " << a <<
    "\ndivisor: " << d <<
    "\nquotient: " << q <<
    "\nremainder: " << r << "\n";
}
