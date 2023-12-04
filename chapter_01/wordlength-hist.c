#include <stdio.h>

#define MAX_WORD_LENGTH 6

/* Exercise 1-13. */
int main() {
  int c, wordLength, maxWordLength;
  int lBins[MAX_WORD_LENGTH];

  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    lBins[i] = 0;
  }

  maxWordLength = 0;
  wordLength = 1;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t' || c == '\b') {
      if (wordLength <= MAX_WORD_LENGTH) {
        ++lBins[wordLength - 1];
        if (lBins[wordLength] > maxWordLength) {
          maxWordLength = lBins[wordLength];
        }
      } else {
        printf("Word length larger than %d...\n", MAX_WORD_LENGTH);
      }
      wordLength = 0;
    } else {
      ++wordLength;
    }
  }

  // print histogram
  for (int row = maxWordLength; row >= 0; --row) {
    for (int col = 0; col < MAX_WORD_LENGTH; ++col) {
      if (row < lBins[col]) {
        printf("##");
      } else {
        printf("  ");
      }
      printf("  ");
    }
    printf("\n");
  }

  // print separator
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("----");
  }
  printf("\n");

  // print labels
  for (int i = 1; i <= MAX_WORD_LENGTH; ++i) {
    if (i < MAX_WORD_LENGTH) {
      printf("%2d  ", i);
    } else {
    }
    printf("%2d", i);
  }

  printf("\n\n Kontrolle:");
  for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
    printf("%d words with length %d\n", lBins[i], i);
  }

  return 0;
}
