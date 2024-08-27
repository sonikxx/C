#include "s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal q, s21_decimal w) {
  int res = 0;
  normalize(&q, &w);
  int q1 = first1bitpos(q);
  int w1 = first1bitpos(w);
  int sign_q = get_sign_dec(q);
  int sign_w = get_sign_dec(w);
  int flag = 0;  // equal to 1 when abs(q) == abs(w)
  if (q1 > w1) {
    res = 1;
  } else if (q1 == w1) {
    for (int i = q1; i >= 0; i--) {
      if (getbit_dec(q, i) == 0 && getbit_dec(w, i) == 1) {
        res = 0;
        w1++;
        break;
      } else if (getbit_dec(q, i) == 1 && getbit_dec(w, i) == 0) {
        res = 1;
        q1++;
        break;
      }
      res = 1;
    }
  }
  if (q1 == w1) flag = 1;
  if (sign_q < sign_w)
    res = 1;
  else if (sign_q > sign_w)
    res = 0;
  else if (sign_q == 1 && sign_w == 1 && !flag) {
    res = abs(res - 1);
  }

  if (q.bits[0] == 0 && q.bits[1] == 0 && q.bits[2] == 0 && w.bits[0] == 0 &&
      w.bits[1] == 0 && w.bits[2] == 0)
    res = 1;  // +0 == -0

  return res;
}
