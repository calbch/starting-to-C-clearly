
#include <limits.h>
#include <stdio.h>

int main() {
  // largest possible number
  long long unsigned int max;

  /* char */
  printf("char\n");
  printf("\tsigned\n");
  printf("\t\t%d to %d\n", CHAR_MIN, CHAR_MAX);

  signed char c;
  for (c = max = 1; c > 0; c *= 2) {
    max *= 2;
  }
  printf("\t\t%d to %llu\n", c, max - 1);

  printf("\tunsigned\n");
  printf("\t\t%d to %d\n", 0, UCHAR_MAX);

  unsigned char uc;
  for (uc = max = 1; uc > 0; uc *= 2) {
    max *= 2;
  }
  printf("\t\t%d to %llu\n", uc, max - 1);

  /* short */
  printf("\nshort\n");

  printf("\tsigned\n");
  printf("\t\t%d to %d\n", SHRT_MIN, SHRT_MAX);

  signed short s;
  for (s = max = 1; s > 0; s *= 2) {
    max *= 2;
  }
  printf("\t\t%d to %llu\n", s, max - 2);

  /* and so on... */

  printf("\tunsigned\n");
  printf("\t\t%d to %d\n", 0, USHRT_MAX);

  /* int */
  printf("\nint\n");

  printf("\tsigned\n");
  printf("\t\t%d to %d\n", INT_MIN, INT_MAX);

  printf("\tunsigned\n");
  printf("\t\t%d to %d\n", 0, UINT_MAX);

  /* long */
  printf("\nlong\n");

  printf("\tsigned\n");
  printf("\t\t%ld - %ld\n", LONG_MIN, LONG_MAX);

  printf("\tunsigned\n");
  printf("\t\t%d - %lu\n", 0, ULONG_MAX);

  // TODO: determine floating point sizes

  return 0;
}
