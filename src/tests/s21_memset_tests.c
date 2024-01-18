#include "tests.h"

START_TEST(s21_memset_test0) {
  char buffer[] = "Hello, world!";
  ck_assert_mem_eq(s21_memset(buffer, 0, 14), memset(buffer, 0, 14), 14);
}
END_TEST

START_TEST(s21_memset_test1) {
  char buffer[] = "Hello, world!";
  ck_assert_mem_eq(s21_memset(buffer, 15, 14), memset(buffer, 15, 14), 14);
}
END_TEST

START_TEST(s21_memset_test2) {
  int buffer[] = {15, 83, 467, 512, 8};
  ck_assert_mem_eq(s21_memset(buffer, 9, 5), memset(buffer, 9, 14), 5);
}
END_TEST

START_TEST(s21_memset_test3) {
  int *buffer = NULL;
  ck_assert_ptr_eq(s21_memset(buffer, 9, 14), s21_memset(buffer, 9, 14));
}
END_TEST

START_TEST(s21_memset_test4) {
  int buffer[] = {94, 43, 23, 5435, 543};
  ck_assert_ptr_eq(s21_memset(buffer, 9, 0), s21_memset(buffer, 9, 0));
}
END_TEST

START_TEST(s21_memset_test5) {
  int buffer[] = {15, 83, 467, 512, 8};
  ck_assert_mem_eq(s21_memset(buffer, 9, 3), memset(buffer, 9, 14), 3);
}
END_TEST

Suite *s21_memset_test_suite() {
  Suite *s = suite_create("s21_memset");
  TCase *tc_case = tcase_create("s21_memset_case");
  tcase_add_test(tc_case, s21_memset_test0);
  tcase_add_test(tc_case, s21_memset_test1);
  tcase_add_test(tc_case, s21_memset_test2);
  tcase_add_test(tc_case, s21_memset_test3);
  tcase_add_test(tc_case, s21_memset_test4);
  tcase_add_test(tc_case, s21_memset_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memset_tests() {
  Suite *s = s21_memset_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
