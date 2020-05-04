#include "munit.h"
#include "type.h"


static MunitResult test_integer(const MunitParameter params[], void *data) {
  munit_assert_int(ft_to_int(ft_from_int(123)), ==, 123);
  munit_assert_true(is_number(ft_from_int(123)));
  munit_assert_false(is_number(FALSE));
  return MUNIT_OK;
}

MunitTest test_type[] = {
  {"/integer", test_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL      , NULL        , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};
