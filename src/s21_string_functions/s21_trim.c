#include "../s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL && trim_chars != S21_NULL) {
    result = calloc(s21_strlen(src) + 1, sizeof(char));

    if (result) {
      int started = 0;
      int stopped = 0;
      for (s21_size_t i = 0, j = 0; src[i]; i++) {
        int match = 0;
        for (s21_size_t k = 0; trim_chars[k]; k++) {
          if (src[i] == trim_chars[k] && !stopped) {
            match++;

            if (!started) started = 1;
          }
          if (started && stopped) match = 0;
        }
        if (started && !match) stopped = 1;

        if (!match) {
          result[j] = src[i];
          j++;
        }
      }

      started = 0;
      stopped = 0;
      for (s21_size_t i = s21_strlen(result); i != 0; i--) {
        int match = 0;
        for (s21_size_t k = 0; trim_chars[k]; k++) {
          if (result[i] == trim_chars[k] && !stopped) {
            result[i] = '\0';
            match++;

            if (!started) started = 1;
          }
          if (started && stopped) match = 0;
        }
        if (started && !match) stopped = 1;
      }
    }
  }
  return result;
}
