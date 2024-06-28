#include <assert.h>
#include <stdio.h>

int lower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else {
    return c;
  }
}

int cond_lower(int c) { return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c; }

int main() {
  char c = 'Z';

  assert(lower(c) == cond_lower(c));
  printf("%c - %c - %c", c, lower(c), cond_lower(c));

  return 0;
}
