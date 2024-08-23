#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_value = OK;
  if (is_correct_mat(A) || is_correct_mat(B)) {
    return_value = INCORRECT_MATRIX;
  } else if (A->columns != B->rows) {
    return_value = CALCULATION_ERROR;
  } else {
    return_value = s21_create_matrix(A->rows, B->columns, result);
    if (!return_value) {
      for (int i = 0; i < result->rows; ++i) {
        for (int j = 0; j < result->columns; ++j) {
          double element = 0.0;
          for (int k = 0; k < A->columns; ++k) {
            element += A->matrix[i][k] * B->matrix[k][j];
          }
          if (isinf(fabs(element)) || isnan(fabs(element))) {
            return_value = CALCULATION_ERROR;
          }
          if (!return_value) result->matrix[i][j] = element;
        }
      }
    }
  }
  return return_value;
}
