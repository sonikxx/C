#include "s21_decimal.h"

int s21_is_equal(s21_decimal q, s21_decimal w) {
  int res = 1;
  normalize(&q, &w);
  for (int i = 127; i >= 0; i--) {
    if ((getbit_dec(q, i)) != (getbit_dec(w, i))) res = 0;
  }
  if (q.bits[0] == 0 && q.bits[1] == 0 && q.bits[2] == 0 && w.bits[0] == 0 &&
      w.bits[1] == 0 && w.bits[2] == 0)
    res = 1;
  return res;
}
