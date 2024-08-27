#include "../s21_math.h"

long double s21_atan(double x) {
  if (S21_IS_NAN(x)) return S21_NAN;
  if (x == 0) return 0;
  if (x == S21_INF_POS) return (S21_PI / 2);
  if (x == S21_INF_NEG) return (-S21_PI / 2);
  if (x == -1) return -0.7853981634;
  if (x == 1) return 0.7853981634;

  long double add_value = 1;
  long double sum = 0;

  /* atan(x) = summary( (-1)^n * x ^ (1 + 2 * n) / (1 + 2 * n) ), -1 < x < 1 */
  if (s21_fabs(x) < 1) {
    for (long double index = 1; s21_fabs(add_value) > S21_DBL_EPS; ++index) {
      add_value =
          s21_pow(-1, index - 1) * s21_pow(x, 2 * index - 1) / (2 * index - 1);
      sum += add_value;
    }
  }
  /* atan(x) = PI * sqrt(x^2) / 2x - summa ry( (-1)^n * x ^ (-1 - 2 * n) / (1 +
   * 2
   * * n) ), x > 1 or x < -1 */
  if (s21_fabs(x) > 1) {
    for (long double index = 0; s21_fabs(add_value) > S21_DBL_EPS; ++index) {
      add_value =
          s21_pow(-1, index) * s21_pow(x, -1 - 2 * index) / (1 + 2 * index);
      sum += add_value;
    }
    sum = (S21_PI * (s21_sqrt(x * x)) / (2 * x)) - sum;
  }
  return sum;
}