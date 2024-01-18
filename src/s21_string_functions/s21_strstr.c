#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  int processing = 1, max_len = s21_strlen(needle);
  char *target = S21_NULL;

  if (*needle == '\0') {
    target = (char *)haystack;
    processing = 0;
  }
  
  while (processing && *haystack) {
    if (*haystack == *needle) {
      target = (char *)haystack;
      int len = 0;

      while (needle[len] && target[len] == needle[len]) len++;

      if (len == max_len) processing = 0;
    }
    haystack++;
  }

  if (processing) target = S21_NULL;

  return target;
}
