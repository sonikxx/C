#include "tests_suitcases.h"

START_TEST(div_test_1) {
  s21_decimal a = {0};
  s21_decimal b = {0};
  s21_decimal res_dec = {0};
  s21_div(a, b, &res_dec);
  ck_assert_int_eq(res_dec.bits[0], 0);
}
END_TEST

Suite *suite_div(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_div");
  tc = tcase_create("case_div");

  tcase_add_test(tc, div_test_1);
  suite_add_tcase(s, tc);
  return s;
}
