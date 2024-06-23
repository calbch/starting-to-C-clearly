#include "shared.h"
#include <stdio.h>

int setbits(unsigned x, int p, int n, int y) {
  int mask = ~(~0 << n);
  printf("mask\n");
  printBits(mask);

  int masked_y = y & mask;
  printf("apply mask to y\n");
  printBits(y);
  printBits(mask);
  printf("---------------\n");
  printBits(masked_y);

  int by = (p + 1) - n;
  printf("left shift mask by %d\n", by);
  mask <<= by;
  printBits(mask);

  printf("invert\n");
  mask = ~mask;
  printBits(mask);

  int masked_x = x & mask;
  printf("apply mask to x\n");
  printBits(x);
  printBits(mask);
  printf("---------------\n");
  printBits(masked_x);

  int shifted_y = masked_y << by;
  printf("shift masked y by %d\n", by);
  printBits(shifted_y);

  int result = masked_x | shifted_y;
  printBits(result);

  return result;
}

int main(void) {
  unsigned x = 22;
  unsigned y = 23;
  int p = 2; /* starting position of bits */
  int n = 2; /* number of bits to set */

  printf("%d\n", setbits(x, p, n, y));

  return 0;
}
