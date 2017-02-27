#include "party.h"

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case rsaName: cryptosystem = Rsa();
  }
}
