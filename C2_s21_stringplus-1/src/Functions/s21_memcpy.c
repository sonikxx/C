#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *cdest = dest;
  const char *csrc = (const char *)src;
  while (n > 0) {
    *cdest = *csrc;
    ++cdest;
    ++csrc;
    --n;
  }
  return dest;
}