#include "tests.h"

START_TEST(s21_strstr_test0) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strstr(str, " ."), strstr(str, " ."));
}
END_TEST

START_TEST(s21_strstr_test1) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strstr(str, ". "), strstr(str, ". "));
}
END_TEST

START_TEST(s21_strstr_test2) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strstr(str, " "), strstr(str, " "));
}
END_TEST

START_TEST(s21_strstr_test3) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strstr(str, "very."), strstr(str, "very."));
}
END_TEST

START_TEST(s21_strstr_test4) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_ptr_eq(s21_strstr(str, "znm"), strstr(str, "znm"));
}
END_TEST

START_TEST(s21_strstr_test5) {
  char str[] = "abobaaboba";
  ck_assert_str_eq(s21_strstr(str, "aboba"), strstr(str, "aboba"));
}
END_TEST

Suite *s21_strstr_test_suite() {
  Suite *s = suite_create("s21_strstr");
  TCase *tc_case = tcase_create("s21_strstr_case");
  tcase_add_test(tc_case, s21_strstr_test0);
  tcase_add_test(tc_case, s21_strstr_test1);
  tcase_add_test(tc_case, s21_strstr_test2);
  tcase_add_test(tc_case, s21_strstr_test3);
  tcase_add_test(tc_case, s21_strstr_test4);
  tcase_add_test(tc_case, s21_strstr_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strstr_tests() {
  Suite *s = s21_strstr_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
