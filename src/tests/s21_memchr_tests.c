#include "tests.h"
START_TEST(s21_memchr_test0) {
  const char* src = "Hello, world!";
  const char* insert = " Hello, world!";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test1) {
  const char* src = ",,,";
  const char* insert = ",,,";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test2) {
  const char* src = "/)+-*)";
  int insert[] = {15, 83, 467, 512, 8};
  for (s21_size_t i = 0; i < 10; i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, 10);
  }
}
END_TEST

START_TEST(s21_memchr_test3) {
  const char* src = "/)+";
  const char* insert = "/5/6/+";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test4) {
  const char* src = "#^&*(^&^";
  const char* insert = "#^&*(^&^";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test5) {
  const char* src = "Hello, world!";
  const char* insert = "Hello";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test6) {
  const char* src = "Hello, world!";
  const char* insert = "Hi, world!";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test7) {
  const char* src = "";
  const char* insert = "Hello, world!";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test8) {
  const char* src = "Hello";
  const char* insert = "Hello";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test9) {
  const char* src = "Hello";
  const char* insert = "Hi";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test10) {
  const char* src = "abcdefg";
  const char* insert = "xyz";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test11) {
  const char* src = "123456789";
  const char* insert = "987654321";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test12) {
  const char* src = "Hello, world!";
  const char* insert = "Bonjour, le monde!";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test13) {
  const char* src = "apple";
  const char* insert = "banana";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memchr_test14) {
  const char* src = "12345";
  const char* insert = "54321";
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memchr(src, insert[i], start_index);
    void* nefor = s21_memchr(src, insert[i], start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

Suite* s21_memchr_test_suite() {
  Suite* s = suite_create("s21_memchr");
  TCase* tc_case = tcase_create("s21_memchr_case");
  tcase_add_test(tc_case, s21_memchr_test0);
  tcase_add_test(tc_case, s21_memchr_test1);
  tcase_add_test(tc_case, s21_memchr_test2);
  tcase_add_test(tc_case, s21_memchr_test3);
  tcase_add_test(tc_case, s21_memchr_test4);
  tcase_add_test(tc_case, s21_memchr_test5);
  tcase_add_test(tc_case, s21_memchr_test6);
  tcase_add_test(tc_case, s21_memchr_test7);
  tcase_add_test(tc_case, s21_memchr_test8);
  tcase_add_test(tc_case, s21_memchr_test9);
  tcase_add_test(tc_case, s21_memchr_test10);
  tcase_add_test(tc_case, s21_memchr_test11);
  tcase_add_test(tc_case, s21_memchr_test12);
  tcase_add_test(tc_case, s21_memchr_test13);
  tcase_add_test(tc_case, s21_memchr_test14);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memchr_tests() {
  Suite* s = s21_memchr_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
