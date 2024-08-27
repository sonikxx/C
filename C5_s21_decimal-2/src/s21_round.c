#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && getpow_dec(value) <= 28) {
    *result = value;
    s21_decimal qwe = {0};
    // int sign = getbit_dec(value,127);

    s21_decimal zxc = {0};
    //
    setbit_dec(&zxc, 1, 0);
    setbit_dec(&zxc, 1, 2);
    setpow_dec(&zxc, 1);
    // zxc = 0.5

    s21_truncate(value, result);  // now result contents integer part of value
    s21_sub(value, *result,
            &qwe);  // now there is a fractional part of value in qwe
    int i = 0;
    if (s21_is_greater_or_equal(qwe, zxc)) {
      while (getbit_dec(*result, i) == 1) {
        setbit_dec(result, 0, i);
        i++;
      }
      setbit_dec(result, 1, i);  // if fract > 0.5, abs(result)++
    }
  } else {
    res = 1;
  }

  return res;
}
