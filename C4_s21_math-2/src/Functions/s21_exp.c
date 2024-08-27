#include "../s21_math.h"

long double s21_exp(double x) {
  if (x == S21_INF_NEG) return 0;
  if (x == S21_INF_POS) return S21_INF_POS;

  long double i = 1;
  long double add_value = 1;
  long double sum = 1;

  /* e^x = summary(x^n / n!) */
  while (s21_fabs(add_value) > S21_DBL_EPS) {
    add_value *= x / i;
    sum += add_value;
    ++i;
    if (sum > DBL_MAX) {
      return S21_INF_POS;
    }
  }
  return sum;
}
