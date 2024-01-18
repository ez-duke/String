#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *static_string = S21_NULL;
  char *result = S21_NULL;

  if (!str) str = static_string;

  if (str) {
    // сначала отбросить разделители в начале строки
    // по факту выполняется лишь в первый раз
    while (*str && s21_is_delim(*str, delim)) str++;

    if (!*str)
      result = S21_NULL;
    else
      result = str;

    if (result) static_string = s21_tokenize(str, delim);
  }

  return result;
}

char *s21_tokenize(char *str, const char *delim) {
  // пропустить все обычные символы
  while (*str && !s21_is_delim(*str, delim)) str++;

  // и убрать все разделители
  while (*str && s21_is_delim(*str, delim)) {
    *str = '\0';
    str++;
  }

  return str;
}

int s21_is_delim(int ch, const char *delim) {
  int found = 0;

  while (!found && *delim) {
    if (ch == *delim) found = 1;
    delim++;
  }

  return found;
}
