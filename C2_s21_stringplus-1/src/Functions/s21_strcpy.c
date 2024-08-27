#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *pointer = dest;
  for (; *src != '\0';) {
    *dest = *src;
    dest++;
    src++;
  }
  *dest = '\0';
  return pointer;
}