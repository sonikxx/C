#include "../s21_matrix.h"

void s21_matrix_for_minor(matrix_t *A, matrix_t *result, int i, int j) {
  s21_create_matrix(A->rows - 1, A->columns - 1, result);
  int ki, kj;
  ki = 0;
  for (int new_i = 0; new_i < result->rows; ++new_i) {
    kj = 0;
    if (new_i == i) ki = 1;
    for (int new_j = 0; new_j < result->columns; ++new_j) {
      if (new_j == j) kj = 1;
      if ((new_i + ki <= result->rows) && (new_j + kj <= result->columns)) {
        result->matrix[new_i][new_j] = A->matrix[new_i + ki][new_j + kj];
      }
    }
  }
}