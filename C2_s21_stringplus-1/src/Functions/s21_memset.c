#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *cstr = str;
  for (; n > 0; n--, cstr++) {
    *cstr = c;
  }
  return str;
}