#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;
  if (is_correct_mat(A) || is_correct_mat(B)) {
    return_value = FAILURE;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    return_value = FAILURE;
  } else {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
          return_value = FAILURE;
        }
      }
    }
  }
  return return_value;
}
