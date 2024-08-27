#include "../s21_math.h"

long double s21_ceil(double x) {
  if (S21_IS_NAN(x)) return S21_NAN;
  if (x == S21_INF_POS || x == S21_INF_NEG) return x;

  /* 10 = (int)10.9 */
  int res = (int)x;
  /* 10 < 10.9 */
  if (res < x) {
    /* res == 11 */
    res += 1;
  }
  return res;
}
