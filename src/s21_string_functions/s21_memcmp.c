#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  if (n) {
    while (--n && *(char *)str1 == *(char *)str2) {
      str1 = (char *)str1 + 1;
      str2 = (char *)str2 + 1;
    }
    res = (*((unsigned char *)str1) - *((unsigned char *)str2));
  }
  return res;
}
