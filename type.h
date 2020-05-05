#pragma once
#include <stdbool.h>


typedef int SCM;

enum token_type_t {
  FALSE = 0,
  UNDEFINED = 2,
  TRUE = 20
};

static inline SCM scm_from_int(int c) {
  return (c << 1) + 1;
}

static inline int scm_to_int(SCM c) {
  return (c - 1) >> 1;
}

static inline bool is_number(SCM c) {
  return c & 1;
}
