#ifndef S21_MATH_H
#define S21_MATH_H
#include <float.h>
#include <limits.h>

#define S21_PI 3.14159265358979323846       // PI value
#define S21_NAN 0.0 / 0.0                   // not a number value(NAN)
#define S21_INF_POS +1.0 / 0.0              // positive infinity
#define S21_INF_NEG -1.0 / 0.0              // negative inifinity
#define S21_LN2 0.693147180559945309417232  // natural logarithm of 2
#define S21_E 2.71828182845904523536028747  // Euler's number()
#define S21_DBL_EPS 2.2204460492503131e-16  // epsilon(tiny double number)

#define S21_IS_NAN(x) (x != x)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_factorial(double x);

#endif
