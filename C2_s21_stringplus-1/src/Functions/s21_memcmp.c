#include "../s21_string.h"

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  const unsigned char* str1_byte = (const unsigned char*)str1;
  const unsigned char* str2_byte = (const unsigned char*)str2;
  for (; n--; str1_byte++, str2_byte++) {
    if (*str1_byte != *str2_byte) {
      return (*str1_byte - *str2_byte);
    }
  }
  return 0;
}