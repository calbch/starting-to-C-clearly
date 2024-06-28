#include <stdio.h>
#include <sys/syslimits.h>
#define MAX_LEN 100

int escape(char t[], char s[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++, j++) {
    if (i > (MAX_LEN / 2)) {
      return -1;
    }

    switch (t[i]) {
    case '\n':
      s[j] = '\\';
      s[++j] = 'n';
      break;
    case '\t':
      s[j] = '\\';
      s[++j] = 't';
      break;
    default:
      s[j] = t[i];
      break;
    }
  }
  s[j] = '\0';

  return 0;
}

int catch (char t[], char s[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++, j++) {
    if (i > (MAX_LEN / 2)) {
      return -1;
    }

    if (t[i] == '\\') {
      if (++i >= MAX_LEN) {
        return -1;
      }
      switch (t[i]) {
      case 'n':
        s[j] = '\n';
        break;
      case 't':
        s[j] = '\t';
        break;
      default:
        s[j] = '\\';
        break;
      }
    } else {
      s[j] = t[i];
    }
  }
  s[j] = '\0';

  return 0;
}

int main() {
  char input[MAX_LEN / 2] = "Hello\tWorld\nThis is a test";
  char output[MAX_LEN]; // Double size to accommodate escaped characters

  escape(input, output);

  printf("Input string: %s\n", input);
  printf("Escaped string: %s\n", output);

  catch (output, input);
  printf("Input string: %s\n", output);
  printf("Escaped string: %s\n", input);

  return 0;
}
