#include "tests.h"

START_TEST(s21_strncat_test0) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = ", world!";

  s21_strncat(buffer1, plus, 5);
  strncat(buffer2, plus, 5);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test1) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = ", world!";

  s21_strncat(buffer1, plus, 0);
  strncat(buffer2, plus, 0);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test2) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = "\0";

  s21_strncat(buffer1, plus, 5);
  strncat(buffer2, plus, 5);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test3) {
  char buffer1[14] = "\0";
  char buffer2[14] = "\0";
  const char* plus = ", world";

  s21_strncat(buffer1, plus, 5);
  strncat(buffer2, plus, 5);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test4) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = "/123";

  s21_strncat(buffer1, plus, 2);
  strncat(buffer2, plus, 2);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test5) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = ",q";

  s21_strncat(buffer1, plus, 3);
  strncat(buffer2, plus, 3);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(s21_strncat_test6) {
  char buffer1[14] = "Hello";
  char buffer2[14] = "Hello";
  const char* plus = ",q ,dvakdf f jcdw eq e ";

  s21_strncat(buffer1, plus, 3);
  strncat(buffer2, plus, 3);

  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite* s21_strncat_test_suite() {
  Suite* s = suite_create("s21_strncat");
  TCase* tc_case = tcase_create("s21_strncat_case");
  tcase_add_test(tc_case, s21_strncat_test0);
  tcase_add_test(tc_case, s21_strncat_test1);
  tcase_add_test(tc_case, s21_strncat_test2);
  tcase_add_test(tc_case, s21_strncat_test3);
  tcase_add_test(tc_case, s21_strncat_test4);
  tcase_add_test(tc_case, s21_strncat_test5);
  tcase_add_test(tc_case, s21_strncat_test6);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strncat_tests() {
  Suite* s = s21_strncat_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
