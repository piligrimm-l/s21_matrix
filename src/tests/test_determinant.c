#include "test.h"

START_TEST(s21_determinant_1) {
  matrix_t A = {};
  double determinant = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &determinant), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(3, 2, &A);
  s21_init_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &determinant), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(3, 3, &A);
  s21_init_matrix(&A, 1, 1);
  ck_assert_int_eq(s21_determinant(&A, &determinant), OK);
  ck_assert_double_eq(determinant, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(2, 2, &A);
  s21_init_matrix(&A, 3, 3);
  ck_assert_int_eq(s21_determinant(&A, &determinant), OK);
  ck_assert_double_eq(determinant, -18.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 21;
  ck_assert_int_eq(s21_determinant(&A, &determinant), OK);
  ck_assert_double_eq(determinant, 21.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3;
  ck_assert_int_eq(s21_determinant(&A, &determinant), OK);
  ck_assert_double_eq(determinant, -1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t A = {};
  double determinant = 0.0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 2, A.matrix[0][1] = 5, A.matrix[0][2] = 7,
  A.matrix[0][3] = 1;
  A.matrix[1][0] = 6, A.matrix[1][1] = 3, A.matrix[1][2] = 4,
  A.matrix[1][3] = 1;
  A.matrix[2][0] = 5, A.matrix[2][1] = -2, A.matrix[2][2] = -3,
  A.matrix[2][3] = 1;
  A.matrix[3][0] = 1, A.matrix[3][1] = 1, A.matrix[3][2] = 1,
  A.matrix[3][3] = 1;
  ck_assert_int_eq(s21_determinant(&A, &determinant), OK);
  ck_assert_double_eq(determinant, -9);
  s21_remove_matrix(&A);
}
END_TEST

Suite *test_determinant(void) {
  Suite *s = suite_create("\033[45m-=s21_determinant=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  tcase_add_test(tc_core, s21_determinant_6);
  tcase_add_test(tc_core, s21_determinant_7);
  suite_add_tcase(s, tc_core);

  return s;
}
