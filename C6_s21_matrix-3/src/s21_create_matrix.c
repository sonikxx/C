#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1) return INCORRECT_MATRIX;
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)calloc(result->rows, sizeof(double *));
  if (result->matrix == NULL) return CALCULATION_ERROR;
  for (int i = 0; i < result->rows; ++i) {
    result->matrix[i] = (double *)calloc(result->columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      for (int k = 0; k <= i; ++k) {
        s21_remove_matrix_k(result, k);
      }
      return CALCULATION_ERROR;
    }
  }
  return OK;
}