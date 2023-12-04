#include "stdio.h"

/* Exercise 1-4. */
int main() {
  int fahrenheit;
  float celsius;

  int lower, upper, step;
  lower = -20;
  upper = 40;
  step = 5;

  celsius = lower;
  while (celsius <= upper) {
    fahrenheit = 9 * (celsius + 32) / 5;
    printf("%6.1f %6d\n", celsius, fahrenheit);
    celsius = celsius + step;
  }
}
