#include "tests.h"

START_TEST(s21_strchr_test0) {
  const char *str = "HeLlO, WoRlD!";
  int c = 'W';
  ck_assert_str_eq(s21_strchr(str, c), strchr(str, c));
}
END_TEST

START_TEST(s21_strchr_test1) {
  const char *str = "HEL543534LO,535345 5W43543545OrLD!";
  for (int i = 0; i < 34; i++) {
    ck_assert_str_eq(s21_strchr("HEL543534LO,535345 5W43543545OrLD!", str[i]),
                     strchr("HEL543534LO,535345 5W43543545OrLD!", str[i]));
  }
}
END_TEST

START_TEST(s21_strchr_test2) {
  // * pstr - для NULL
  ck_assert_pstr_eq(s21_strchr("A", 'a'), strchr("A", 'a'));
}
END_TEST

START_TEST(s21_strchr_test3) {
  ck_assert_str_eq(s21_strchr("-------------------", '-'),
                   strchr("-------------------", '-'));
}
END_TEST

START_TEST(s21_strchr_test4) {
  const char *str = "aaaaae";
  ck_assert_str_eq(s21_strchr(str, 'e'), strchr(str, 'e'));
}
END_TEST

START_TEST(s21_strchr_test5) {
  const char *str = "aaaaae";
  ck_assert_pstr_eq(s21_strchr(str, 'b'), strchr(str, 'b'));
}
END_TEST

START_TEST(s21_strchr_test6) {
  const char *str = "";
  ck_assert_pstr_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(s21_strchr_test7) {
  const char *str = "aaaa";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test8) {
  ck_assert_str_eq(s21_strchr("12345", '3'), strchr("12345", '3'));
}
END_TEST

START_TEST(s21_strchr_test9) {
  const char *str = "abcdefg";
  ck_assert_str_eq(s21_strchr(str, 'g'), strchr(str, 'g'));
}
END_TEST

START_TEST(s21_strchr_test10) {
  const char *str = "apple";
  ck_assert_str_eq(s21_strchr(str, 'p'), strchr(str, 'p'));
}
END_TEST

START_TEST(s21_strchr_test11) {
  const char *str = "banana";
  ck_assert_str_eq(s21_strchr(str, 'b'), strchr(str, 'b'));
}
END_TEST

START_TEST(s21_strchr_test12) {
  const char *str = "12345";
  ck_assert_pstr_eq(s21_strchr(str, '6'), strchr(str, '6'));
}
END_TEST

START_TEST(s21_strchr_test13) {
  const char *str = "aaaa";
  ck_assert_str_eq(s21_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(s21_strchr_test14) {
  const char *str = "HELLO";
  for (s21_size_t i = 0; i < 5; i++) {
    ck_assert_str_eq(s21_strchr(str, str[i]), strchr(str, str[i]));
  }
}
END_TEST

START_TEST(s21_strchr_test16) {
  const char *str = "123456";
  ck_assert_pstr_eq(s21_strchr(str, '7'), strchr(str, '7'));
}
END_TEST

START_TEST(s21_strchr_test17) {
  const char *str = "12345";
  ck_assert_str_eq(s21_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(s21_strchr_test18) {
  const char *str = "abc";
  ck_assert_str_eq(s21_strchr(str, 'c'), strchr(str, 'c'));
}
END_TEST

START_TEST(s21_strchr_test19) {
  const char *str = "abc";
  ck_assert_pstr_eq(s21_strchr(str, 'd'), strchr(str, 'd'));
}
END_TEST

START_TEST(s21_strchr_test20) {
  const char *str = "abc";
  ck_assert_pstr_eq(s21_strchr(str, ' '), strchr(str, ' '));
}
END_TEST

START_TEST(s21_strchr_test21) {
  const char *str = "abc";
  ck_assert_pstr_eq(s21_strchr(str, 'z'), strchr(str, 'z'));
}
END_TEST

START_TEST(s21_strchr_test22) {
  const char *str = "1234567";
  ck_assert_str_eq(s21_strchr(str, '1'), strchr(str, '1'));
}
END_TEST

START_TEST(s21_strchr_test23) {
  const char *str = "12345678";
  ck_assert_str_eq(s21_strchr(str, '8'), strchr(str, '8'));
}
END_TEST

START_TEST(s21_strchr_test24) {
  const char *str = "";
  ck_assert_pstr_eq(s21_strchr(str, '1'), strchr(str, '1'));
}
END_TEST

START_TEST(s21_strchr_test25) {
  const char *str = "abcdefg";
  ck_assert_pstr_eq(s21_strchr(str, 'h'), strchr(str, 'h'));
}
END_TEST

START_TEST(s21_strchr_test26) {
  const char *str = "abcdefg";
  ck_assert_pstr_eq(s21_strchr(str, '_'), strchr(str, '_'));
}
END_TEST

Suite *s21_strchr_test_suite() {
  Suite *s = suite_create("s21_strchr");
  TCase *tc_case = tcase_create("s21_strchr_case");
  tcase_add_test(tc_case, s21_strchr_test0);
  tcase_add_test(tc_case, s21_strchr_test1);
  tcase_add_test(tc_case, s21_strchr_test2);
  tcase_add_test(tc_case, s21_strchr_test3);
  tcase_add_test(tc_case, s21_strchr_test4);
  tcase_add_test(tc_case, s21_strchr_test5);
  tcase_add_test(tc_case, s21_strchr_test6);
  tcase_add_test(tc_case, s21_strchr_test7);
  tcase_add_test(tc_case, s21_strchr_test8);
  tcase_add_test(tc_case, s21_strchr_test9);
  tcase_add_test(tc_case, s21_strchr_test10);
  tcase_add_test(tc_case, s21_strchr_test11);
  tcase_add_test(tc_case, s21_strchr_test12);
  tcase_add_test(tc_case, s21_strchr_test13);
  tcase_add_test(tc_case, s21_strchr_test14);
  tcase_add_test(tc_case, s21_strchr_test16);
  tcase_add_test(tc_case, s21_strchr_test17);
  tcase_add_test(tc_case, s21_strchr_test18);
  tcase_add_test(tc_case, s21_strchr_test19);
  tcase_add_test(tc_case, s21_strchr_test20);
  tcase_add_test(tc_case, s21_strchr_test21);
  tcase_add_test(tc_case, s21_strchr_test22);
  tcase_add_test(tc_case, s21_strchr_test23);
  tcase_add_test(tc_case, s21_strchr_test24);
  tcase_add_test(tc_case, s21_strchr_test25);
  tcase_add_test(tc_case, s21_strchr_test26);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_strchr_tests() {
  Suite *s = s21_strchr_test_suite();
  SRunner *runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
