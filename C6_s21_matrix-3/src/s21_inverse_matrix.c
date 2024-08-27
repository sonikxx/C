#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (s21_bad_matrix(A) == 1) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1.0 / A->matrix[0][0];
    return OK;
  }
  double det = 0;
  int status = s21_determinant(A, &det);
  if (det == 0 || status != OK) return CALCULATION_ERROR;
  matrix_t new_1;
  // s21_create_matrix(A->rows, A->columns, &new_1);
  s21_calc_complements(A, &new_1);
  matrix_t new_2;
  // s21_create_matrix(A->rows, A->columns, &new_2);
  s21_transpose(&new_1, &new_2);
  s21_mult_number(&new_2, 1 / det, result);
  s21_remove_matrix(&new_1);
  s21_remove_matrix(&new_2);
  return OK;
}
