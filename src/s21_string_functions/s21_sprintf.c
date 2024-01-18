#include "../s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list args = {};
  // с помощью str_start посчитаем число записанных символов
  char *str_start = str;

  va_start(args, format);
  str = s21_process_input(str, (char *)format, args);
  va_end(args);
  return str - str_start;
}

char *s21_process_input(char *buf, char *str, va_list args) {
  while (*str) {
    while (str[0] == '%' && str[1] == '%') {
      *buf = '%';
      buf++;
      str += 2;
    }

    if (*str == '%') {
      str++;
      Format format_struct = {};

      str = s21_process_format(&buf, str, &format_struct, args);
    } else {
      while (*str && *str != '%') {
        *buf = *str;
        buf++;
        str++;
      }
    }
  }

  *buf = '\0';
  return buf;
}

char *s21_process_format(char **buf, char *str, Format *format_struct,
                         va_list args) {
  str = s21_get_flags(str, format_struct);
  str = s21_get_width(str, format_struct);
  str = s21_get_precision(str, format_struct);
  str = s21_get_length(str, format_struct);
  str = s21_get_specifier(str, format_struct);

  long long unsigned int num = 0;
  double ldnum = 0;
  switch (format_struct->specifier) {
    case 'c':
      *buf = s21_format_char(*buf, *format_struct, va_arg(args, int));
      break;
    case 'd':
      num = va_arg(args, long long int);
      *buf = s21_format_int(*buf, *format_struct, num);
      break;
    case 'f':
      ldnum = va_arg(args, double);
      *buf = s21_format_float(*buf, *format_struct, ldnum);
      break;
    case 's':
      *buf = s21_format_string(*buf, *format_struct, va_arg(args, char *));
      break;
    case 'u':
      num = va_arg(args, long long unsigned int);
      *buf = s21_format_unsigned(*buf, *format_struct, num);
      break;
    default:
      *buf = s21_format_char(*buf, *format_struct, *str);
      str++;
  }
  return str;
}

char *s21_format_char(char *buf, Format format_struct, int ch) {
  int spaces = format_struct.width - 1;

  if (!format_struct.minusflag) s21_print_chars(&buf, &spaces, ' ');

  *buf = ch;
  buf++;

  if (spaces > 0) s21_print_chars(&buf, &spaces, ' ');
  return buf;
}

char *s21_format_int(char *buf, Format format_struct, long long int num) {
  int sign = 1, power = 0, spaces = format_struct.width,
      nulls = format_struct.precision, overflow = 0;
  ;
  char num_string[20] = {};

  if (format_struct.length > 0 && num < -9223372036854775807) {
    num = 9223372036854775807;
    overflow = 1;
    sign = -1;
  }

  switch (format_struct.length) {
    case 1:
      num = (long int)num;
      break;
    case 0:
      num = (int)num;
      break;
    case -1:
      num = (short int)num;
      break;
    case -2:
      num = (signed char)num;
  }
  if (num < 0) {
    num = -num;
    sign = -1;
  }

  do {
    num_string[power] = (num % 10) + '0';
    num /= 10;
    power++;
  } while (num);

  s21_correct_printables_int(&spaces, &nulls, power, format_struct);
  if (sign < 1 || format_struct.plusflag || format_struct.spaceflag) spaces--;

  if (!format_struct.minusflag) s21_print_chars(&buf, &spaces, ' ');
  s21_print_flags(&buf, format_struct, sign);
  s21_print_chars(&buf, &nulls, '0');

  for (; power > 0; power--) {
    *buf = num_string[power - 1];
    buf++;
  }
  if (overflow) *(buf - 1) += 1;

  if (spaces > 0) s21_print_chars(&buf, &spaces, ' ');
  return buf;
}

void s21_print_flags(char **buf, Format format_struct, int sign) {
  if (sign < 0) {
    **buf = '-';
    *buf += 1;
  } else if (format_struct.plusflag) {
    **buf = '+';
    *buf += 1;
  } else if (format_struct.spaceflag) {
    **buf = ' ';
    *buf += 1;
  }
}

void s21_correct_printables_int(int *spaces, int *nulls, int power,
                                Format format_struct) {
  if (format_struct.width > power)
    *spaces -= power;
  else
    *spaces = 0;
  if (format_struct.precision > power)
    *nulls -= power;
  else
    *nulls = 0;
  *spaces -= *nulls;
}

char *s21_format_float(char *buf, Format format_struct, double num) {
  if (format_struct.precision == -5) format_struct.precision = 6;
  int sign = 1, power = 0, spaces = format_struct.width,
      nulls = format_struct.precision;
  char num_string[5000] = {};

  if (num < 0) {
    num = -num;
    sign = -1;
  }

  power = s21_calc_int_part(num, num_string, power);
  power = s21_print_float(num, num_string, format_struct, power);
  s21_correct_printables_int(&spaces, &nulls, power, format_struct);
  if (sign < 1 || format_struct.plusflag || format_struct.spaceflag) spaces--;

  if (!format_struct.minusflag) s21_print_chars(&buf, &spaces, ' ');
  s21_print_flags(&buf, format_struct, sign);

  for (int i = 0; i < power; i++) {
    *buf = num_string[i];
    buf++;
  }
  s21_print_chars(&buf, &nulls, '0');
  if (spaces > 0) s21_print_chars(&buf, &spaces, ' ');

  return buf;
}

