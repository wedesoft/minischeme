#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "type.h"


int main(void) {
  while (true) {
    SCM t = token(stdin);
    if (t == UNDEFINED)
      break;
    if (is_number(t)) {
      printf("%d\n", scm_to_int(t));
    } else if (is_symbol(t)) {
      printf("%s\n", scm_to_locale_symbol(t));
    } else if (t == SCM_OPEN_PAREN) {
      printf("(\n");
    } else if (t == SCM_CLOSE_PAREN) {
      printf(")\n");
    };
  };
  return 0;
}
