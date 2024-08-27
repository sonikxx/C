#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#define s21_FLOAT_MIN 1e-28
#define s21_DEC_MAX 79228162514264337593543950335.0
#define s21_INT_MAX 2147483658
#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_NEG_INF -1.0 / 0.0

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

//  helpers
void reversebit_dec(s21_decimal *src, int pos);
void setsign_dec(s21_decimal *dec, int res);

void setbit_dec(s21_decimal *src, int val, int pos);
int getbit_dec(s21_decimal src, int pos);

void printbitss_dec(s21_decimal src);

int getpow_dec(s21_decimal src);
void setpow_dec(s21_decimal *src, int pow);
void shift_left(s21_decimal *dec);   // == mul by two
void shift_right(s21_decimal *src);  // == div by two
void divide_by_ten(s21_decimal *dec);
void mult_by_ten(s21_decimal *dec);

int first1bitpos(s21_decimal a);
void normalize(s21_decimal *a, s21_decimal *b);

int get_sign_dec(s21_decimal dec);       // получаем знак
void make_zero_value(s21_decimal *res);  // result = 0000000
int pre_add(
    s21_decimal value_1, s21_decimal value_2,
    s21_decimal *result);  //  прост сложение двух чисел без учета степени
s21_decimal s21_copy_dec(s21_decimal val);  //  копирование для модуля
void inverse(s21_decimal *res);  // переводим в дом код
s21_decimal s21_abs_dec(s21_decimal val);          // молудль числа
s21_decimal get_after_point(s21_decimal value_1);  //  1.11 --> 0.11

// primers | converters

int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_int_to_decimal(
    int src, s21_decimal *dst);  // Возвращаемое значение - код ошибки: 0 - OK |
                                 //  1 - ошибка конвертаци
int s21_from_decimal_to_int(s21_decimal src, int *dst);

int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

int s21_is_equal(s21_decimal q, s21_decimal w);
int s21_is_not_equal(s21_decimal q, s21_decimal w);
int s21_is_greater_or_equal(s21_decimal q, s21_decimal w);
int s21_is_less(s21_decimal q, s21_decimal w);
int s21_is_less_or_equal(s21_decimal q, s21_decimal w);
int s21_is_greater(s21_decimal q, s21_decimal w);

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal first, s21_decimal second, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif  //  SRC_S21_DECIMAL_H_
// bits[0], bits[1], и bits[2] содержат младшие, средние и старшие 32 бита
// 96-разрядного целого числа соответственно. bits[3] содержит коэффициент
// масштабирования и знак, и состоит из следующих частей:

// Биты от 0 до 15, младшее слово, не используются и должны быть равны нулю.
// Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который
// указывает степень 10 для разделения целого числа. Биты с 24 по 30 не
// используются и должны быть равны нулю. Бит 31 содержит знак; 0 означает
// положительный, а 1 означает отрицательный.

// 302231725137227122016259
// 3022317251372271220162
// 30038705072556119955
