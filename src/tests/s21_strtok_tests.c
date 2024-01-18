#include "tests.h"

START_TEST(s21_strtok_test0) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strtok(str, " ."), strtok(str, " ."));
}
END_TEST

START_TEST(s21_strtok_test1) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strtok(str, "? "), strtok(str, "? "));
}
END_TEST

START_TEST(s21_strtok_test2) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strtok(str, "ab"), strtok(str, "ab"));
}
END_TEST

START_TEST(s21_strtok_test3) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strtok(str, "o"), strtok(str, "o"));
}
END_TEST

START_TEST(s21_strtok_test4) {
  char str[] = "aboba..is?  very.  ./ cool";
  ck_assert_str_eq(s21_strtok(str, "znm"), strtok(str, "znm"));
}
END_TEST

START_TEST(s21_strtok_test5) {
  char str[] = "aaabaaaaabaaaa";
  ck_assert_ptr_eq(s21_strtok(str, "ba"), strtok(str, "ba"));
}
END_TEST

Suite *s21_strtok_test_suite() {
  Suite *s = suite_create("s21_strtok");
  TCase *tc_case = tcase_create("s21_strtok_case");
  tcase_add_test(tc_case, s21_strtok_test0);
  tcase_add_test(tc_case, s21_strtok_test1);
  tcase_add_test(tc_case, s21_strtok_test2);
  tcase_add_test(tc_case, s21_strtok_test3);
  tcase_add_test(tc_case, s21_strtok_test4);
  tcase_add_test(tc_case, s21_strtok_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strtok_tests() {
  Suite *s = s21_strtok_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
