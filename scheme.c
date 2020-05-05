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
    printf("%d\n", scm_to_int(t));
  };
  return 0;
}
