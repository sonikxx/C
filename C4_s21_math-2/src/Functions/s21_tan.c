#include "../s21_math.h"

long double s21_tan(double x) {
  if (S21_IS_NAN(x) || x == S21_INF_POS || x == S21_INF_NEG || s21_cos(x) == 0)
    return S21_NAN;
  if (x == 0) return 0;

  long double sum = 0;

  x = s21_fmod(x, S21_PI);
  if (x == 0) return -x;
  if (x == S21_PI / 2) return 16331239353195370;
  if (x == -(S21_PI / 2)) return -16331239353195370;
  if (s21_cos(x) == 0) return S21_NAN;
  /* tg α = sin α / cos α  */
  sum = s21_sin(x) / s21_cos(x);
  return sum;
}
