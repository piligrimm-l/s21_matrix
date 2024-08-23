#include "s21_matrix.h"

void s21_init_matrix(matrix_t *A, double start_value, double iteration_step) {
  if (A && A->matrix) {
    double element = start_value;
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        A->matrix[i][j] = element;
        element += iteration_step;
      }
    }
  }
}
