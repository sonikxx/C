#include "s21_decimal.h"

int s21_is_not_equal(s21_decimal q, s21_decimal w) {
  return !s21_is_equal(q, w);
}
