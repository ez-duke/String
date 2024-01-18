#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *result = S21_NULL;

  while (*str) {
    if (*str == c) result = (char *)str;
    str++;
  }
  if (c == '\0') result = (char *)str;

  return result;
}
