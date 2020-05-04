#include <ctype.h>
#include <stdbool.h>
#include "tokenizer.h"


FT token(FILE *stream) {
  FT result = UNDEFINED;
  while (true) {
    int c = getc(stream);
    if (c == 0 || c == EOF)
      return result;
    if (!isspace(c)) {
      ungetc(c, stream);
      break;
    };
  };
  while (true) {
    int c = getc(stream);
    if ((result == UNDEFINED || is_number(result) && isdigit(c))) {
      if (result == UNDEFINED)
        result = ft_from_int(0);
      result = ft_from_int(ft_to_int(result) * 10 + c - '0');
    } else if (isspace(c) || c == 0 || c == EOF) {
      ungetc(c, stream);
      return result;
    };
  };
  return result;
}
