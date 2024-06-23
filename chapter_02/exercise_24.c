#include "shared.h"
#include <stdio.h>

int squeeze(char sp[], char ss[]) {
  int i, j;

  for (i = j = 0; sp[i] != '\0'; i++) {
    if (!match(sp[i], ss)) {
      sp[j++] = sp[i];
    }
  }
  sp[j] = '\0';

  return 0;
}

int main() {

  char first[MAXLEN];
  char second[MAXLEN];

  printf("Enter the first string: ");
  scanf("%s", first);

  printf("Enter the second string: ");
  scanf("%s", second);

  squeeze(first, second);

  printf("Result: %s", first);

  return 0;
}
