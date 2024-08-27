#include "../s21_math.h"

long double s21_acos(double x) {
  if (S21_IS_NAN(x) || s21_fabs(x) > 1) return S21_NAN;
  if (x == 1) return 0;
  if (x == -1) return S21_PI;
  long double res = 0;
  /* if (0 <= x < 1) acos(x) = atan((sqrt(1 - x*x)) / x) */
  if (x < 1 && x >= 0) res = s21_atan(s21_sqrt(1 - x * x) / x);
  /* if (-1 < x < 0) acos(x) = PI + atan((sqrt(1 - x*x)) / x) */
  if (x < 0 && x > -1) res = (S21_PI + s21_atan(s21_sqrt(1 - x * x) / x));
  return res;
}