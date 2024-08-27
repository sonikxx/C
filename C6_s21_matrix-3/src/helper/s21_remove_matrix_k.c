#include "../s21_matrix.h"

void s21_remove_matrix_k(matrix_t *A, int k) {
  for (int i = 0; i < k; ++i) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}