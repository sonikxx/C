#include "s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  if (result != NULL && getpow_dec(value) <= 28) {
    *result = value;
    if (getpow_dec(value)) {
      for (int i = 0; i < getpow_dec(value); i++) {
        divide_by_ten(result);
      }
      setpow_dec(result, 0);
    }
  } else {
    res = 1;
  }
  return res;
}
