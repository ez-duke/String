#include "tests.h"

START_TEST(s21_sprintf_test0) {
  char str[100];
  char original[100];

  s21_sprintf(str, "%.f", 1.f);
  sprintf(original, "%.f", 1.f);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%+-10.3lf", 0.00000002345);
  sprintf(original, "%+-10.3lf", 0.00000002345);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%+.5f", 1234523459.123456789);
  sprintf(original, "%+.5f", 1234523459.123456789);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%.5f", 1.f);
  sprintf(original, "%.5f", 1.f);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "% f", 0.00345);
  sprintf(original, "% f", 0.00345);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%.0f", 0.00345);
  sprintf(original, "%.0f", 0.00345);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%.20f", 1234567.0034598765432987654321);
  sprintf(original, "%.20f", 1234567.0034598765432987654321);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%f", -1234567.0034598765432987654321);
  sprintf(original, "%f", -1234567.0034598765432987654321);
  ck_assert_str_eq(str, original);
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str[100];
  char original[100];

  s21_sprintf(str, "%.20s.0", "Hello, world!");
  sprintf(original, "%.20s.0", "Hello, world!");
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%s.0", "Hello, world!");
  sprintf(original, "%s.0", "Hello, world!");
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%.0s.0", "Hello, world!");
  sprintf(original, "%.0s.0", "Hello, world!");
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%40.50s",
              "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut "
              "tristique mollis nisl et venenatis orci");
  sprintf(original, "%40.50s",
          "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut "
          "tristique mollis nisl et venenatis orci");
  ck_assert_str_eq(str, original);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str[100];
  char original[100];

  const char *test = "Hello, world!";

  for (size_t i = 0; test[i]; i++) {
    s21_sprintf(str, "%c", test[i]);
    sprintf(original, "%c", test[i]);

    ck_assert_str_eq(str, original);
  }

  const char *test2 =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut "
      "tristique mollis nisl et venenatis orci";

  for (size_t i = 0; test2[i]; i++) {
    s21_sprintf(str, "%c", test2[i]);
    sprintf(original, "%c", test2[i]);

    ck_assert_str_eq(str, original);
  }
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char str[100];
  char original[100];

  s21_sprintf(str, "%.8d", 15);
  sprintf(original, "%.8d", 15);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%hhd", 15);
  sprintf(original, "%hhd", 15);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%hd", -15);
  sprintf(original, "%hd", -15);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%d", 0);
  sprintf(original, "%d", 0);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "% lld", (long long)INT64_MAX);
  sprintf(original, "% lld", (long long)INT64_MAX);
  ck_assert_str_eq(str, original);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str[100];
  char original[100];

  s21_sprintf(str, "%hu", 15);
  sprintf(original, "%hu", 15);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%hhu", -15);
  sprintf(original, "%hhu", -15);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%u", 0);
  sprintf(original, "%u", 0);
  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%u", (unsigned)INT64_MIN);
  sprintf(original, "%u", (unsigned)INT64_MIN);
  ck_assert_str_eq(str, original);
}
END_TEST

START_TEST(s21_sprintf_test5) {
  char str[100];
  char original[100];

  s21_sprintf(str, " ");
  sprintf(original, " ");

  ck_assert_str_eq(str, original);

  s21_sprintf(str, "%%");
  sprintf(original, "%%");

  ck_assert_str_eq(str, original);
}
END_TEST

Suite *s21_sprintf_test_suite() {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc_case = tcase_create("s21_sprintf_case");
  tcase_add_test(tc_case, s21_sprintf_test0);
  tcase_add_test(tc_case, s21_sprintf_test1);
  tcase_add_test(tc_case, s21_sprintf_test2);
  tcase_add_test(tc_case, s21_sprintf_test3);
  tcase_add_test(tc_case, s21_sprintf_test4);
  tcase_add_test(tc_case, s21_sprintf_test5);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_sprintf_tests() {
  Suite *s = s21_sprintf_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
