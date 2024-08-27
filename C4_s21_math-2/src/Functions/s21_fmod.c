#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  if (y == 0) return S21_NAN;

  if ((S21_IS_NAN(x)) && (S21_IS_NAN(y))) return S21_NAN;
  if ((x == S21_INF_POS || x == S21_INF_NEG) && (!S21_IS_NAN(y)))
    return S21_NAN;
  if ((x == 0 || x == -0) && (!S21_IS_NAN(y)) && y != 0) return x;
  if ((y == S21_INF_NEG || y == S21_INF_POS) && x != S21_NAN) return x;

  int n = x / y;
  long double res = (long double)x - n * (long double)y;
  return res;
}
