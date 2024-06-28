#include "shared.h"
#include <limits.h>

long long unsigned get_int_len() {
  long long unsigned c = 0;

  for (unsigned i = 1; i > 0; i <<= 1) {
    c++;
  }

  return c;
}

int rightrot(unsigned x, unsigned n) {
  int int_len = get_int_len();

  unsigned right = ~(~0 << n) & x;
  x >>= n;
  right <<= (int_len - n);

  return x | right;
}

int main() {

  int x = 22;
  int n = 3;

  printBits(x);
  printBits(rightrot(x, n));

  return 0;
}
