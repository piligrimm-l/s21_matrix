#include "s21_matrix.h"

int is_correct_mat(const matrix_t *A) {
  int return_value = OK;
  if (!A || !A->matrix || A->columns < 1 || A->rows < 1) {
    return_value = INCORRECT_MATRIX;
  }
  return return_value;
}
