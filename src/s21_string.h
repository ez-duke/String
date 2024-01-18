#ifndef S21_STRING_H
#define S21_STRING_H

#define S21_NULL ((void *)0)
typedef unsigned long long s21_size_t;

typedef struct Ssprintf {
  int minusflag;
  int plusflag;
  int spaceflag;
  int width;
  int precision;
  char length;
  int specifier;
  int string_len;
} Format;

#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_is_delim(int ch, const char *delim);
char *s21_tokenize(char *str, const char *delim);

char *s21_process_input(char *buf, char *str, va_list args);
char *s21_process_format(char **buf, char *str, Format *format_struct,
                         va_list args);
char *s21_format_char(char *buf, Format format_struct, int ch);
char *s21_format_int(char *buf, Format format_struct, long long int num);
char *s21_format_float(char *buf, Format format_struct, double num);
char *s21_format_string(char *buf, Format format_struct, char *str);
char *s21_format_unsigned(char *buf, Format format_struct,
                          long long unsigned int num);
char *s21_get_flags(char *str, Format *format_struct);
char *s21_get_width(char *str, Format *format_struct);
char *s21_get_precision(char *str, Format *format_struct);
char *s21_get_length(char *str, Format *format_struct);
char *s21_get_specifier(char *str, Format *format_struct);
void s21_print_chars(char **buf, int *chars, char ch);
void s21_correct_printables_int(int *spaces, int *nulls, int power,
                                Format format_struct);
void s21_correct_printables_string(int len, int *spaces, Format *format_struct);
int s21_calc_int_part(double num, char *num_string, int power);
int s21_print_float(double num, char *num_string, Format format_struct,
                    int power);
void s21_print_flags(char **buf, Format format_struct, int sign);
void s21_round(char *num_string, int power);

#endif
