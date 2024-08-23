#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_value = OK;
  if (is_correct_mat(A)) {
    return_value = INCORRECT_MATRIX;
  } else {
    return_value = s21_create_matrix(A->rows, A->columns, result);
    if (!return_value) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          double element = A->matrix[i][j] * number;
          if (isinf(fabs(element)) || isnan(fabs(element))) {
            return_value = CALCULATION_ERROR;
          }
          if (!return_value) {
            result->matrix[i][j] = element;
          }
        }
      }
    }
  }
  return return_value;
}
