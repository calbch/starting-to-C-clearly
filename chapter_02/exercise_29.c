/* Why does x &= (x - 1) delete the least significant 1-bit
 *
 * Subtracting 1 flips all bits starting from the rightmost 1-bit to the LSB.
 * Applying a bitwise and to x and (x - 1) clears the rightmost 1-bit and keeps
 * all other bits unchanged.
 *
 */

#include <assert.h>
#include <stdio.h>

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1) {
    if (x & 01) {
      b++;
    }
  }
  return b;
}

int better_bitcount(unsigned x) {
  int b;

  // clear rightmost 1-bit till x is 0
  for (b = 0; x != 0; x &= (x - 1)) {
    // you can omit the LSB check necessary above
    b++;
  }

  return b;
}

int main() {

  int x = 42;

  int c, bc;
  c = bitcount(x);
  bc = better_bitcount(x);

  printf("Bitcount of %d: %d\nBetter Bitcount: %d", x, c, bc);
  assert(c == bc);

  return 0;
}
