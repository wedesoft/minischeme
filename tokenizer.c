#include <ctype.h>
#include <stdbool.h>
#include "tokenizer.h"


SCM token(FILE *stream) {
  SCM result = UNDEFINED;
  while (true) {
    int c = getc(stream);
    if (c == EOF)
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
        result = scm_from_int(0);
      result = scm_from_int(scm_to_int(result) * 10 + (c - '0'));
    } else if (isspace(c) || c == EOF) {
      ungetc(c, stream);
      return result;
    };
  };
  return result;
}
