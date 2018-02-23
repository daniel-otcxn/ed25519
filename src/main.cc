#include "ed25519.h"
#include <iostream>

int main(void) {
  unsigned char seed[32] = { 0 };

  unsigned char pk[32] = { 0 },
                pv[64] = { 0 };

  char table[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b' ,'c' ,'d' ,'e' , 'f' };

  ed25519_create_keypair(pk, pv, seed);

  for (int i = 0; i < 32; ++i) {
    std::cout << table[(pk[i] >> 4)] << table[(pk[i] & 0x0f)];
  }
  std::cout << "\n";

  for (int i = 0; i < 64; ++i) {
    std::cout << table[(pv[i] >> 4)] << table[(pv[i] & 0x0f)];
  }
  std::cout << "\n";

  unsigned char result[64];
  ed25519_sign(result, seed, 32, pk, pv);

  for (int i = 0; i < 64; ++i) {
    std::cout << table[(result[i] >> 4)] << table[(result[i] & 0x0f)];
  }
  std::cout << "\n";

  return 0;
}
