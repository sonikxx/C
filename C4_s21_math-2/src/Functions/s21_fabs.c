#include "../s21_math.h"

long double s21_fabs(double x) {
  if (x == S21_INF_NEG) return S21_INF_POS;
  if (S21_IS_NAN(x)) return S21_NAN;
  /* |a| = a and |-a| = a */
  return (x < 0 && x >= -DBL_MAX) ? -x : x;
}
