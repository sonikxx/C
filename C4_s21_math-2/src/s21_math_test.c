#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>

// S21_FACTORIAL_TEST

START_TEST(s21_factorial_test) {
  long double fact_arr[] = {7, 1, 0, 11, 5, 20, -1};
  long double fact_ans_arr[] = {
      5040, 1, 1, 39916800, 120, 2432902008176640000, S21_INF_POS};

  for (int i = 0; i < 7; i++)
    ck_assert_double_eq(s21_factorial(fact_arr[i]), fact_ans_arr[i]);
}
END_TEST

// S21_ABS_TEST

START_TEST(s21_abs_test) {
  int abs_arr[] = {-7, 1, 0, -11, -5, -100, S21_INF_POS, S21_INF_NEG, S21_NAN};

  for (int i = 0; i < 8; i++)
    ck_assert_int_eq(s21_abs(abs_arr[i]), abs(abs_arr[i]));
}
END_TEST

// S21_FABS_TEST

START_TEST(s21_fabs_test) {
  double fabs_arr[] = {-7.05,
                       -1.1,
                       0,
                       -11.11,
                       -5.1555,
                       -100.001,
                       -(-10),
                       -(10),
                       -(-10.9875),
                       -(10.9875),
                       (10.9875 * -1),
                       0.5,
                       -0.5,
                       0.1,
                       -0.1,
                       0.2,
                       -0.2,
                       0.3,
                       -0.3,
                       0.4,
                       -0.4,
                       0.0,
                       -0.0};

  for (int i = 0; i < 23; i++)
    ck_assert_double_eq(s21_fabs(fabs_arr[i]), fabs(fabs_arr[i]));
}
END_TEST

// S21_FABS_WITH_INFINITE_AND_NAN

START_TEST(s21_fabs_test_nan_inf) {
  ck_assert_double_eq(s21_fabs(S21_INF_POS), fabs(S21_INF_POS));
  ck_assert_double_eq(s21_fabs(S21_INF_NEG), fabs(S21_INF_NEG));
}
END_TEST

START_TEST(s21_fabs_test_nan_inf2) {
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_nan(fabs(S21_NAN));
}
END_TEST

START_TEST(s21_fabs_test_nan_inf3) {
  ck_assert_double_eq(s21_fabs(INFINITY), fabs(INFINITY));
}
END_TEST

START_TEST(s21_fabs_test_nan_inf4) {
  ck_assert_double_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

// S21_FMOD_TEST

START_TEST(s21_fmod_test) {
  ck_assert_double_eq_tol(s21_fmod(10, 15), fmod(10, 15), 0.000001);
  ck_assert_double_eq_tol(s21_fmod(100000, 13), fmod(100000, 13), 0.000001);
  ck_assert_double_eq_tol(s21_fmod(1586183461, 1245), fmod(1586183461, 1245),
                          0.000001);
  ck_assert_double_eq_tol(s21_fmod(124.1234, 11.111111),
                          fmod(124.1234, 11.111111), 0.000001);
}
END_TEST

// S21_FMOD_TESTS_WITH_INF_NAN

START_TEST(s21_fmod_test_nan_inf) {
  ck_assert_double_nan(s21_fmod(S21_INF_POS, S21_INF_POS));
  ck_assert_double_nan(fmod(S21_INF_POS, S21_INF_POS));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf2) {
  ck_assert_double_nan(s21_fmod(S21_INF_POS, S21_INF_NEG));
  ck_assert_double_nan(fmod(S21_INF_POS, S21_INF_NEG));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf3) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, S21_INF_NEG));
  ck_assert_double_nan(fmod(S21_INF_NEG, S21_INF_NEG));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf4) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, S21_INF_POS));
  ck_assert_double_nan(fmod(S21_INF_NEG, S21_INF_POS));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf5) {
  ck_assert_double_nan(s21_fmod(S21_INF_POS, S21_NAN));
  ck_assert_double_nan(fmod(S21_INF_POS, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf6) {
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF_POS));
  ck_assert_double_nan(fmod(S21_NAN, S21_INF_POS));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf7) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, S21_NAN));
  ck_assert_double_nan(fmod(S21_INF_NEG, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf8) {
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF_NEG));
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_INF_NEG));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf9) {
  ck_assert_double_nan(s21_fmod(10, 0));
  ck_assert_double_nan(fmod(10, 0));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf10) {
  ck_assert_double_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_double_nan(fmod(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf11) {
  ck_assert_double_nan(s21_fmod(S21_INF_POS, 3));
  ck_assert_double_nan(fmod(S21_INF_POS, 3));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf12) {
  ck_assert_double_nan(s21_fmod(S21_INF_NEG, 2));
  ck_assert_double_nan(fmod(S21_INF_NEG, 2));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf13) {
  ck_assert_double_nan(s21_fmod(S21_NAN, 1));
  ck_assert_double_nan(fmod(S21_NAN, 1));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf14) {
  ck_assert_double_eq(s21_fmod(100, S21_INF_POS), fmod(100, S21_INF_POS));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf15) {
  ck_assert_double_eq(s21_fmod(100, S21_INF_NEG), fmod(100, S21_INF_NEG));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf16) {
  ck_assert_double_eq(s21_fmod(0, S21_INF_POS), fmod(0, S21_INF_POS));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf17) {
  ck_assert_double_eq(s21_fmod(0, S21_INF_NEG), fmod(0, S21_INF_NEG));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf18) {
  ck_assert_double_nan(s21_fmod(0, NAN));
  ck_assert_double_nan(fmod(0, NAN));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf19) {
  ck_assert_double_nan(s21_fmod(S21_INF_POS, 0));
  ck_assert_double_nan(fmod(S21_INF_POS, 0));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf20) {
  ck_assert_double_nan(s21_fmod(-INFINITY, 0));
  ck_assert_double_nan(fmod(-INFINITY, 0));
}
END_TEST

START_TEST(s21_fmod_test_nan_inf21) {
  ck_assert_double_nan(s21_fmod(S21_NAN, 0));
  ck_assert_double_nan(fmod(S21_NAN, 0));
}
END_TEST

// S21_EXP_TEST

START_TEST(s21_exp_test) {
  ck_assert_double_eq_tol(s21_exp(127), exp(127), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-2), exp(-2), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-20), exp(-20), 0.000001);
  ck_assert_double_eq_tol(s21_exp(5.5), exp(5.5), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-5.5), exp(-5.5), 0.000001);
  ck_assert_double_eq_tol(s21_exp(80.009), exp(80.009), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-3.123456), exp(-3.123456), 0.000001);
  ck_assert_double_eq(s21_exp(25000.438), exp(25000.438));
  ck_assert_double_eq_tol(s21_exp(1), exp(1), 0.000001);
  ck_assert_double_eq_tol(s21_exp(-0), exp(-0), 0.000001);
  ck_assert_double_eq_tol(s21_exp(0), exp(0), 0.000001);
}
END_TEST

