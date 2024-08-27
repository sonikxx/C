#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  /* Pointer temp to end of the dest string */
  char *tmp = dest + s21_strlen(dest);
  /* Appending characters from src to the dest string */
  while (*src != '\0' && n > 0) {
    *tmp = *src;
    ++tmp;
    ++src;
    --n;
  }
  *tmp = '\0';
  return dest;
}
