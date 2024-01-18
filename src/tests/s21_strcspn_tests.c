#include "tests.h"

START_TEST(s21_strcspn_test0) {
  const char* str1 = "Hello";
  const char* str2 = ", world!";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test1) {
  const char* str1 = "Hello";
  const char* str2 = "\0";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test2) {
  const char* str1 = "\0";
  const char* str2 = ", world!";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test3) {
  const char* str1 = "Hello";
  const char* str2 = "retry";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test4) {
  const char* str1 = "Hello";
  const char* str2 = "123";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(s21_strcspn_test5) {
  const char* str1 = "Hello";
  const char* str2 = "/!!";

  ck_assert_uint_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST
Suite* s21_strcspn_test_suite() {
  Suite* s = suite_create("s21_strcspn");
  TCase* tc_case = tcase_create("s21_strcspn_case");
  tcase_add_test(tc_case, s21_strcspn_test0);
  tcase_add_test(tc_case, s21_strcspn_test1);
  tcase_add_test(tc_case, s21_strcspn_test2);
  tcase_add_test(tc_case, s21_strcspn_test3);
  tcase_add_test(tc_case, s21_strcspn_test4);
  tcase_add_test(tc_case, s21_strcspn_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strcspn_tests() {
  Suite* s = s21_strcspn_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
