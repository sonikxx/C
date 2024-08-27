#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (s21_bad_matrix(A) == 1) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;
  if (A->rows == 1) *result = A->matrix[0][0];
  if (A->rows == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  if (A->rows > 2) *result = s21_calc_determinant(A);
  return OK;
}