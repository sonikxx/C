#include "../s21_matrix.h"

double s21_calc_determinant(matrix_t *A) {
  if (A->rows == 1) return A->matrix[0][0];
  double result = 0;
  for (int i = 0; i < A->rows; ++i) {
    matrix_t new;
    s21_matrix_for_minor(A, &new, 0, i);
    result += pow(-1, i) * A->matrix[0][i] * s21_calc_determinant(&new);
    s21_remove_matrix(&new);
  }
  return result;
}