#include "../s21_string.h"

char *s21_strchr(const char *string, int symbol) {
  char *ch = S21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(string) + 1; i++)
    if (string[i] == (char)symbol) {
      ch = (char *)&string[i];
      break;
    }
  return ch;
}
