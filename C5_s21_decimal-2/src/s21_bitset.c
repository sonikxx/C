#include "s21_decimal.h"

void setbit_dec(s21_decimal *dec, int val,
                int pos) {  // устанавливает значение 0 или 1 с помощью
                            // переменной /val/ на бит /pos/
  int mask = 1 << (pos % 32);
  if (val == 1) dec->bits[pos / 32] = dec->bits[pos / 32] | mask;
  if (val == 0) dec->bits[pos / 32] = dec->bits[pos / 32] & ~mask;
}

void setsign_dec(s21_decimal *dec,
                 int res) {  // устанавлиает знак /res/ в 127 бит
  if (res == 1) {
    dec->bits[3] = dec->bits[3] | 1 << 31;
  } else if (res == 0) {
    dec->bits[3] = dec->bits[3] & ~(1 << 31);
  }
}

void reversebit_dec(s21_decimal *dec,
                    int pos) {  // меняет значение бита по позиции /pos/
  int mask = 1 << (pos % 32);
  dec->bits[pos / 32] = dec->bits[pos / 32] ^ mask;
}

int getbit_dec(s21_decimal dec,
               int pos) {  // возвращает значение бита по позиции /pos/. 0 или 1
  int res = 0;
  if ((dec.bits[pos / 32] & (1 << pos % 32)) == 0)
    res = 0;
  else
    res = 1;
  return res;
}

void shift_right(s21_decimal *dec) {  // == div by two, тут имо всЁ понятно
  // opredelit' nomer pervogo bita == 1
  int bit = 0;
  int i = 95;
  while (bit == 0) {
    bit = getbit_dec(*dec, i);
    // printf("%d\n",bit);
    i--;
  }
  // sdvig vpravo
  int j = i;
  i++;
  int prev = getbit_dec(*dec, j + 1);
  int cur = getbit_dec(*dec, j);
  for (; j >= 0; j--) {
    cur = prev;
    prev = getbit_dec(*dec, j);
    setbit_dec(dec, cur, j);
  }
  // samiy bol'woy bit delaem nolikom
  setbit_dec(dec, 0, i);
  // printf("%d\n",i);
}

void shift_left(s21_decimal *dec) {
  // int bit = 0;
  int i = 0;
  int prev = getbit_dec(*dec, i);
  int curr = getbit_dec(*dec, i + 1);
  for (; i <= 95; i++) {
    curr = prev;
    prev = getbit_dec(*dec, i);
    setbit_dec(dec, curr, i);
    // if (i == 95 && prev) printf("\npiecedecimal\n");
  }
  setbit_dec(dec, 0, 0);
}

void divide_by_ten(s21_decimal *dec) {  // тут тоже
  long initial = 0;
  int rest = 0;
  for (int i = 2; i >= 0; i--) {
    initial = rest * 4294967296 + dec->bits[i];
    dec->bits[i] = initial / 10;
    rest = initial - dec->bits[i] * 10;
    // printf("!%d\n",rest);
  }
}

void mult_by_ten(s21_decimal *dec) {
  shift_left(dec);
  s21_decimal decx2 = *dec;
  shift_left(dec), shift_left(dec);
  // printbitss_dec(*dec), printbitss_dec(decx2);
  int bit1 = 0;
  int bit2 = 0;
  int f = 0;
  for (int i = 0; i <= 95; i++) {
    bit1 = getbit_dec(decx2, i);
    bit2 = getbit_dec(*dec, i);
    if (f == 0) {
      if (bit1 == 0 && bit2 == 0) setbit_dec(dec, 0, i), f = 0;
      if ((bit1 == 0 && bit2 == 1) || (bit1 == 1 && bit2 == 0))
        setbit_dec(dec, 1, i), f = 0;
      if (bit1 == 1 && bit2 == 1) setbit_dec(dec, 0, i), f = 1;
    } else if (f == 1) {
      if (bit1 == 0 && bit2 == 0) setbit_dec(dec, 1, i), f = 0;
      if ((bit1 == 0 && bit2 == 1) || (bit1 == 1 && bit2 == 0))
        setbit_dec(dec, 0, i), f = 1;
      if (bit1 == 1 && bit2 == 1) setbit_dec(dec, 1, i), f = 1;
    }
  }
}

int getpow_dec(s21_decimal dec) {  //возвращает значение степени децимала
  // int bits[5];
  int res = 0, s = 0;
  for (int i = 16; i < 23; i++) {
    int mask = 1 << i;
    int masked_n = dec.bits[3] & mask;
    int thebit = masked_n >> i;
    res += thebit * pow(2, s);
    s++;
  }
  return res;  // should be <= 28
}

