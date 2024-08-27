#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (s21_bad_matrix(A) == 1) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    for (int i = 0; i < result->rows; ++i) {
      for (int j = 0; j < result->columns; ++j) {
        matrix_t new;
        s21_matrix_for_minor(A, &new, i, j);
        double minor;
        s21_determinant(&new, &minor);
        result->matrix[i][j] = pow(-1, i + j) * minor;
        s21_remove_matrix(&new);
      }
    }
  }
  return OK;
}