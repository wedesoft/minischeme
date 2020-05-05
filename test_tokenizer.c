#include <stdio.h>
#include "munit.h"
#include "tokenizer.h"


static MunitResult test_empty_stream(const MunitParameter params[], void *data) {
  FILE *f = fmemopen("", 0, "r");
  munit_assert_int(token(f), ==, UNDEFINED);
  fclose(f);
  return MUNIT_OK;
}

static MunitResult test_number(const MunitParameter params[], void *data) {
  FILE *f = fmemopen(" 123", 4, "r");
  SCM t = token(f);
  munit_assert_true(is_number(t));
  munit_assert_int(scm_to_int(t), ==, 123);
  fclose(f);
  return MUNIT_OK;
}

MunitTest test_tokenizer[] = {
  {"/empty_stream", test_empty_stream, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {"/number"      , test_number      , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL           , NULL             , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};
