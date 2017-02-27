#include "party/party.h"

////////////////////////////////////////////////////////////

int main() {
  CryptosystemName cryptosystemName = rsaName;
  Party party(cryptosystemName);
  cout << cryptosystemName << "\n";
}
