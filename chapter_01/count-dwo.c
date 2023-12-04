#include <stdio.h>

#define WS 10
#define OTHER 11

int main() {
  int c;
  int count[12];

  for (int i = 0; i < 12; i++) {
    count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++count[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++count[WS];
    } else {
      ++count[OTHER];
    }
  }
  printf("Occurences:\n-------------------\n");
  for (int i = 0; i < 12; ++i) {
    if (i == 10) {
      printf("Whitespace \t%d times\n", count[WS]);
    } else if (i == 11) {
      printf("Other \t%d times\n", count[OTHER]);
    } else {
      printf("Digit %d\t%d times\n", i, count[i]);
    }
  }

  return 0;
}
