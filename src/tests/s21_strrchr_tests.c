#include "tests.h"

START_TEST(s21_strrchr_test0) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strrchr(str, ' '), strrchr(str, ' '));
}
END_TEST

START_TEST(s21_strrchr_test1) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strrchr(str, '.'), strrchr(str, '.'));
}
END_TEST

START_TEST(s21_strrchr_test2) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strrchr(str, 'o'), strrchr(str, 'o'));
}
END_TEST

START_TEST(s21_strrchr_test3) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
}
END_TEST

START_TEST(s21_strrchr_test4) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_ptr_eq(s21_strrchr(str, 'z'), strrchr(str, 'z'));
}
END_TEST

START_TEST(s21_strrchr_test5) {
  char str[] = "aaaaaaa";
  ck_assert_str_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
}
END_TEST

Suite *s21_strrchr_test_suite() {
  Suite *s = suite_create("s21_strrchr");
  TCase *tc_case = tcase_create("s21_strrchr_case");
  tcase_add_test(tc_case, s21_strrchr_test0);
  tcase_add_test(tc_case, s21_strrchr_test1);
  tcase_add_test(tc_case, s21_strrchr_test2);
  tcase_add_test(tc_case, s21_strrchr_test3);
  tcase_add_test(tc_case, s21_strrchr_test4);
  tcase_add_test(tc_case, s21_strrchr_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strrchr_tests() {
  Suite *s = s21_strrchr_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
