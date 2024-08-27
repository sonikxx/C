#include "../s21_matrix.h"

int s21_bad_matrix(matrix_t* A) {
  int status = 0;
  if (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0)
    status = 1;
  return status;
}