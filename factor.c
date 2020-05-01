#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "lexer.h"


int stack[1024];
int stack_index = 0;

char *symbols[1024];
void (*func[1024])(void);
int func_index = 0;

void dot(void) {
  stack_index--;
  printf("%d\n", stack[stack_index]);
};

int main(int argc, char *argv) {
  symbols[func_index] = "."; func[func_index++] = &dot;
  while (true) {
    int token = yylex();
    if (!token) break;
    switch (token) {
    case NUMBER:
      stack[stack_index++] = yylval.number;
      break;
    case SYMBOL:
      for (int i=0; i<func_index; i++) {
        if (!strcmp(yylval.symbol, symbols[i])) {
          func[i]();
          break;
        };
      };
      break;
    };
  };
  return 0;
}
