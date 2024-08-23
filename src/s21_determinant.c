#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_value = OK;
  if (is_correct_mat(A) || !result) {
    return_value = INCORRECT_MATRIX;
  } else if (A->columns != A->rows) {
    return_value = CALCULATION_ERROR;
  } else {
    if (A->columns == 1)
      *result = A->matrix[0][0];
    else if (A->columns == 2)
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    else {
      for (int col = 0; col < A->columns; ++col) {
        long double cur_number = A->matrix[0][col];
        int sign = (col % 2 == 0) ? 1 : -1;
        *result +=
            cur_number ? sign * cur_number * s21_get_minor(A, 0, col) : 0;
      }
    }
  }
  return return_value;
}
