#include "s21_decimal.h"

int s21_is_greater(s21_decimal q, s21_decimal w) {
  return (!s21_is_less_or_equal(q, w));
}