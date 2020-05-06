#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
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
  int n_buffer = 1;
  char *buffer = malloc(n_buffer);
  char *p = buffer;
  int n = 0;
  while (true) {
    int c = getc(stream);
    if (n > 0 && (isspace(c) || c == EOF || c == '(' || c == ')')) {
      ungetc(c, stream);
      SCM result = scm_from_locale_symboln(buffer, n);
      free(buffer);
      return result;
    } else if (c == '(') {
      free(buffer);
      return SCM_OPEN_PAREN;
    } else if (c == ')') {
      free(buffer);
      return SCM_CLOSE_PAREN;
    } else {
      if (n >= n_buffer) {
        n_buffer *= 2;
        char *buffer_new = malloc(n_buffer);
        memcpy(buffer_new, buffer, n);
        free(buffer);
        buffer = buffer_new;
        p = buffer + n;
      };
      *p++ = c;
      n++;
    };
  };
  return result;
}
