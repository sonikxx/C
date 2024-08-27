#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (; n > 0; n--, str1++, str2++) {
    if (*str1 != *str2) {
      break;
    }
  }
  if (n == 0)
    return 0;
  else
    return (*(unsigned char *)str1 - (*(unsigned char *)str2));
}
