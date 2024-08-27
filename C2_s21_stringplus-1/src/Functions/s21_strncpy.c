#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *cdest = dest;
  while (n > 0) {
    *cdest = *src;
    ++cdest;
    ++src;
    --n;
  }
  return dest;
}