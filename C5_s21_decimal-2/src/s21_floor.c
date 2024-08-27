#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && getpow_dec(value) <= 28) {
    make_zero_value(result);
    int sign = getbit_dec(value, 127);
    s21_truncate(value, result);
    if (sign) {
      int i = 0;
      while (getbit_dec(*result, i) == 1) {
        setbit_dec(result, 0, i);
        i++;
      }
      setbit_dec(result, 1, i);
    }
  } else {
    res = 1;
  }
  return res;
}

// 9246474251
// 924647