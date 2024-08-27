#include "../s21_math.h"

long double s21_asin(double x) {
  if (S21_IS_NAN(x) || s21_fabs(x) > 1) return S21_NAN;
  if (x == 0) return 0;
  long double res = s21_atan(x / s21_sqrt(1 - x * x));

  /* asin(x) = atan(x / (sqrt(1 - x*x))), -1 < x < 1 */
  return res;
}