// S21_EXP_WITH_INF_NAN

START_TEST(s21_exp_test_nan_inf) {
  ck_assert_double_eq(s21_exp(S21_INF_POS), exp(S21_INF_POS));
}
END_TEST

START_TEST(s21_exp_test_nan_inf2) {
  ck_assert_double_eq(s21_exp(S21_INF_NEG), exp(S21_INF_NEG));
}
END_TEST

START_TEST(s21_exp_test_nan_inf3) {
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_double_nan(exp(S21_NAN));
}

START_TEST(s21_exp_test_nan_inf4) {
  ck_assert_double_nan(s21_exp(-S21_NAN));
  ck_assert_double_nan(exp(-S21_NAN));
}

// S21_LOG_TESTS

START_TEST(s21_log_test) {
  ck_assert_double_eq_tol(s21_log(0.005), log(0.005), 0.000001);
  ck_assert_double_eq_tol(s21_log(150.5), log(150.5), 0.000001);
  ck_assert_double_eq_tol(s21_log(1234.1234), log(1234.1234), 0.000001);
  ck_assert_double_eq_tol(s21_log(1.1111111), log(1.1111111), 0.000001);
  ck_assert_double_eq_tol(s21_log(0.0000001), log(0.0000001), 0.000001);
  ck_assert_double_eq_tol(s21_log(0.987654321), log(0.987654321), 0.000001);
}
END_TEST

START_TEST(s21_log_test_main) {
  long double log_values[] = {
      1234.1234, 600.59999123, 518495.123, 1.00000099999, 12.0,  0.1,
      0.2,       0.3,          0.4,        0.5,           0.005, 0.0000001};

  for (int index = 0; index < 12; index++) {
    ck_assert_double_eq_tol(s21_log(log_values[index]), log(log_values[index]),
                            0.000001);
  }
}
END_TEST

// S21_LOG_WITH_INF_NAN

START_TEST(s21_log_test_nan_inf) {
  ck_assert_double_nan(s21_log(NAN));
  ck_assert_double_nan(log(NAN));
}
END_TEST

START_TEST(s21_log_test_nan_inf2) { ck_assert_double_eq(s21_log(-0), log(-0)); }
END_TEST

START_TEST(s21_log_test_nan_inf3) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

START_TEST(s21_log_test_nan_inf4) {
  ck_assert_double_nan(s21_log(-1));
  ck_assert_double_nan(log(-1));
}
END_TEST

START_TEST(s21_log_test_nan_inf5) {
  ck_assert_double_eq(s21_log(S21_INF_POS), log(S21_INF_POS));
}
END_TEST

START_TEST(s21_log_test_nan_inf6) {
  ck_assert_double_nan(s21_log(S21_INF_NEG));
  ck_assert_double_nan(log(S21_INF_NEG));
}
END_TEST

START_TEST(s21_log_test_nan_inf7) {
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(log(S21_NAN));
}
END_TEST

