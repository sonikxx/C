#include "s21_decimal.h"

int s21_is_less(s21_decimal q, s21_decimal w) {
  return !s21_is_greater_or_equal(q, w);
}
