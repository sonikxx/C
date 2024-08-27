#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  for (; *str != '\0'; str++) {
    if (*str == c) {
      res = (char *)str;
    }
  }
  return res;
}
