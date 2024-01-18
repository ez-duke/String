#include "tests.h"

START_TEST(s21_strerror_test0) {
  for (int i = -119; i < 136; i++)
    ck_assert_str_eq(s21_strerror(i), strerror(i));
}
END_TEST

Suite *s21_strerror_test_suite() {
  Suite *s = suite_create("s21_strerror");
  TCase *tc_case = tcase_create("s21_strerror_case");
  tcase_add_test(tc_case, s21_strerror_test0);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strerror_tests() {
  Suite *s = s21_strerror_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
