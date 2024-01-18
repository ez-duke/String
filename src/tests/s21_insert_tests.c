#include "tests.h"

START_TEST(s21_insert_test0) {
  const char *buffer = "hello, world!";
  const char *inserted_item = " and goodbye";
  s21_size_t start_index = 5;

  char *result = s21_insert(buffer, inserted_item, start_index);
  ck_assert_str_eq("hello and goodbye, world!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test1) {
  const char *buffer = "ave morituri te salutant!";
  const char *inserted_item = ", Caesar,";
  s21_size_t start_index = 3;

  char *result = s21_insert(buffer, inserted_item, start_index);
  ck_assert_str_eq("ave, Caesar, morituri te salutant!", result);
  if (result) free(result);
}
END_TEST

START_TEST(s21_insert_test_null0) {
  ck_assert_pstr_eq(NULL, s21_insert(NULL, NULL, 0));
}
END_TEST

START_TEST(s21_insert_test_null1) {
  ck_assert_pstr_eq(NULL, s21_insert("hello, world!", NULL, 0));
}
END_TEST

START_TEST(s21_insert_test_null2) {
  ck_assert_pstr_eq(NULL, s21_insert(NULL, "hello, world!", 0));
}
END_TEST

START_TEST(s21_insert_test_null3) {
  ck_assert_pstr_eq(NULL, s21_insert("hello, world!", "and goodbye", 15));
}
END_TEST

Suite *s21_insert_test_suite() {
  Suite *s = suite_create("s21_insert");
  TCase *tc_case = tcase_create("s21_insert_case");
  tcase_add_test(tc_case, s21_insert_test0);
  tcase_add_test(tc_case, s21_insert_test1);
  tcase_add_test(tc_case, s21_insert_test_null0);
  tcase_add_test(tc_case, s21_insert_test_null1);
  tcase_add_test(tc_case, s21_insert_test_null2);
  tcase_add_test(tc_case, s21_insert_test_null3);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_insert_tests() {
  Suite *s = s21_insert_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
