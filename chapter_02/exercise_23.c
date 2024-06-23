/* write 'htoi': convert string of hexadecimals into integer value
 * (including leading 0x/0X
 */

#include <ctype.h>
#include <stdio.h>

#define MAXLEN 42

int htoi(char hex[]) {

  int i, hexd, r;

  i = hexd = r = 0;

  if (hex[0] == '0' && tolower(hex[1]) == 'x') {
    i = 2;
  }

  for (; hex[i] != '\0'; i++) {
    // early return on invalid letter
    if (!isdigit(hex[i]) && (tolower(hex[i]) < 'a' || 'f' < tolower(hex[i]))) {
      return -1;
    }
    if (isdigit(hex[i])) {
      hexd = hex[i] - '0';
    } else {
      hexd = (tolower(hex[i]) - 'a') + 10;
    }
    r = (r << 4) + hexd;
  }

  return r;
}

int main() {

  int res;
  char s[MAXLEN];

  printf("Enter hexadecimal number: ");
  scanf("%s", s);

  if ((res = htoi(s)) < 0) {
    printf("Invalid hexadecimal number");
    return -1;
  }

  printf("The resulting integer is: %d\n", res);

  return 0;
}
