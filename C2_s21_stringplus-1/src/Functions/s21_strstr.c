#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t string_lenght = s21_strlen(needle);
  while (*haystack != '\0') {
    if (!s21_memcmp(haystack, needle, string_lenght)) {
      return (char *)haystack;
      ;
    }
    haystack++;
  }
  return s21_NULL;
}
