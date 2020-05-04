#pragma once
#include <stdbool.h>


typedef int FT;

enum token_type_t {
  FALSE = 0,
  UNDEFINED = 2,
  TRUE = 20
};

static inline FT ft_from_int(int c) {
  return (c << 1) + 1;
}

static inline int ft_to_int(FT c) {
  return (c - 1) >> 1;
}

static inline bool is_number(FT c) {
  return c & 1;
}
