#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  if (((base == S21_INF_NEG || s21_fabs(base) > 1) && exp == S21_INF_NEG) ||
      (s21_fabs(base) < 1 && exp == S21_INF_POS))
    return 0;
  if ((base == S21_INF_NEG && exp == S21_INF_POS) ||
      (s21_fabs(base) < 1 && exp == S21_INF_NEG))
    return S21_INF_POS;
  if ((base == -1 && (exp == S21_INF_NEG || exp == S21_INF_POS)) ||
      (exp == 0) || (base == 1))
    return 1;
  if ((base < 0 && exp != (long long int)exp) ||
      (base == 1 && (exp == S21_INF_NEG || exp == S21_INF_POS)) ||
      S21_IS_NAN(base) || S21_IS_NAN(exp))
    return S21_NAN;

  long double res = 1;
  if (exp == (long long int)exp) {
    for (int i = 0; i < s21_fabs(exp); ++i) {
      res *= base;
    }
  } else {
    /* if exp is float */
    /* base^(exp) = e^(exp * ln po argumentu base) */
    res = s21_exp(exp * s21_log(base));
  }
  if (exp < 0 && exp == (long long int)exp) res = 1 / res;
  return res;
}
