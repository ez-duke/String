#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

int main() {
  char *str = s21_strstr("aboba", "\0");
  printf("%s\n", str);
  char *str2 = strstr("aboba", "\0");
  printf("%s\n", str2);
  return 0;
}
