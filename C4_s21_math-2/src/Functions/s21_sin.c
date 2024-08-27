#include "../s21_math.h"

long double s21_sin(double x) {
  if (S21_IS_NAN(x) || x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;
  if (x == 0) return 0;

  long double add_value = 1;
  long double sum = 0;

  /* period sin(x) is 2PI*/
  x = s21_fmod(x, 2 * S21_PI);
  if (x == 0) return -x;
  /* sin(x) = summary( (-1)^n * x ^ (2n + 1) / (2n + 1)! ) */
  for (long double index = 1; s21_fabs(add_value) > S21_DBL_EPS; ++index) {
    add_value = s21_pow(-1, index - 1) * s21_pow(x, 2 * index - 1) /
                s21_factorial(2 * index - 1);
    sum += add_value;
  }
  return sum;
}