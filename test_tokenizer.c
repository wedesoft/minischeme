#include <stdio.h>
#include "munit.h"
#include "tokenizer.h"


static MunitResult test_empty_stream(const MunitParameter params[], void *data) {
  FILE *f = fmemopen("", 1, "r");
  munit_assert_int(token(f), ==, UNDEFINED);
  fclose(f);
  return MUNIT_OK;
}

MunitTest test_tokenizer[] = {
  {"/empty_stream", test_empty_stream, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL           , NULL             , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};
