#include "shared.h"
#include <stdio.h>

int invert(int x, int p, int n) {
  printBits(x);
  int by = (p + 1) - n;

  int mask = ~(~(~0 << n) << by);
  printBits(mask);

  int inverted_x_bits = ~(x & ~mask) & ~mask;
  printBits(inverted_x_bits);

  int masked_x = x & mask;
  printBits(masked_x);

  return x | inverted_x_bits;
}

int main() {
  int x = 22;
  int p = 3;
  int n = 2;

  int inverted = invert(x, p, n);

  printf("\n\n");
  printBits(x);
  printBits(inverted);

  return 0;
}
