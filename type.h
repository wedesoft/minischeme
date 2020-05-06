#pragma once
#include <stdbool.h>
#include <string.h>


typedef long int SCM;

enum token_type_t {
  SCM_BOOL_F = 0,
  UNDEFINED = 2,
  SCM_BOOL_T = 20
};

static inline int scm_is_false(SCM b) {
  return b == SCM_BOOL_F;
}

static inline int scm_is_true(SCM b) {
  return b != SCM_BOOL_F;
}

static inline int scm_is_bool(SCM b) {
  return b == SCM_BOOL_F || b == SCM_BOOL_T;
}

static inline SCM scm_from_int(int c) {
  return (c << 1) + 1;
}

static inline int scm_to_int(SCM c) {
  return (c - 1) >> 1;
}

static inline bool is_number(SCM c) {
  return c & 1;
}

static inline SCM scm_from_locale_symbol(const char *s) {
  return (SCM)strdup(s); // TODO: register with garbage collector! Check alignment!
}

static inline SCM scm_from_locale_symboln(const char *s, int n) {
  return (SCM)strndup(s, n); // TODO: register with garbage collector! Check alignment!
}

static inline const char *scm_to_locale_symbol(SCM s) {
  return (const char *)s;
}
