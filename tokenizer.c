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
  char *buffer = malloc(1);
  char *p = buffer;
  int n = 0;
  while (true) {
    int c = getc(stream);
    if (isspace(c) || c == EOF) {
      ungetc(c, stream);
      SCM result = scm_from_locale_symboln(buffer, n);
      free(buffer);
      return result;
    } else {
      if (n >= n_buffer) {
        n_buffer *= 2;
        char *buffer_new = malloc(n_buffer);
        memcpy(buffer_new, buffer, n);
        buffer = buffer_new;
        p = buffer + n;
      };
      *p++ = c;
      n++;
    };
  };
  return result;
}
