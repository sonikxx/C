#include "../s21_math.h"

long double s21_factorial(double x) {
  if (x == 1 || x == 0)
    return 1;
  else if (x < 0)
    return S21_INF_POS;
  else
    // x! = x * (x - 1)!
    return x * s21_factorial(x - 1);
}
