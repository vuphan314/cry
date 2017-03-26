#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = RSA;
  Tester *Tester =
    getTester(cryptosystemName);
  Bool success = Tester->testAll();
  if (success) {
    std::cout << "All tests passed.\n";
  } else {
    std::cout << "Some test failed.\n";
  }
}
