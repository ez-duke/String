#include "tests.h"

START_TEST(s21_strpbrk_test0) {
  const char *str1 = "Hello, world!";
  const char *str2 = "wjpd";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test1) {
  const char *str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char *str2 = ".";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test2) {
  const char *str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char *str2 = "it";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test3) {
  const char *str1 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  const char *str2 = "";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(s21_strpbrk_test4) {
  const char *str1 = "";
  const char *str2 = "ipsum";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

Suite *s21_strpbrk_test_suite() {
  Suite *s = suite_create("s21_strpbrk");
  TCase *tc_case = tcase_create("s21_strpbrk_case");
  tcase_add_test(tc_case, s21_strpbrk_test0);
  tcase_add_test(tc_case, s21_strpbrk_test1);
  tcase_add_test(tc_case, s21_strpbrk_test2);
  tcase_add_test(tc_case, s21_strpbrk_test3);
  tcase_add_test(tc_case, s21_strpbrk_test4);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strpbrk_tests() {
  Suite *s = s21_strpbrk_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