START_TEST(s21_log_test_nan_inf8) {
  ck_assert_double_nan(s21_log(-S21_NAN));
  ck_assert_double_nan(log(-S21_NAN));
}
END_TEST

// S21_POW_TEST

START_TEST(s21_pow_test) {
  ck_assert_double_eq_tol(s21_pow(-1, 1), pow(-1, 1), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-2, -50), pow(-2, -50), 0.00001);
  ck_assert_double_eq_tol(s21_pow(500, 0), pow(500, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(5, 5.5), pow(5, 5.5), 0.000001);
  ck_assert_double_eq_tol(s21_pow(5, -5.5), pow(5, -5.5), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-16894.2629, -1545), pow(-16894.2629, -1545),
                          0.000001);
  ck_assert_double_eq_tol(s21_pow(12, 0), pow(12, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-12, 0), pow(-12, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(-11, 0), pow(-11, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(11, 0), pow(11, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(0, 0), pow(0, 0), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1, 11), pow(1, 11), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1, 12), pow(1, 12), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1, -11), pow(1, 11), 0.000001);
  ck_assert_double_eq_tol(s21_pow(1, -12), pow(1, 12), 0.000001);
}
END_TEST

// S21_POW_TEST_WITH_INF_AND_NAN_VALUES

START_TEST(s21_pow_test_nan_inf) {
  ck_assert_double_nan(s21_pow(0, S21_NAN));
  ck_assert_double_nan(pow(0, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_2) {
  ck_assert_double_nan(s21_pow(0, -(S21_NAN)));
  ck_assert_double_nan(pow(0, (S21_NAN)));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_3) {
  ck_assert_double_eq(s21_pow(0, S21_INF_NEG), pow(0, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_4) {
  ck_assert_double_eq(s21_pow(-1, S21_INF_NEG), pow(-1, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_5) {
  ck_assert_double_eq(s21_pow(-1, S21_INF_POS), pow(-1, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_6) {
  ck_assert_double_eq(s21_pow(1, S21_NAN), pow(1, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_7) {
  ck_assert_double_eq(s21_pow(1, S21_INF_POS), pow(1, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_8) {
  ck_assert_double_eq(s21_pow(1, 0), pow(1, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_9) {
  ck_assert_double_eq(s21_pow(1, 0), pow(1, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_10) {
  ck_assert_double_eq(s21_pow(S21_NAN, 0), pow(S21_NAN, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_11) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, 0), pow(S21_INF_POS, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_12) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, 0), pow(S21_INF_NEG, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_13) {
  ck_assert_double_eq(s21_pow(0, 11), pow(0, 11));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_14) {
  ck_assert_double_eq(s21_pow(0, -11), pow(0, -11));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_15) {
  ck_assert_double_eq(s21_pow(0, 12), pow(0, 12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_16) {
  ck_assert_double_eq(s21_pow(0, -12), pow(0, -12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_17) {
  ck_assert_double_eq(s21_pow(0.5, S21_INF_POS), pow(0.5, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_18) {
  ck_assert_double_eq(s21_pow(0.5, S21_INF_NEG), pow(0.5, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_19) {
  ck_assert_double_eq(s21_pow(-0.5, S21_INF_NEG), pow(-0.5, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_20) {
  ck_assert_double_eq(s21_pow(-0.5, S21_INF_POS), pow(-0.5, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_21) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, 0), pow(S21_INF_NEG, 0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_22) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, -0), pow(S21_INF_NEG, -0));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_23) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, 12), pow(S21_INF_POS, 12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_24) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, -12), pow(S21_INF_POS, -12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_25) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, 12), pow(S21_INF_NEG, 12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_26) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, -12), pow(S21_INF_NEG, -12));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_27) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, S21_INF_POS),
                      pow(S21_INF_POS, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_28) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, S21_INF_NEG),
                      pow(S21_INF_POS, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_29) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, S21_INF_POS),
                      pow(S21_INF_NEG, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_30) {
  ck_assert_double_eq(s21_pow(S21_INF_NEG, S21_INF_NEG),
                      pow(S21_INF_NEG, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_31) {
  ck_assert_double_nan(s21_pow(S21_INF_NEG, S21_NAN));
  ck_assert_double_nan(pow(S21_INF_NEG, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_32) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF_NEG));
  ck_assert_double_nan(pow(S21_NAN, S21_INF_NEG));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_33) {
  ck_assert_double_nan(s21_pow(S21_INF_POS, S21_NAN));
  ck_assert_double_nan(pow(S21_INF_POS, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_34) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_INF_POS));
  ck_assert_double_nan(pow(S21_NAN, S21_INF_POS));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_35) {
  ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
  ck_assert_double_nan(pow(S21_NAN, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_36) {
  ck_assert_double_nan(s21_pow(S21_NAN, 13));
  ck_assert_double_nan(pow(S21_NAN, 13));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_37) {
  ck_assert_double_nan(s21_pow(S21_NAN, 22));
  ck_assert_double_nan(pow(S21_NAN, 22));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_38) {
  ck_assert_double_nan(s21_pow(22, S21_NAN));
  ck_assert_double_nan(pow(22, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_39) {
  ck_assert_double_nan(s21_pow(13, S21_NAN));
  ck_assert_double_nan(pow(13, S21_NAN));
}
END_TEST

START_TEST(s21_pow_test_nan_inf_40) {
  ck_assert_double_nan(s21_pow(13.123, S21_NAN));
  ck_assert_double_nan(pow(13.123, S21_NAN));
}
END_TEST

// TEST_FOR_S21_SQRT

START_TEST(s21_sqrt_test) {
  long double sqrt_value[] = {0.00004,    13567.00004, 5,           5.000000001,
                              123.456123, 65314.24511, 312345.1452, 0.00000001,
                              150,        228,         1337};

  for (int index = 0; index < 11; index++) {
    ck_assert_double_eq_tol(s21_sqrt(sqrt_value[index]),
                            sqrt(sqrt_value[index]), 0.000001);
  }
}
END_TEST

// TEST_FOR_S21_SQRT_WITH_NAN_AND_INF

START_TEST(s21_sqrt_test_nan_inf) {
  ck_assert_double_nan(s21_sqrt(-5));
  ck_assert_double_nan(sqrt(-5));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_2) {
  ck_assert_double_nan(s21_sqrt(-4.2134145145));
  ck_assert_double_nan(sqrt(-4.2134145145));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_3) {
  ck_assert_double_eq(s21_sqrt(S21_INF_POS), sqrt(S21_INF_POS));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_4) {
  ck_assert_double_nan(s21_sqrt(S21_INF_NEG));
  ck_assert_double_nan(sqrt(S21_INF_NEG));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_5) {
  ck_assert_double_eq(s21_sqrt(0), sqrt(0));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_6) {
  ck_assert_double_eq(s21_sqrt(-0), sqrt(-0));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_7) {
  ck_assert_double_nan(s21_sqrt(-0.000001));
  ck_assert_double_nan(sqrt(-0.000001));
}
END_TEST

START_TEST(s21_sqrt_test_nan_inf_8) {
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(sqrt(S21_NAN));
}
END_TEST

// TEST_FOR_S21_CEIL

START_TEST(s21_ceil_test) {
  long double ceil_value[] = {0.00004,
                              -0.00004,
                              13567.00004,
                              99999999.999999,
                              -99999999.999999,
                              1.1,
                              -1.1,
                              2.1,
                              -2.1,
                              1.9,
                              -1.9,
                              2.9,
                              -2.9,
                              -0,
                              0,
                              1.999999,
                              -1.999999};
  for (int index = 0; index < 16; index++) {
    ck_assert_double_eq_tol(s21_ceil(ceil_value[index]),
                            ceil(ceil_value[index]), 0.000001);
  }
}
END_TEST

// TEST_FOR_S21_CEIL_WITH_NAN_AND_INF

START_TEST(s21_ceil_test_nan_inf) {
  ck_assert_double_eq(s21_ceil(S21_INF_POS), ceil(S21_INF_POS));
}
END_TEST

START_TEST(s21_ceil_test_nan_inf_2) {
  ck_assert_double_eq(s21_ceil(S21_INF_NEG), ceil(S21_INF_NEG));
}
END_TEST

START_TEST(s21_ceil_test_nan_inf_3) {
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_nan(ceil(S21_NAN));
}
END_TEST

// TEST_FOR_S21_FLOOR

START_TEST(s21_floor_test) {
  long double floor_value[] = {0.00004,
                               -0.00004,
                               13567.00004,
                               99999999.999999,
                               -99999999.999999,
                               1.1,
                               -1.1,
                               2.1,
                               -2.1,
                               1.9,
                               -1.9,
                               2.9,
                               -2.9,
                               -0,
                               0,
                               1.999999,
                               -1.999999};
  for (int index = 0; index < 16; index++) {
    ck_assert_double_eq(s21_floor(floor_value[index]),
                        floor(floor_value[index]));
  }
}
END_TEST

// TEST_FOR_S21_FLOOR_WITH_NAN_AND_INF

START_TEST(s21_floor_test_nan_inf) {
  ck_assert_double_eq(s21_floor(S21_INF_POS), floor(S21_INF_POS));
}
END_TEST

START_TEST(s21_floor_test_nan_inf_2) {
  ck_assert_double_eq(s21_floor(S21_INF_NEG), floor(S21_INF_NEG));
}
END_TEST

START_TEST(s21_floor_test_nan_inf_3) {
  ck_assert_double_nan(s21_floor(S21_NAN));
  ck_assert_double_nan(floor(S21_NAN));
}
END_TEST

// TEST_FOR_S21_SIN

START_TEST(s21_sin_test) {
  long double sin_value[] = {S21_PI,
                             -S21_PI,
                             0.001121101,
                             -0.001121101,
                             -2.322222,
                             2.322222,
                             12.00012345 * S21_PI,
                             S21_PI / 5,
                             -S21_PI / 5,
                             S21_PI / 2,
                             -S21_PI / 2,
                             2 * S21_PI,
                             -2 * S21_PI,
                             3 * S21_PI,
                             -3 * S21_PI,
                             0,
                             -0,
                             2 * S21_PI / 2,
                             -2 * S21_PI / 2,
                             3 * S21_PI / 2,
                             -3 * S21_PI / 2};

  for (int index = 0; index < 21; index++) {
    ck_assert_double_eq_tol(s21_sin(sin_value[index]), sin(sin_value[index]),
                            0.000001);
  }
}
END_TEST

// TEST_FOR_S21_SIN_WITH_NAN_AND_INF

START_TEST(s21_sin_test_nan_inf) {
  ck_assert_double_nan(s21_sin(1 / S21_INF_POS));
  ck_assert_double_nan(sin(1 / S21_INF_POS));
}
END_TEST

START_TEST(s21_sin_test_nan_inf_2) {
  ck_assert_double_nan(s21_sin(1 / S21_INF_NEG));
  ck_assert_double_nan(sin(1 / S21_INF_NEG));
}
END_TEST

START_TEST(s21_sin_test_nan_inf_3) {
  ck_assert_double_nan(s21_sin(S21_INF_POS));
  ck_assert_double_nan(sin(S21_INF_POS));
}
END_TEST

START_TEST(s21_sin_test_nan_inf_4) {
  ck_assert_double_nan(s21_sin(S21_INF_NEG));
  ck_assert_double_nan(sin(S21_INF_NEG));
}
END_TEST

START_TEST(s21_sin_test_nan_inf_5) {
  ck_assert_double_nan(s21_sin(S21_INF_NEG / 2));
  ck_assert_double_nan(sin(S21_INF_NEG / 2));
}
END_TEST

START_TEST(s21_sin_test_nan_inf_6) {
  ck_assert_double_nan(s21_sin(S21_INF_POS / 2));
  ck_assert_double_nan(sin(S21_INF_POS / 2));
}
END_TEST

// TEST_FOR_S21_COS

START_TEST(s21_cos_test) {
  long double cos_value[] = {S21_PI,
                             -S21_PI,
                             0.001121101,
                             -0.001121101,
                             -2.322222,
                             2.322222,
                             12.00012345 * S21_PI,
                             S21_PI / 5,
                             -S21_PI / 5,
                             S21_PI / 2,
                             -S21_PI / 2,
                             2 * S21_PI,
                             -2 * S21_PI,
                             3 * S21_PI,
                             -3 * S21_PI,
                             0,
                             -0,
                             2 * S21_PI / 2,
                             -2 * S21_PI / 2,
                             3 * S21_PI / 2,
                             -3 * S21_PI / 2};

  for (int index = 0; index < 21; index++) {
    ck_assert_double_eq_tol(s21_cos(cos_value[index]), cos(cos_value[index]),
                            0.000001);
  }
}
END_TEST

// TEST_FOR_S21_COS_WITH_NAN_AND_INF

START_TEST(s21_cos_test_nan_inf) {
  ck_assert_double_nan(s21_cos(S21_INF_POS));
  ck_assert_double_nan(cos(S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_2) {
  ck_assert_double_nan(s21_cos(S21_INF_NEG));
  ck_assert_double_nan(cos(S21_INF_NEG));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_3) {
  ck_assert_double_nan(s21_cos(2 / S21_INF_NEG));
  ck_assert_double_nan(cos(2 / S21_INF_NEG));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_4) {
  ck_assert_double_nan(s21_cos(2 / S21_INF_POS));
  ck_assert_double_nan(cos(2 / S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_5) {
  ck_assert_double_nan(s21_cos(1 / S21_INF_POS));
  ck_assert_double_nan(cos(1 / S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_6) {
  ck_assert_double_nan(s21_cos(-1 / S21_INF_POS));
  ck_assert_double_nan(cos(-1 / S21_INF_POS));
}
END_TEST

START_TEST(s21_cos_test_nan_inf_7) {
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(cos(S21_NAN));
}
END_TEST

// TEST_FOR_S21_TAN

START_TEST(s21_tan_test) {
  long double tan_value[] = {
      S21_PI,      -S21_PI,        0.001121101,          -0.001121101,
      -2.322222,   2.322222,       12.00012345 * S21_PI, S21_PI / 5,
      -S21_PI / 5, S21_PI / 2,     -S21_PI / 2,          2 * S21_PI,
      -2 * S21_PI, 3 * S21_PI,     -3 * S21_PI,          0,
      -0,          2 * S21_PI / 2, -2 * S21_PI / 2};
  for (int index = 0; index < 19; index++) {
    ck_assert_double_eq_tol(s21_tan(tan_value[index]), tan(tan_value[index]),
                            0.000001);
  }
}
END_TEST

// TEST_FOR_S21TAN_WITH_NAN_INF

START_TEST(s21_tan_test_nan_inf) {
  ck_assert_double_nan(s21_tan(S21_INF_POS));
  ck_assert_double_nan(tan(S21_INF_POS));
}
END_TEST

START_TEST(s21_tan_test_nan_inf_2) {
  ck_assert_double_nan(s21_tan(S21_INF_NEG));
  ck_assert_double_nan(tan(S21_INF_NEG));
}
END_TEST

START_TEST(s21_tan_test_nan_inf_3) {
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(tan(S21_NAN));
}
END_TEST

START_TEST(s21_tan_test_nan_inf_4) {
  ck_assert_double_nan(s21_tan(S21_INF_POS / 2));
  ck_assert_double_nan(tan(S21_INF_POS / 2));
}
END_TEST

START_TEST(s21_tan_test_nan_inf_5) {
  ck_assert_double_nan(s21_tan(S21_INF_NEG / 2));
  ck_assert_double_nan(tan(S21_INF_NEG / 2));
}
END_TEST

// TEST_FOR_S21_ATAN

START_TEST(s21_atan_test) {
  long double atan_value[] = {S21_PI,
                              -S21_PI,
                              0.001121101,
                              -0.001121101,
                              -2.322222,
                              2.322222,
                              12.00012345 * S21_PI,
                              S21_PI / 5,
                              -S21_PI / 5,
                              S21_PI / 2,
                              -S21_PI / 2,
                              2 * S21_PI,
                              -2 * S21_PI,
                              3 * S21_PI,
                              -3 * S21_PI,
                              0,
                              -0,
                              2 * S21_PI / 2,
                              -2 * S21_PI / 2,
                              3 * S21_PI / 2,
                              -3 * S21_PI / 2,
                              55.123456789,
                              -55.123456789,
                              10000000,
                              -10000000};

  for (int index = 0; index < 25; index++) {
    ck_assert_double_eq_tol(s21_atan(atan_value[index]),
                            atan(atan_value[index]), 0.000001);
  }
}
END_TEST

// TEST_FOR_S21_ATAN_NAN_INF

START_TEST(s21_atan_test_nan_inf) {
  ck_assert_double_eq_tol(s21_atan(S21_INF_POS), atan(S21_INF_POS), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_2) {
  ck_assert_double_eq_tol(s21_atan(S21_INF_NEG), atan(S21_INF_NEG), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_3) {
  ck_assert_double_eq_tol(s21_atan(S21_INF_POS / 2), atan(S21_INF_POS / 2),
                          0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_4) {
  ck_assert_double_eq_tol(s21_atan(S21_INF_NEG / 2), atan(S21_INF_NEG / 2),
                          0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_5) {
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_nan(atan(S21_NAN));
}
END_TEST

START_TEST(s21_atan_test_nan_inf_6) {
  ck_assert_double_eq_tol(s21_atan(614398691346.13461346),
                          atan(614398691346.13461346), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_7) {
  ck_assert_double_eq_tol(s21_atan(-614398691346.13461346),
                          atan(-614398691346.13461346), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_8) {
  ck_assert_double_eq_tol(s21_atan(4 * (1)), atan(4 * (1)), 0.000001);
}
END_TEST

START_TEST(s21_atan_test_nan_inf_9) {
  ck_assert_double_eq_tol(s21_atan(2 * (S21_INF_POS)), atan(2 * (S21_INF_POS)),
                          0.000001);
}
END_TEST

// TEST_FOR_S21_ASIN

START_TEST(s21_asin_test) {
  long double asin_value[] = {
      0.0, -0.0, 0.1,         -0.1,         0.2,        -0.2,       0.3, -0.3,
      0.4, -0.4, 0.5,         -0.5,         0.6,        -0.7,       0.8, -0.8,
      0.9, -0.9, 0.999991234, -0.999991234, S21_PI / 4, -S21_PI / 4};

  for (int index = 0; index < 22; index++) {
    ck_assert_double_eq_tol(s21_asin(asin_value[index]),
                            asin(asin_value[index]), 0.000001);
  }
}
END_TEST

// TEST_FOR_S21_ASIN_NAN_INF

START_TEST(s21_asin_test_nan_inf) {
  ck_assert_double_nan(s21_asin(S21_PI));
  ck_assert_double_nan(asin(S21_PI));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_2) {
  ck_assert_double_nan(s21_asin(S21_PI / 2));
  ck_assert_double_nan(asin(S21_PI / 2));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_3) {
  ck_assert_double_nan(s21_asin(2 * S21_PI / 5));
  ck_assert_double_nan(asin(2 * S21_PI / 5));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_4) {
  ck_assert_double_nan(s21_asin(S21_INF_POS));
  ck_assert_double_nan(asin(S21_INF_POS));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_5) {
  ck_assert_double_nan(s21_asin(S21_INF_NEG));
  ck_assert_double_nan(asin(S21_INF_NEG));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_6) {
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(asin(S21_NAN));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_7) {
  ck_assert_double_nan(s21_asin(-25));
  ck_assert_double_nan(asin(-25));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_8) {
  ck_assert_double_nan(s21_asin(25));
  ck_assert_double_nan(asin(25));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_9) {
  ck_assert_double_nan(s21_asin(98981234512.146143));
  ck_assert_double_nan(asin(98981234512.146143));
}
END_TEST

START_TEST(s21_asin_test_nan_inf_10) {
  ck_assert_double_nan(s21_asin(-98981234512.146143));
  ck_assert_double_nan(asin(-98981234512.146143));
}
END_TEST

// TEST_FOR_S21_ACOS

START_TEST(s21_acos_test) {
  long double acos_value[] = {
      0,
      -0,
      0.1,
      -0.1,
      0.2,
      -0.2,
      0.3,
      -0.3,
      0.4,
      -0.4,
      0.5,
      -0.5,
      0.6,
      -0.7,
      0.8,
      -0.8,
      0.9,
      -0.9,
      0.999991234,
      -0.999991234,
      S21_PI / 4,
      -S21_PI / 4,
      1,
      -1,
      0.12345678901234567890,
      -0.12345678901234567890,
  };

  for (int index = 0; index < 26; index++) {
    ck_assert_double_eq_tol(s21_acos(acos_value[index]),
                            acos(acos_value[index]), 0.000001);
  }
}
END_TEST

// TEST_FOR_S21_NAN_INF

START_TEST(s21_acos_test_nan_inf) {
  ck_assert_double_nan(s21_acos(S21_INF_POS));
  ck_assert_double_nan(acos(S21_INF_POS));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_2) {
  ck_assert_double_nan(s21_acos(S21_INF_NEG));
  ck_assert_double_nan(acos(S21_INF_NEG));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_3) {
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(acos(S21_NAN));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_4) {
  ck_assert_double_nan(s21_acos(S21_PI / 2));
  ck_assert_double_nan(acos(S21_PI / 2));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_5) {
  ck_assert_double_nan(s21_acos(-S21_PI / 2));
  ck_assert_double_nan(acos(-S21_PI / 2));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_6) {
  ck_assert_double_nan(s21_acos(-S21_PI));
  ck_assert_double_nan(acos(-S21_PI));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_7) {
  ck_assert_double_nan(s21_acos(-1.001));
  ck_assert_double_nan(acos(-1.001));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_8) {
  ck_assert_double_nan(s21_acos(1.001));
  ck_assert_double_nan(acos(1.001));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_9) {
  ck_assert_double_nan(s21_acos(-25));
  ck_assert_double_nan(acos(-25));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_10) {
  ck_assert_double_nan(s21_acos(25));
  ck_assert_double_nan(acos(25));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_11) {
  ck_assert_double_nan(s21_acos(4129568146146.145146));
  ck_assert_double_nan(acos(4129568146146.145146));
}
END_TEST

START_TEST(s21_acos_test_nan_inf_12) {
  ck_assert_double_nan(s21_acos(-4129568146146.145146));
  ck_assert_double_nan(acos(-4129568146146.145146));
}
END_TEST

// Suite for s21_floor

Suite *s21_floor_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("floor(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_floor_test);
  tcase_add_test(tc_core, s21_floor_test_nan_inf);
  tcase_add_test(tc_core, s21_floor_test_nan_inf_2);
  tcase_add_test(tc_core, s21_floor_test_nan_inf_3);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_ceil

Suite *s21_ceil_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("ceil(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_ceil_test);
  tcase_add_test(tc_core, s21_ceil_test_nan_inf);
  tcase_add_test(tc_core, s21_ceil_test_nan_inf_2);
  tcase_add_test(tc_core, s21_ceil_test_nan_inf_3);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_sqrt

Suite *s21_sqrt_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sqrt(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sqrt_test);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_2);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_3);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_4);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_5);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_6);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_7);
  tcase_add_test(tc_core, s21_sqrt_test_nan_inf_8);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_exp

Suite *s21_exp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("exp(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_exp_test);
  tcase_add_test(tc_core, s21_exp_test_nan_inf);
  tcase_add_test(tc_core, s21_exp_test_nan_inf2);
  tcase_add_test(tc_core, s21_exp_test_nan_inf3);
  tcase_add_test(tc_core, s21_exp_test_nan_inf4);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_abs

Suite *s21_abs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("abs(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_abs_test);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_fact

Suite *s21_fact_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("factorial(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_factorial_test);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_fabs

Suite *s21_fabs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fabs(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_fabs_test);
  tcase_add_test(tc_core, s21_fabs_test_nan_inf);
  tcase_add_test(tc_core, s21_fabs_test_nan_inf2);
  tcase_add_test(tc_core, s21_fabs_test_nan_inf3);
  tcase_add_test(tc_core, s21_fabs_test_nan_inf4);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_fmod

Suite *s21_fmod_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fmod(x,y)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_fmod_test);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf2);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf3);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf4);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf5);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf6);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf7);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf8);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf9);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf10);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf11);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf12);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf13);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf14);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf15);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf16);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf17);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf18);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf19);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf20);
  tcase_add_test(tc_core, s21_fmod_test_nan_inf21);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_log

Suite *s21_log_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("log(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_log_test);
  tcase_add_test(tc_core, s21_log_test_main);
  tcase_add_test(tc_core, s21_log_test_nan_inf);
  tcase_add_test(tc_core, s21_log_test_nan_inf2);
  tcase_add_test(tc_core, s21_log_test_nan_inf3);
  tcase_add_test(tc_core, s21_log_test_nan_inf4);
  tcase_add_test(tc_core, s21_log_test_nan_inf5);
  tcase_add_test(tc_core, s21_log_test_nan_inf6);
  tcase_add_test(tc_core, s21_log_test_nan_inf7);
  tcase_add_test(tc_core, s21_log_test_nan_inf8);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_pow

Suite *s21_pow_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("pow(base, exp)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_pow_test);
  tcase_add_test(tc_core, s21_pow_test_nan_inf);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_2);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_3);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_4);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_5);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_6);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_7);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_8);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_9);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_10);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_11);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_12);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_13);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_14);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_15);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_16);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_17);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_18);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_19);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_20);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_21);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_22);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_23);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_24);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_25);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_26);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_27);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_28);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_29);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_30);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_31);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_32);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_33);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_34);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_35);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_36);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_37);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_38);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_39);
  tcase_add_test(tc_core, s21_pow_test_nan_inf_40);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_sin

