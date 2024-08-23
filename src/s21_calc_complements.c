#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_value = s21_create_matrix(A->rows, A->columns, result);
  if (return_value == 0) {
    if (A->columns != A->rows || A->rows == 0) {
      return_value = CALCULATION_ERROR;
    } else {
      if (A->columns == 1)
        result->matrix[0][0] = 1;
      else if (A->columns == 2) {
        result->matrix[0][0] = A->matrix[1][1];
        result->matrix[0][1] = -A->matrix[1][0];
        result->matrix[1][0] = -A->matrix[0][1];
        result->matrix[1][1] = A->matrix[0][0];
      } else {
        for (int i = 0; i < result->rows; ++i) {
          for (int j = 0; j < result->columns; ++j) {
            int sign = (i + j) % 2 == 1 ? -1 : 1;
            result->matrix[i][j] = s21_get_minor(A, i, j) * sign;
          }
        }
      }
    }
  }
  return return_value;
}
