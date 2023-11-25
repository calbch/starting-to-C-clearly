#include <stdio.h>

int main() {
  int c, newLine;

  newLine = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      ++newLine;
    }
  }

  printf("%d\n", newLine);
  return 0;
}