Suite *s21_sin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sin(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_sin_test);
  tcase_add_test(tc_core, s21_sin_test_nan_inf);
  tcase_add_test(tc_core, s21_sin_test_nan_inf_2);
  tcase_add_test(tc_core, s21_sin_test_nan_inf_3);
  tcase_add_test(tc_core, s21_sin_test_nan_inf_4);
  tcase_add_test(tc_core, s21_sin_test_nan_inf_5);
  tcase_add_test(tc_core, s21_sin_test_nan_inf_6);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_cos

Suite *s21_cos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("cos(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_cos_test);
  tcase_add_test(tc_core, s21_cos_test_nan_inf);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_2);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_3);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_4);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_5);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_6);
  tcase_add_test(tc_core, s21_cos_test_nan_inf_7);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_tan

Suite *s21_tan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("tan(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_tan_test);
  tcase_add_test(tc_core, s21_tan_test_nan_inf);
  tcase_add_test(tc_core, s21_tan_test_nan_inf_2);
  tcase_add_test(tc_core, s21_tan_test_nan_inf_3);
  tcase_add_test(tc_core, s21_tan_test_nan_inf_4);
  tcase_add_test(tc_core, s21_tan_test_nan_inf_5);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_atan

Suite *s21_atan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("atan(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_atan_test);
  tcase_add_test(tc_core, s21_atan_test_nan_inf);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_2);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_3);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_4);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_5);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_6);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_7);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_8);
  tcase_add_test(tc_core, s21_atan_test_nan_inf_9);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_asin