void setpow_dec(
    s21_decimal *dec,
    int pow) {  //устааливает степень децимала значением, указанным в /pow/
  int bits[6] = {0};
  int i = 0;
  int sign = getbit_dec(*dec, 127);
  dec->bits[3] = 0;
  while (pow > 0) {
    if (pow % 2 == 1)
      bits[i] = 1;
    else
      bits[i] = 0;
    pow /= 2;
    i++;
  }

  for (int i = 116; i >= 112; i--) {
    setbit_dec(dec, bits[i - 112], i);
  }
  setbit_dec(dec, sign, 127);
}

void printbitss_dec(s21_decimal dec) {  // топ функция, выводящая на экран
                                        // децимал. 3->2->1->0 инт
  for (int i = 127; i >= 0; i--) {
    printf("%d", getbit_dec(dec, i));
    if (i == 127 || i == 120 || i == 112) printf(" ");
    if (i == 32 || i == 64 || i == 96) printf("|");
  }
  printf("\n");
}

// 1 0000000 00000111
// 0000000000000000|00000000000000000000000000000000|00000000000000000000000000000000|00000000000000000000000000010011

int first1bitpos(s21_decimal a) {
  int i = 95;
  while (getbit_dec(a, i) != 1) {
    i--;
  }
  return i;
}

void normalize(s21_decimal *a, s21_decimal *b) {
  int scale1 = getpow_dec(*a);
  int scale2 = getpow_dec(*b);

  if (scale1 > scale2) {
    while (scale1 != scale2) {
      mult_by_ten(b);
      scale2++;
    }
    setpow_dec(b, scale2);
  } else if (scale2 > scale1) {
    while (scale2 != scale1) {
      mult_by_ten(a);
      scale1++;
    }
    setpow_dec(a, scale1);
  }
}

int get_sign_dec(s21_decimal dec) {  //получаем знак
  int res = 0;
  if (getbit_dec(dec, 127)) {
    res = 1;
  }
  return res;
}
void make_zero_value(s21_decimal *res) {  // result = 0000000
  for (int i = 0; i < 128; i++) {
    setbit_dec(res, 0, i);
  }
}
int pre_add(
    s21_decimal value_1, s21_decimal value_2,
    s21_decimal *result) {  //  прост сложение двух чисел без учета степени
  make_zero_value(result);
  int tmp = 0;  // в уме
  int lhs = 0, rhs = 0;  // левый для value_1 правый соответсвенно
  for (int i = 0; i < 96; i++) {
    lhs = getbit_dec(value_1, i);
    rhs = getbit_dec(value_2, i);

    /*
    case 1: 1 1 1 -> lhs rhs tmp
    case 2 : 1 1 0  -> lhs rhs tmp
    case 3: 1 0 1  -> lhs rhs tmp
    case 4: 1 0 0  -> lhs rhs tmp неважно левый или правый
    case 5: 0 0 0  не нужон

    */
    if (lhs && rhs && tmp) {  //  1 1 1
      setbit_dec(result, 1, i);
    } else if ((lhs && rhs && (tmp == 0)) ||
               ((lhs || rhs) && tmp)) {  //  110 101 011
      tmp = 1;
      setbit_dec(result, 0, i);
    } else if (lhs || rhs || tmp) {  // 001 010 100
      setbit_dec(result, 1, i);
      tmp = 0;
    }
  }
  return 0;
}

s21_decimal s21_copy_dec(s21_decimal val) {  //  копирование для модуля
  s21_decimal copy_dec;
  for (int i = 0; i < 128; ++i) {
    setbit_dec(&copy_dec, getbit_dec(val, i), i);
  }
  return copy_dec;
}

void inverse(s21_decimal *res) {  // переводим в дом код
  s21_decimal one;
  s21_from_int_to_decimal(1, &one);
  for (int i = 0; i < 96; i++) {
    if (getbit_dec(*res, i)) {
      setbit_dec(res, 0, i);
    } else {
      setbit_dec(res, 1, i);
    }
  }
  s21_decimal tmp = s21_copy_dec(*res);
  pre_add(tmp, one, res);
}

s21_decimal s21_abs_dec(s21_decimal val) {  /// молудль числа
  s21_decimal abs_dec;
  abs_dec = s21_copy_dec(val);
  setsign_dec(&abs_dec, 0);
  return abs_dec;
}
