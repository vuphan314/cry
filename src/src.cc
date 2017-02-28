#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = RSA;
  Party party(cryptosystemName);
  cout << cryptosystemName << "\n";
}
