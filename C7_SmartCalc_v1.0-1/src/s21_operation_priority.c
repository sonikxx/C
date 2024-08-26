#include "s21_smart_calc.h"

// o+ и o- унарные операции + и - соотвественно

int s21_operation_priority(char string[MAX]) {
  int result = 0;
  if (strcmp(string, "(") == 0) {
    result = 1;
  } else if (strcmp(string, "+") == 0 || strcmp(string, "-") == 0) {
    result = 2;
  } else if (strcmp(string, "*") == 0 || strcmp(string, "/") == 0 ||
             strcmp(string, "%") == 0) {
    result = 3;
  } else if (strcmp(string, "^") == 0) {
    result = 4;
  } else if (strcmp(string, "o+") == 0 || strcmp(string, "o-") == 0 ||
             strcmp(string, "sin") == 0 || strcmp(string, "cos") == 0 ||
             strcmp(string, "tan") == 0 || strcmp(string, "acos") == 0 ||
             strcmp(string, "asin") == 0 || strcmp(string, "atan") == 0 ||
             strcmp(string, "mod") == 0 || strcmp(string, "sqrt") == 0 ||
             strcmp(string, "ln") == 0 || strcmp(string, "log") == 0) {
    result = 5;
  }
  return result;
}