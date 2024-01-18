#include "tests.h"

START_TEST(s21_trim_test0) {
  char *result = s21_trim("*** Much Ado About Nothing ***", "* ");
  ck_assert_str_eq("Much Ado About Nothing", result);

  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test1) {
  char *result = s21_trim("*** Much Ado About Nothing \\\\\\", "* \\\\\\");
  ck_assert_str_eq("Much Ado About Nothing", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test2) {
  char *result = s21_trim("123abc456xyz789", "123456789");
  ck_assert_str_eq("abc456xyz", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_trim_test_null) {
  ck_assert_pstr_eq(NULL, s21_trim(NULL, NULL));
}
END_TEST

Suite *s21_trim_test_suite() {
  Suite *s = suite_create("s21_trim");
  TCase *tc_case = tcase_create("s21_trim_case");
  tcase_add_test(tc_case, s21_trim_test0);
  tcase_add_test(tc_case, s21_trim_test1);
  tcase_add_test(tc_case, s21_trim_test2);
  tcase_add_test(tc_case, s21_trim_test_null);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_trim_tests() {
  Suite *s = s21_trim_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
