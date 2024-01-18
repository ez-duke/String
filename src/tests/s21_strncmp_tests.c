#include "tests.h"

START_TEST(s21_strncmp_test0) {
  const char *str1 = "HeLlO, WoRlD!";
  const char *str2 = "lO";
  s21_size_t n = 14;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test1) {
  const char *str1 = "HeLlO, WoRlD!";
  const char *str2 = "HeLlO, WoRlD!";
  s21_size_t n = 14;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test2) {
  const char *str1 = "HeLlO, WoRlD!";
  const char *str2 = "HeLlO, WoRlD!";
  s21_size_t n = 20;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test3) {
  const char *str1 = "HeLlO, WoRlD!";
  const char *str2 = "HeLlO, WoRlD!";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test4) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test5) {
  const char *str1 = "abcdEfG";
  const char *str2 = "abcdefg";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test6) {
  const char *str1 = "1122334455";
  const char *str2 = "11223344556677";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test7) {
  const char *str1 = "11223344556677";
  const char *str2 = "1122334455";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test8) {
  const char *str1 = "abcdefg";
  const char *str2 = "abcdefg";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test9) {
  const char *str1 = "apple";
  const char *str2 = "banana";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test10) {
  const char *str1 = "12345";
  const char *str2 = "12345";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test11) {
  const char *str1 = "aaaa";
  const char *str2 = "aaab";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test12) {
  const char *str1 = "abc";
  const char *str2 = "abcd";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test13) {
  const char *str1 = "abcdefg";
  const char *str2 = "xyz";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test14) {
  const char *str1 = "xyz";
  const char *str2 = "abc";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test15) {
  const char *str1 = "abc";
  const char *str2 = "abcd";
  s21_size_t n = 2;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test16) {
  const char *str1 = "";
  const char *str2 = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(s21_strncmp_test17) {
  const char *str1 = "abc";
  const char *str2 = "abd";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *s21_strncmp_test_suite() {
  Suite *s = suite_create("s21_strncmp");
  TCase *tc_case = tcase_create("s21_strncmp_case");
  tcase_add_test(tc_case, s21_strncmp_test0);
  tcase_add_test(tc_case, s21_strncmp_test1);
  tcase_add_test(tc_case, s21_strncmp_test2);
  tcase_add_test(tc_case, s21_strncmp_test3);
  tcase_add_test(tc_case, s21_strncmp_test4);
  tcase_add_test(tc_case, s21_strncmp_test5);
  tcase_add_test(tc_case, s21_strncmp_test6);
  tcase_add_test(tc_case, s21_strncmp_test7);
  tcase_add_test(tc_case, s21_strncmp_test8);
  tcase_add_test(tc_case, s21_strncmp_test9);
  tcase_add_test(tc_case, s21_strncmp_test10);
  tcase_add_test(tc_case, s21_strncmp_test11);
  tcase_add_test(tc_case, s21_strncmp_test12);
  tcase_add_test(tc_case, s21_strncmp_test13);
  tcase_add_test(tc_case, s21_strncmp_test14);
  tcase_add_test(tc_case, s21_strncmp_test15);
  tcase_add_test(tc_case, s21_strncmp_test16);
  tcase_add_test(tc_case, s21_strncmp_test17);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncmp_tests() {
  Suite *s = s21_strncmp_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
