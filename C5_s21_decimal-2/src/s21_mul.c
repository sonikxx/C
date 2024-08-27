#include "s21_decimal.h"

int s21_mul(s21_decimal first, s21_decimal second, s21_decimal *result) {
  s21_decimal temp = second;
  make_zero_value(result);

  for (int i = 0; i <= 95; i++) {
    if (getbit_dec(first, i) == 1) {
      pre_add(*result, temp, result);
    }
    shift_left(&temp);
  }

  int res_pow = getpow_dec(first) + getpow_dec(second);
  setpow_dec(result, res_pow);
  if (get_sign_dec(first) == get_sign_dec(second)) {
    setsign_dec(result, 0);
  } else {
    setsign_dec(result, 1);
  }

  return 0;
}
