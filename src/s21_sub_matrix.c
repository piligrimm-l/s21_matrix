#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = OK;
  if (is_correct_mat(A) || is_correct_mat(B)) {
    return_value = INCORRECT_MATRIX;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    return_value = CALCULATION_ERROR;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    if (!return_value) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          double element = A->matrix[i][j] - B->matrix[i][j];
          if (!isfinite(element)) {
            return_value = CALCULATION_ERROR;
          } else if (!return_value) {
            result->matrix[i][j] = element;
          }
        }
      }
    }
  }
  return return_value;
}