Suite *s21_asin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("asin(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_asin_test);
  tcase_add_test(tc_core, s21_asin_test_nan_inf);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_2);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_3);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_4);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_5);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_6);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_7);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_8);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_9);
  tcase_add_test(tc_core, s21_asin_test_nan_inf_10);
  suite_add_tcase(s, tc_core);
  return s;
}

// Suite for s21_acos

Suite *s21_acos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("acos(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, s21_acos_test);
  tcase_add_test(tc_core, s21_acos_test_nan_inf);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_2);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_3);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_4);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_5);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_6);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_7);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_8);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_9);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_10);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_11);
  tcase_add_test(tc_core, s21_acos_test_nan_inf_12);
  suite_add_tcase(s, tc_core);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int failed = 0;
  case_test(s21_fact_suite(), &failed);
  case_test(s21_abs_suite(), &failed);
  case_test(s21_fabs_suite(), &failed);
  case_test(s21_fmod_suite(), &failed);
  case_test(s21_exp_suite(), &failed);
  case_test(s21_log_suite(), &failed);
  case_test(s21_pow_suite(), &failed);
  case_test(s21_sqrt_suite(), &failed);
  case_test(s21_floor_suite(), &failed);
  case_test(s21_ceil_suite(), &failed);
  case_test(s21_sin_suite(), &failed);
  case_test(s21_cos_suite(), &failed);
  case_test(s21_tan_suite(), &failed);
  case_test(s21_atan_suite(), &failed);
  case_test(s21_asin_suite(), &failed);
  case_test(s21_acos_suite(), &failed);
  return failed;
}
