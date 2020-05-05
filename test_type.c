#include "munit.h"
#include "type.h"


static MunitResult test_integer(const MunitParameter params[], void *data) {
  munit_assert_int(scm_to_int(scm_from_int(123)), ==, 123);
  munit_assert_true(is_number(scm_from_int(123)));
  munit_assert_false(is_number(SCM_BOOL_F));
  return MUNIT_OK;
}

static MunitResult test_boolean(const MunitParameter params[], void *data) {
  munit_assert_true(scm_is_false(SCM_BOOL_F));
  munit_assert_false(scm_is_false(SCM_BOOL_T));
  munit_assert_true(scm_is_true(SCM_BOOL_T));
  munit_assert_false(scm_is_true(SCM_BOOL_F));
  munit_assert_true(scm_is_bool(SCM_BOOL_F));
  munit_assert_true(scm_is_bool(SCM_BOOL_T));
  munit_assert_false(scm_is_bool(scm_from_int(123)));
  return MUNIT_OK;
}

static MunitResult test_string(const MunitParameter params[], void *data) {
  munit_assert_string_equal(scm_to_string(scm_from_string("test")), "test");
  return MUNIT_OK;
}

MunitTest test_type[] = {
  {"/integer", test_integer, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {"/boolean", test_boolean, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {"/string" , test_string , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
  {NULL      , NULL        , NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};
