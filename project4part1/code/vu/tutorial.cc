#include "tutorial.h"

////////////////////////////////////////////////////////////

void testTutorial() {
  cout << "Testing tutorial.\n";
  testTypes();
}

void testTypes() {
  cout << "Testing types.\n";
  string s("1000000000000000000000000000000000000000000");

  // long long ll = stoll(s);
    // terminate called after throwing
    // an instance of 'std::out_of_range'

  mpz_class z(s);
  cout << "Big int: " << z << ".\n";
}
