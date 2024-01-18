#include "tests.h"
START_TEST(s21_memcpy_test0) {
  const char* insert = " Hello, world!";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test1) {
  const char* insert = ",,,";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test2) {
  const char* insert = "/5/6/+";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < 10; i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test3) {
  const char* insert = "/5olckb;xfkb;xfjbh;xfjd +";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test4) {
  const char* insert = "#^&*(^&^";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test5) {
  const char* insert = "Hello";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test6) {
  const char* insert = "Hi, world!";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test7) {
  const char* insert = "Hello, world!";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test8) {
  const char* insert = "Hello";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test9) {
  const char* insert = "Hi";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test10) {
  const char* insert = "xyz";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test11) {
  const char* insert = "987654321";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test12) {
  const char* insert = "Bonjour, le monde!";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(insert); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test13) {
  const char* insert = "banana";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

START_TEST(s21_memcpy_test14) {
  const char* insert = "54321";
  char src[s21_strlen(insert)];
  for (s21_size_t i = 0; i < s21_strlen(src); i++) {
    s21_size_t start_index = i;
    void* orig = memcpy(src, insert, start_index);
    void* nefor = s21_memcpy(src, insert, start_index);
    if (!orig)
      ck_assert_ptr_eq(orig, nefor);
    else
      ck_assert_mem_eq(orig, nefor, s21_strlen(src));
  }
}
END_TEST

Suite* s21_memcpy_test_suite() {
  Suite* s = suite_create("s21_memcpy");
  TCase* tc_case = tcase_create("s21_memcpy_case");
  tcase_add_test(tc_case, s21_memcpy_test0);
  tcase_add_test(tc_case, s21_memcpy_test1);
  tcase_add_test(tc_case, s21_memcpy_test2);
  tcase_add_test(tc_case, s21_memcpy_test3);
  tcase_add_test(tc_case, s21_memcpy_test4);
  tcase_add_test(tc_case, s21_memcpy_test5);
  tcase_add_test(tc_case, s21_memcpy_test6);
  tcase_add_test(tc_case, s21_memcpy_test7);
  tcase_add_test(tc_case, s21_memcpy_test8);
  tcase_add_test(tc_case, s21_memcpy_test9);
  tcase_add_test(tc_case, s21_memcpy_test10);
  tcase_add_test(tc_case, s21_memcpy_test11);
  tcase_add_test(tc_case, s21_memcpy_test12);
  tcase_add_test(tc_case, s21_memcpy_test13);
  tcase_add_test(tc_case, s21_memcpy_test14);

  suite_add_tcase(s, tc_case);

  return s;
}

int s21_memcpy_tests() {
  Suite* s = s21_memcpy_test_suite();
  SRunner* runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  int failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return failed;
}
