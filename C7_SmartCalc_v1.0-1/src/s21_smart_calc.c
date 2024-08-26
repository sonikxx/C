#include "s21_smart_calc.h"

int s21_smart_calc(char string[MAX], double *result, const char x[MAX]) {
  int flag = OK;
  char output_string[255][MAX] = {0};
  if (strlen(string) > 255) {
    flag = ERROR;
  } else {
    if (s21_check_string(string, x) == ERROR) {
      flag = ERROR;
    } else {
      int count = 0;  // количество строчек в output_string
      if (s21_reverse_polish_notation(string, output_string, &count) == ERROR) {
        flag = ERROR;
        // printf("Неправильная скобочная последовательность\n");
      } else {
        if (s21_calculation_expressions(output_string, count, result) ==
            ERROR) {
          flag = ERROR;
          // printf("Нельзя решить это выражение\n");
        }
      }
    }
  }
  if (isnan(*result)) flag = ERROR;
  return flag;
}