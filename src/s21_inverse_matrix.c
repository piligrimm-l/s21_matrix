#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_value = OK;
  if (is_correct_mat(A)) {
    return_value = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return_value = CALCULATION_ERROR;
  } else {
    matrix_t matrix = {0};
    matrix_t transp_matrix = {0};
    double determinant = 0.0;
    s21_determinant(A, &determinant);
    if (determinant) {
      return_value = s21_calc_complements(A, &matrix);
      if (!return_value) {
        return_value = s21_transpose(&matrix, &transp_matrix);
        if (!return_value) {
          return_value = s21_mult_number(&transp_matrix,
                                         (1.0 / (double)determinant), result);
          s21_remove_matrix(&transp_matrix);
        }
        s21_remove_matrix(&matrix);
      }
    } else {
      return_value = CALCULATION_ERROR;
    }
  }
  return return_value;
}
