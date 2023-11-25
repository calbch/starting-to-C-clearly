#include <stdio.h>

int main() {
  int c, nl, nw, nc, isSeq;

  nl = nw = nc = isSeq = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++nl;
      isSeq = 0;
    } else if (c == ' ' || c == '\t') {
      isSeq = 0;
    } else {
      ++nc;
      if (!isSeq) {
        ++nw;
        isSeq = 1;
      }
    }
  }

  printf("%d Line - %d Words - %d Characters\n", nl, nw, nc);

  return 0;
}

/* Exercise 1-11.: I would test the program with
 * - empty input
 * - only spaces, tabs and newlines
 * - one word, multiple words and multiple lines
 * - different combinations of spaces, tabs and newlines with words
 */
