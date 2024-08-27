#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dec) {
  int res = 0;
  if (src != s21_INF && src != s21_NEG_INF && src != s21_NAN && dec != NULL) {
    make_zero_value(dec);
    if (src < 0) src *= -1, setsign_dec(dec, 1);
    dec->bits[0] = src;
  } else {
    res = 1;
  }

  return res;
}

int s21_from_decimal_to_int(s21_decimal dec, int *dst) {
  int res = 0;
  if (dst != NULL) {
    if (dec.bits[1] || dec.bits[2] || dec.bits[0] > s21_INT_MAX) res = 1;
    if (getpow_dec(dec)) {
      int step = getpow_dec(dec);
      while (step) {
        divide_by_ten(&dec);
        step--;
      }
    }
    int sign = getbit_dec(dec, 127);
    *dst = dec.bits[0];
    if (sign) *dst = -dec.bits[0];
  } else {
    res = 1;
  }

  return res;
}

int s21_from_float_to_decimal(float src, s21_decimal *dec) {
  int resf = 0;
  if (fabs(src) > s21_FLOAT_MIN && fabs(src) < s21_DEC_MAX && src != s21_INF &&
      src != s21_NEG_INF && src != s21_NAN && dec != NULL) {
    make_zero_value(dec);
    char fnum[101] = {0};
    sprintf(fnum, "%e", src);
    if (src < 0) {
      for (unsigned int i = 0; i < strlen(fnum); i++) {
        fnum[i] = fnum[i + 1];
      }
    }
    int val_numbers = 0;
    int fl = 0;
    int scalesign = 1;
    int escale = 0;
    unsigned int i = 0;
    for (; i < strlen(fnum); i++) {
      if (fnum[i] == '.') i++;
      if (fnum[i] == 'e') fl = 1;
      if (!fl) val_numbers = val_numbers * 10 + fnum[i] - 48;
      if (i == 9 && fnum[i] == '-') scalesign *= -1;
      if (fl && i > 9) escale = escale * 10 + fnum[i] - 48;
    }
    // на данном этапе у нас есть понимание интовой цифры, степени и является ли
    // степень +-
    int juk = 0;
    while (val_numbers % 10 == 0) {
      val_numbers /= 10;
      juk++;
    }
    s21_from_int_to_decimal(val_numbers, dec);

    if (escale) {
      if (scalesign > 0) {
        if (escale > 5) {
          while (escale - 6 + juk > 0) {
            mult_by_ten(dec);
            escale--;
          }
        } else if (escale < 5) {
          if (escale == 4) {
            if (juk <= escale) {
              if (juk == escale)
                mult_by_ten(dec), mult_by_ten(dec);
              else {
                for (int i = 0; i < 5 - escale; i++) {
                  mult_by_ten(dec);
                }
              }
            } else {
              for (int i = 0; i < 3; i++) {
                mult_by_ten(dec);
              }
            }
          } else {
            if (juk > escale) {
              while (escale) {
                mult_by_ten(dec);
                escale--;
              }
            } else {
              if (juk == escale)
                mult_by_ten(dec);
              else if (escale - juk > 0) {
                setpow_dec(dec, 6 - escale - juk);
              }
            }
          }

        } else if (escale == 5) {
          for (int i = 0; i < escale - juk; i++) {
            mult_by_ten(dec);
          }
        }
      } else if (scalesign < 0) {
        setpow_dec(dec, escale + 6 - juk);
      }
    } else {
      if (juk) {
        setpow_dec(dec, 6 - juk);
      } else {
        setpow_dec(dec, 6);
      }
    }
    if (src < 0) setsign_dec(dec, 1);
  } else {
    resf = 1;
  }
  return resf;
}

int s21_from_decimal_to_float(s21_decimal dec, float *dst) {
  int res = 0, i = 0;
  double qwe = 0;
  if (dst != NULL) {
    for (; i < 96; i++) {
      if (getbit_dec(dec, i)) {
        qwe += pow(2, i);
      }
    }
    int scale = getpow_dec(dec);
    while (scale) {
      qwe /= 10;
      scale--;
    }
    if (getbit_dec(dec, 127)) {
      qwe *= -1;
    }
    *dst = (float)qwe;
  } else {
    res = 1;
  }

  return res;
}
