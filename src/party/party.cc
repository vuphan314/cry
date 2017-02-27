#include "party.h"

////////////////////////////////////////////////////////////

Party::Party(CryptosystemName cryptosystemName) {
  switch (cryptosystemName) {
    case RSA: cryptosystem = RsaCryptosystem();
  }
}
