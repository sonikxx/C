#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_bad_matrix(A) == 1) return INCORRECT_MATRIX;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < result->rows; ++i) {
    for (int j = 0; j < result->columns; ++j) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
  return OK;
}