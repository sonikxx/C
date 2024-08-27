#include "../s21_math.h"

long double s21_cos(double x) {
  if (S21_IS_NAN(x) || x == S21_INF_POS || x == S21_INF_NEG) return S21_NAN;
  if (x == 0) return 1;

  long double add_value = 1;
  long double sum = 0;

  /* period cos(x) is 2PI*/
  x = s21_fmod(x, 2 * S21_PI);
  /* cos(x) = summary( (-1)^n * x ^ 2n / (2n)! ) */
  for (long double index = 0; s21_fabs(add_value) > S21_DBL_EPS; ++index) {
    add_value =
        s21_pow(-1, index) * s21_pow(x, 2 * index) / s21_factorial(2 * index);
    sum += add_value;
  }
  return sum;
}