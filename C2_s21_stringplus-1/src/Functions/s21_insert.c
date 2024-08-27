#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t src_lenght = s21_strlen(src), str_lenght = s21_strlen(str);
  s21_size_t new_lenght = src_lenght + str_lenght;
  if (start_index > src_lenght) return s21_NULL;
  char *pointer = (char *)calloc((new_lenght + 1), sizeof(char));
  if (!pointer) return s21_NULL;
  s21_strncpy(pointer, src, start_index);
  s21_strcat(pointer, str);
  s21_strcat(pointer, src + start_index);
  return pointer;
}