#include "../s21_math.h"

int s21_abs(int x) {
  /* |a| = a and |-a| = a */
  return (x < 0 && x > INT_MIN) ? -x : x;
}
