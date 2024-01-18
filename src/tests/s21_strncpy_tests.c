#include "tests.h"

START_TEST(s21_strncpy_test0) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test1) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test2) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test3) {
  char str1[1];
  const char *str2 = "-";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test4) {
  char str1[10];
  const char *str2 = "Hello";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test5) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test6) {
  char str1[5];
  const char *str2 = "\0";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test7) {
  char str1[1];
  const char *str2 = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test8) {
  char str1[7];
  const char *str2 = "123";
  s21_size_t n = 7;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test10) {
  char str1[10];
  const char *str2 = "abcdefg";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test11) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test12) {
  char str1[5];
  const char *str2 = "123436";
  s21_size_t n = 2;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test13) {
  char str1[5];
  const char *str2 = "123436";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test14) {
  char str1[5];
  const char *str2 = "12345";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test15) {
  char str1[10];
  const char *str2 = "abc";
  s21_size_t n = 7;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test16) {
  char str1[15];
  const char *str2 = "Hello, World!";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

START_TEST(s21_strncpy_test17) {
  char str1[7];
  const char *str2 = "123456789";
  s21_size_t n = 7;
  ck_assert_str_eq(s21_strncpy(str1, str2, n), strncpy(str1, str2, n));
}
END_TEST

Suite *s21_strncpy_test_suite() {
  Suite *s = suite_create("s21_strncpy");
  TCase *tc_case = tcase_create("s21_strncpy_case");
  tcase_add_test(tc_case, s21_strncpy_test0);
  tcase_add_test(tc_case, s21_strncpy_test1);
  tcase_add_test(tc_case, s21_strncpy_test2);
  tcase_add_test(tc_case, s21_strncpy_test3);
  tcase_add_test(tc_case, s21_strncpy_test4);
  tcase_add_test(tc_case, s21_strncpy_test5);
  tcase_add_test(tc_case, s21_strncpy_test6);
  tcase_add_test(tc_case, s21_strncpy_test7);
  tcase_add_test(tc_case, s21_strncpy_test8);
  tcase_add_test(tc_case, s21_strncpy_test10);
  tcase_add_test(tc_case, s21_strncpy_test11);
  tcase_add_test(tc_case, s21_strncpy_test12);
  tcase_add_test(tc_case, s21_strncpy_test13);
  tcase_add_test(tc_case, s21_strncpy_test14);
  tcase_add_test(tc_case, s21_strncpy_test15);
  tcase_add_test(tc_case, s21_strncpy_test16);
  tcase_add_test(tc_case, s21_strncpy_test17);
  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncpy_tests() {
  Suite *s = s21_strncpy_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
