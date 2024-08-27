#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *byte = (unsigned char *)str;
  while (n > 0) {
    if (*byte == (unsigned char)c) {
      return byte;
    }
    ++byte;
    --n;
  }
  return s21_NULL;
}