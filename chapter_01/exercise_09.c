#include <stdio.h>

/* Exercise 1-9. */
int main() {
  int c, isPrevBlank;

  isPrevBlank = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && isPrevBlank == 1) {
      continue;
    }
    if (c == ' ') {
      isPrevBlank = 1;
    } else {
      isPrevBlank = 0;
    }

    putchar(c);
  }

  return 0;
}
