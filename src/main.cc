#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = RSA;
  CryptosystemTester *cryptosystemTester =
    getCryptosystemTester(cryptosystemName);
  Bool success = cryptosystemTester->testAll();
  if (success) {
    std::cout << "All tests passed.\n";
  } else {
    std::cout << "Some test failed.\n";
  }
}
