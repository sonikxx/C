#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && getpow_dec(value) <= 28) {
    *result = value;
    int sign = getbit_dec(value, 127);
    if (sign)
      setbit_dec(result, 0, 127);
    else
      setbit_dec(result, 1, 127);
  } else {
    res = 1;
  }
  return res;
}
