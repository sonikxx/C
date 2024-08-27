#include "../s21_math.h"

long double s21_sqrt(double x) {
  if (x < 0 || x == S21_INF_NEG || x == S21_NAN) return S21_NAN;
  if (x == S21_INF_POS) return S21_INF_POS;

  /* n-th sgrt(x) = x ^ (1/n) */
  return s21_pow(x, 0.5);
}
