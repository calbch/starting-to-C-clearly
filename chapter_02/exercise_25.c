#include "shared.h"
#include <stdio.h>

int any(char first[], char second[]) {
  for (int i = 0; first[i] != '\0'; i++) {
    if (match(first[i], second)) {
      return i;
    }
  }

  return -1;
}

int main() {

  char first[MAXLEN];
  char second[MAXLEN];
  int res;

  printf("Enter the first string: ");
  scanf("%s", first);

  printf("Enter the second string: ");
  scanf("%s", second);

  if ((res = any(first, second)) < 0) {
    return -1;
  }

  printf("Result index: %d", res);
}
