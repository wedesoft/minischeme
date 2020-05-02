#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int ft_from_int(int c) {
  return (c << 1) + 1;
}

int ft_to_int(int c) {
  return (c - 1) >> 1;
}

int token(void) {
  while (true) {
    int c = getchar();
    if (!isspace(c)) {
      ungetc(c, stdin);
      break;
    };
  };
  int number = 0;
  while (true) {
    int c = getchar();
    if (isdigit(c)) {
      number = number * 10;
      number += c - '0';
    } else if (isspace(c)) {
      ungetc(c, stdin);
      return ft_from_int(number);
    };
  };
}

int main(void) {
  while (true) {
    int t = token();
    printf("%d\n", ft_to_int(t));
  };
  return 0;
}
