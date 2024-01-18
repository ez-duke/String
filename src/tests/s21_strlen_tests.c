#include "tests.h"

START_TEST(s21_strlen_test0) {
  ck_assert_uint_eq(s21_strlen("Hello, world!"), strlen("Hello, world!"));
}
END_TEST

START_TEST(s21_strlen_test1) {
  ck_assert_uint_eq(s21_strlen("djfhi3u2894euifjkadnflkj4iuyr98hfjkhgil"),
                    strlen("djfhi3u2894euifjkadnflkj4iuyr98hfjkhgil"));
}
END_TEST

Suite *s21_strlen_test_suite() {
  Suite *s = suite_create("s21_strlen");
  TCase *tc_case = tcase_create("s21_strlen_case");
  tcase_add_test(tc_case, s21_strlen_test0);
  tcase_add_test(tc_case, s21_strlen_test1);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strlen_tests() {
  Suite *s = s21_strlen_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
