#include "tests.h"

START_TEST(s21_to_lower_test0) {
  char *result = s21_to_lower("HeLlO, WoRlD!");
  ck_assert_str_eq("hello, world!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test1) {
  char *result = s21_to_lower("HEL543534LO,535345 5W43543545OrLD!");
  ck_assert_str_eq("hel543534lo,535345 5w43543545orld!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_lower_test_null) {
  ck_assert_pstr_eq(NULL, s21_to_lower(NULL));
}
END_TEST

Suite *s21_to_lower_test_suite() {
  Suite *s = suite_create("s21_to_lower");
  TCase *tc_case = tcase_create("s21_to_lower_case");
  tcase_add_test(tc_case, s21_to_lower_test0);
  tcase_add_test(tc_case, s21_to_lower_test1);
  tcase_add_test(tc_case, s21_to_lower_test_null);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_to_lower_tests() {
  Suite *s = s21_to_lower_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
