#pragma once


typedef int FT;

enum token_type_t {
  FALSE = 0,
  UNDEFINED = 2,
  TRUE = 20
};

FT token(FILE *stream) {
  FT result = UNDEFINED;
  return result;
}
