#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define SIZE 42

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int alt_binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  if (v[low] == x) {
    return low;
  }
  return -1;
}

int main() {
  int x = 84;
  int v[SIZE] = {3,   7,   12,  15,  18,  23,  29,  31,  36,  40,  44,
                 49,  52,  57,  61,  66,  70,  75,  79,  84,  88,  93,
                 97,  102, 106, 111, 115, 120, 124, 129, 133, 138, 142,
                 147, 151, 156, 160, 165, 169, 174, 178, 183};

  int b, ab;
  double book, exercise;

  clock_t begin = clock();
  b = binsearch(x, v, SIZE);
  clock_t end = clock();
  book = (double)(end - begin) / CLOCKS_PER_SEC;

  begin = clock();
  ab = alt_binsearch(x, v, SIZE);
  end = clock();
  exercise = (double)(end - begin) / CLOCKS_PER_SEC;

  assert(b == ab);
  printf("%f vs. %f: the alternative version seems to be %f seconds faster.",
         book, exercise, fabs(book - exercise));

  return 0;
}
