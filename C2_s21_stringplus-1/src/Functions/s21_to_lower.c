#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *stringByte = s21_NULL;
  if (str) {
    stringByte = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
  }
  if (stringByte) {
    s21_strncpy(stringByte, str, s21_strlen(str) + 1);
    for (char *i = stringByte; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') *i += 32;
    }
  }
  return (void *)stringByte;
}
