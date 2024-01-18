#include "tests.h"

START_TEST(s21_to_upper_test0) {
  char *result = s21_to_upper("Hello, world!");
  ck_assert_str_eq("HELLO, WORLD!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test1) {
  char *result = s21_to_upper("hel543534lO,535345 5w43543545OrLD!");
  ck_assert_str_eq("HEL543534LO,535345 5W43543545ORLD!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_to_upper_test_null) {
  ck_assert_pstr_eq(NULL, s21_to_upper(NULL));
}
END_TEST

Suite *s21_to_upper_test_suite() {
  Suite *s = suite_create("s21_to_upper");
  TCase *tc_case = tcase_create("s21_to_upper_case");
  tcase_add_test(tc_case, s21_to_upper_test0);
  tcase_add_test(tc_case, s21_to_upper_test1);
  tcase_add_test(tc_case, s21_to_upper_test_null);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_to_upper_tests() {
  Suite *s = s21_to_upper_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
