#include <stdio.h>

/* Exercise 1-5. */

#define UPPER 300 /* upper limit of table */
#define LOWER 0   /* lower limit of table */
#define STEP 20   /* step size */

int main() {
  for (int fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP) {
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
  }
}
