#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  if ((is_correct_mat(A))) {
    return_value = INCORRECT_MATRIX;
  } else {
    return_value = s21_create_matrix(A->columns, A->rows, result);
    if (!return_value) {
      for (int j = 0; j < A->columns; ++j) {
        for (int i = 0; i < A->rows; ++i) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  }
  return return_value;
}
