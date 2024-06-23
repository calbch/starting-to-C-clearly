#include <stdio.h>

// return 1 if there is a match, 0 otherwise
int match(char c, char s[]) {
  int match = 0;

  for (int i = 0; s[i] != '\0'; i++) {
    if (c == s[i]) {
      match = 1;
    }
  }

  return match;
}

// Print integer bits to stdout
void printBits(int num) {
  int size = sizeof(int) * 8;          // Number of bits in an int
  unsigned int mask = 1 << (size - 1); // Start with the leftmost bit

  for (int i = 0; i < size; i++) {
    // Print '1' if the bit is set, '0' otherwise
    putchar((num & mask) ? '1' : '0');

    // Move to the next bit
    num <<= 1;

    // Add a space every 8 bits for readability
    if ((i + 1) % 8 == 0 && i < size - 1) {
      putchar(' ');
    }
  }
  putchar('\n');
}
