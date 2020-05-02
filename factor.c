#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


enum token_type_t {
  FALSE = 0,
  UNDEFINED = 2,
  TRUE = 20
};

typedef int FT;

FT ft_from_int(int c) {
  return (c << 1) + 1;
}

int ft_to_int(FT c) {
  return (c - 1) >> 1;
}

bool is_number(FT c) {
  return c & 1;
}

FT token(void) {
  int result = UNDEFINED;
  while (true) {
    int c = getchar();
    if (c == EOF)
      return result;
    if (!isspace(c)) {
      ungetc(c, stdin);
      break;
    };
  };
  int count = 0;
  int buffer_size = 1;
  char *buffer = malloc(buffer_size);
  char *p = buffer;
  while (true) {
    int c = getchar();
    if (count >= buffer_size) {
      buffer_size *= 2;
      char *buffer_new = malloc(buffer_size);
      memcpy(buffer_new, buffer, count);
      free(buffer);
      buffer = buffer_new;
      p = buffer + count;
    };
    *p++ = c;
    count++;
    if (isdigit(c) && (result == UNDEFINED || is_number(result))) {
      if (result == UNDEFINED)
        result = ft_from_int(0);
      result = ft_from_int(ft_to_int(result) * 10 + c - '0');
    } else if (isspace(c) || c == EOF) {
      ungetc(c, stdin);
      free(buffer);
      return result;
    };
  };
}

int main(void) {
  while (true) {
    FT t = token();
    if (t == UNDEFINED) break;
    printf("%d\n", ft_to_int(t));
  };
  return 0;
}
