#include "s21_smart_calc.h"

int s21_is_char_in_str(char tmp_char, const char *string) {
  int flag = ERROR;
  for (size_t i = 0; i < strlen(string); ++i) {
    if (tmp_char == string[i]) flag = OK;
  }
  return flag;
}