int s21_calc_int_part(double num, char *num_string, int power) {
  double int_part = floor(num);
  while (int_part >= 1) {
    num_string[power] = fmod(int_part, 10) + '0';
    int_part /= 10;
    power++;
  }

  // переворачиваем числа в массиве
  for (int i = 0; i < power / 2; i++) {
    int bup = num_string[i];
    num_string[i] = num_string[power - i - 1];
    num_string[power - i - 1] = bup;
  }
  return power;
}

int s21_print_float(double num, char *num_string, Format format_struct,
                    int power) {
  double fraction = (num - floor(num)) * 10;
  // на случай если число меньше нуля, печатаем ноль перед точкой
  if (num < 1) {
    num_string[power] = '0';
    power++;
  }
  // печатаем плавающую точку
  if (format_struct.precision > 0) {
    num_string[power] = '.';
    power++;
  }

  // печатаем дробную часть
  for (int i = 0; i < format_struct.precision; i++) {
    num_string[power] = floor(fraction) + '0';
    fraction -= floor(fraction);
    fraction *= 10;
    power++;
  }
  // ручное округление
  if (fraction >= 5) s21_round(num_string, power);

  return power;
}

void s21_round(char *num_string, int power) {
  int round = 0, i = 0;
  do {
    round = 0;
    if (num_string[power - i - 1] == '.') i++;
    if (num_string[power - i - 1] == '9') {
      num_string[power - i - 1] = '0';
      round = 1;
    } else {
      num_string[power - i - 1]++;
    }
    i++;
  } while (round && power - i > 0);
}

char *s21_format_string(char *buf, Format format_struct, char *str) {
  int len = s21_strlen(str);
  int spaces = format_struct.width;

  s21_correct_printables_string(len, &spaces, &format_struct);
  if (!format_struct.minusflag) s21_print_chars(&buf, &spaces, ' ');

  while (*str && format_struct.precision > 0) {
    *buf = *str;
    buf++;
    str++;
    format_struct.precision--;
  }

  if (spaces > 0) s21_print_chars(&buf, &spaces, ' ');
  return buf;
}

void s21_correct_printables_string(int len, int *spaces,
                                   Format *format_struct) {
  if (format_struct->precision == -5)
    format_struct->precision = len;
  else if (format_struct->precision == 0)
    *spaces = format_struct->width;
  else if (format_struct->precision > len)
    *spaces -= len;
  else
    *spaces -= format_struct->precision;
}

void s21_print_chars(char **buf, int *chars, char ch) {
  while (*chars > 0) {
    **buf = ch;
    *buf += 1;
    *chars -= 1;
  }
}

char *s21_format_unsigned(char *buf, Format format_struct,
                          long long unsigned int num) {
  switch (format_struct.length) {
    case 1:
      num = (unsigned long int)num;
      break;
    case 0:
      num = (unsigned int)num;
      break;
    case -1:
      num = (unsigned short int)num;
      break;
    case -2:
      num = (unsigned char)num;
  }

  int power = 0, spaces = format_struct.width, nulls = format_struct.precision;
  char num_string[20] = {};

  do {
    num_string[power] = (num % 10) + '0';
    num /= 10;
    power++;
  } while (num);

  s21_correct_printables_int(&spaces, &nulls, power, format_struct);
  if (format_struct.plusflag || format_struct.spaceflag) spaces--;

  if (!format_struct.minusflag) s21_print_chars(&buf, &spaces, ' ');
  s21_print_chars(&buf, &nulls, '0');

  for (; power > 0; power--) {
    *buf = num_string[power - 1];
    buf++;
  }
  if (spaces > 0) s21_print_chars(&buf, &spaces, ' ');

  return buf;
}

char *s21_get_flags(char *str, Format *format_struct) {
  while (s21_strchr("-+ 0", *str)) {
    if (*str == '-') {
      format_struct->minusflag = 1;
    } else if (*str == '+') {
      format_struct->plusflag = 1;
    } else if (*str == ' ') {
      format_struct->spaceflag = 1;
    }
    str++;
  }

  if (format_struct->plusflag && format_struct->spaceflag)
    format_struct->spaceflag = 0;
  return str;
}

char *s21_get_width(char *str, Format *format_struct) {
  while (*str >= '0' && *str <= '9') {
    format_struct->width = format_struct->width * 10 + *str - '0';
    str++;
  }
  return str;
}

char *s21_get_precision(char *str, Format *format_struct) {
  if (*str == '.') {
    str++;
    while (*str >= '0' && *str <= '9') {
      format_struct->precision = format_struct->precision * 10 + *str - '0';
      str++;
    }
  } else {
    // если точность не указали, юзаем эту незатейливую константу
    format_struct->precision = -5;
  }
  return str;
}

char *s21_get_length(char *str, Format *format_struct) {
  while (*str == 'l' || *str == 'h') {
    if (*str == 'l') {
      if (format_struct->length == 1)
        format_struct->length = 2;
      else
        format_struct->length = 1;
    } else {
      if (format_struct->length < 1 && format_struct->length > -2)
        format_struct->length -= 1;
    }
    str++;
  }
  return str;
}

char *s21_get_specifier(char *str, Format *format_struct) {
  if (s21_strchr("cdfsu", *str)) {
    format_struct->specifier = *str;
    str++;
  }
  return str;
}
