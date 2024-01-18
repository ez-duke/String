#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t str_dest = s21_strlen(dest);
  s21_size_t i = 0;

  for (; i < n; i++) {
    dest[str_dest + i] = src[i];
  }
  dest[str_dest + i] = '\0';

  return dest;
}
