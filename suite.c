#include "munit.h"


extern MunitTest test_type[];
extern MunitTest test_tokenizer[];

static MunitSuite test_factor[] = {
  {"/type"     , test_type     , NULL, 1, MUNIT_SUITE_OPTION_NONE},
  {"/tokenizer", test_tokenizer, NULL, 1, MUNIT_SUITE_OPTION_NONE},
  {NULL        , NULL          , NULL, 0, MUNIT_SUITE_OPTION_NONE}
};

static const MunitSuite test_suite[] = {
  {"", NULL, test_factor, 1, MUNIT_SUITE_OPTION_NONE}
};

int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
  int result = munit_suite_main(&test_suite[0], (void *)NULL, argc, argv);
  return result;
}
