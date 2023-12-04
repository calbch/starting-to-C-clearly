#include <stdio.h>

/* Exercise 1-8. */
int main() {

  int c, blanks, tabs, newLines;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++newLines;
    } else if (c == '\t') {
      ++tabs;
    } else if (c == ' ') {
      ++blanks;
    }
  }

  printf("%d Blanks\t%d Tabs\t%d Newlines\n", blanks, tabs, newLines);
  return 0;
}
