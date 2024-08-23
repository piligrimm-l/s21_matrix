#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int return_value = OK;
  if (!result || rows < 1 || columns < 1) {
    return_value = INCORRECT_MATRIX;
  } else {
    double** matrix = calloc(rows, sizeof(double*));
    if (!matrix) {
      return_value = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows; ++i) {
        matrix[i] = calloc(columns, sizeof(double*));
        if (!matrix[i]) {
          return_value = INCORRECT_MATRIX;
        }
      }
    }
    result->matrix = matrix;
    result->columns = columns;
    result->rows = rows;
  }
  return return_value;
}
