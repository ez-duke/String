#include <stdio.h>

#include "../s21_string.h"

int s21_strncmp(const char *string_1, const char *string_2, s21_size_t n) {
  s21_size_t result = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (string_1[i] != string_2[i]) {
      result = string_1[i] - string_2[i];
      break;
    }
  }

  return result;
}
