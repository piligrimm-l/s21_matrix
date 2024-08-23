#include "s21_matrix.h"

double s21_get_minor(matrix_t* A, int row, int col) {
  double result = 0.0;
  if (is_correct_mat(A)) {
    result = 0;
  } else {
    matrix_t minor = {};
    s21_create_matrix(A->rows - 1, A->rows - 1, &minor);
    for (int r = 0, res_r = 0; r <= minor.rows; ++r) {
      if (r == row) continue;
      for (int c = 0, res_c = 0; c <= minor.columns; ++c) {
        if (c == col) continue;
        minor.matrix[res_r][res_c] = A->matrix[r][c];
        res_c++;
      }
      res_r++;
    }
    if (minor.rows == 2) {
      result = minor.matrix[0][0] * minor.matrix[1][1] -
               minor.matrix[0][1] * minor.matrix[1][0];
    } else {
      for (int i = 0; i < minor.columns; ++i) {
        int sign = (i % 2) == 1 ? -1 : 1;
        double value = minor.matrix[0][i];
        result += sign * value * s21_get_minor(&minor, 0, i);
      }
    }
    s21_remove_matrix(&minor);
  }
  return result;
}
