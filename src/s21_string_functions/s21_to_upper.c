#include "../s21_string.h"

void *s21_to_upper(const char *str) {
  char *result = S21_NULL;
  if (str != S21_NULL) {
    result = calloc(s21_strlen(str) + 1, sizeof(char));

    if (result) {
      for (s21_size_t i = 0; str[i]; i++) {
        result[i] = str[i];
        if (str[i] > 0x60 && str[i] < 0x7b) result[i] -= 32;
      }
    }
  }

  return result;
}
