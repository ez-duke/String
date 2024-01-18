#include "tests.h"

START_TEST(s21_memcmp_test0) {
  const char* src = "Hello, world!";
  const char* insert = " Hello, world!";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test1) {
  const char* src = ",,,";
  const char* insert = ",,,";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test2) {
  const char* src = "/)+-*)";
  const char* insert = ",,,,,,";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test3) {
  const char* src = "/)+";
  const char* insert = "/5/6/+";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test4) {
  const char* src = "#^&*(^&^";
  const char* insert = "#^&*(^&^";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test5) {
  const char* src = "Hello, world!";
  const char* insert = "Hello";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test6) {
  const char* src = "Hello, world!";
  const char* insert = "Hi, world!";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test7) {
  const char* src = "";
  const char* insert = "Hello, world!";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test8) {
  const char* src = "Hello";
  const char* insert = "Hello";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test9) {
  const char* src = "Hello";
  const char* insert = "Hi";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test10) {
  const char* src = "abcdefg";
  const char* insert = "xyz";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test11) {
  const char* src = "123456789";
  const char* insert = "987654321";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test12) {
  const char* src = "Hello, world!";
  const char* insert = "Bonjour, le monde!";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test13) {
  const char* src = "apple";
  const char* insert = "banana";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

START_TEST(s21_memcmp_test14) {
  const char* src = "12345";
  const char* insert = "54321";
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    ck_assert_int_eq(memcmp(src, insert, start_index),
                     s21_memcmp(src, insert, start_index));
  }
}
END_TEST

Suite* s21_memcmp_test_suite() {
  Suite* s = suite_create("s21_memcmp");
  TCase* tc_case = tcase_create("s21_memcmp_case");
  tcase_add_test(tc_case, s21_memcmp_test0);
  tcase_add_test(tc_case, s21_memcmp_test1);
  tcase_add_test(tc_case, s21_memcmp_test2);
  tcase_add_test(tc_case, s21_memcmp_test3);
  tcase_add_test(tc_case, s21_memcmp_test4);
  tcase_add_test(tc_case, s21_memcmp_test5);
  tcase_add_test(tc_case, s21_memcmp_test6);
  tcase_add_test(tc_case, s21_memcmp_test7);
  tcase_add_test(tc_case, s21_memcmp_test8);
  tcase_add_test(tc_case, s21_memcmp_test9);
  tcase_add_test(tc_case, s21_memcmp_test10);
  tcase_add_test(tc_case, s21_memcmp_test11);
  tcase_add_test(tc_case, s21_memcmp_test12);
  tcase_add_test(tc_case, s21_memcmp_test13);
  tcase_add_test(tc_case, s21_memcmp_test14);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memcmp_tests() {
  Suite* s = s21_memcmp_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
