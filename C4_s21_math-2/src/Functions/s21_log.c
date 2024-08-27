#include "../s21_math.h"

long double s21_log(double x) {
  if (x == S21_INF_POS) return S21_INF_POS;
  if (x == 0) return S21_INF_NEG;
  if (x < 0) return S21_NAN;

  long double result = 0;
  long double prev;
  for (int i = 0; i < 200; ++i) {
    prev = result;
    result = prev + 2 * (x - s21_exp(prev)) / (x + s21_exp(prev));
  }

  return result;
}
