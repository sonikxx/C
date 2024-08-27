#include "s21_decimal.h"

enum add_sub_mul_div_mod { OK = 0, LARGE = 1, SMALL = 2, ZERO_DIV = 3 };

int s21_add(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result) {  /// caмо сложение
  int res = OK;
  int sign = 0;
  make_zero_value(result);
  if (getpow_dec(value_1) != getpow_dec(value_2)) {
    normalize(&value_1, &value_2);
  }
  int pow = getpow_dec(value_1);

  if (get_sign_dec(value_1) == get_sign_dec(value_2)) {
    pre_add(value_1, value_2, result);
    sign = get_sign_dec(value_1);
    setsign_dec(result, sign);
    if (first1bitpos(value_1) > first1bitpos(*result) ||
        first1bitpos(value_2) > first1bitpos(*result)) {
      if (sign) {
        res = SMALL;
      } else {
        res = LARGE;
      }
    }
  } else if (get_sign_dec(value_1) != get_sign_dec(value_2)) {
    int sign = 0;
    if (s21_is_greater_or_equal(s21_abs_dec(value_1), s21_abs_dec(value_2))) {
      sign = get_sign_dec(value_1);
      inverse(&value_2);
    } else {
      inverse(&value_1);
      sign = get_sign_dec(value_2);
    }
    pre_add(value_1, value_2, result);
    setsign_dec(result, sign);
  }
  setpow_dec(result, pow);
  return res;
}
