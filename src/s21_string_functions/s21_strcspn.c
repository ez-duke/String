#include "../s21_string.h"

s21_size_t s21_strcspn(const char *s1, const char *s2) {
  s21_size_t i = 0;

  for (; s1[i]; i++) {
    if (s21_strchr(s2, s1[i]) != S21_NULL) {
      break;
    }
  }

  return i;
}
