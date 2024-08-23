#include "test.h"

START_TEST(s21_create_matrix_1) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(7, 7, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  ck_assert_int_eq(s21_create_matrix(7, 7, NULL), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(7, 0, &A), INCORRECT_MATRIX);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t A = {};
  ck_assert_int_eq(s21_create_matrix(0, 7, &A), INCORRECT_MATRIX);
}
END_TEST

Suite *test_create_matrix(void) {
  Suite *s = suite_create("\033[45m-=s21_create_matrix=-\033[0m");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_create_matrix_1);
  tcase_add_test(tc_core, s21_create_matrix_2);
  tcase_add_test(tc_core, s21_create_matrix_3);
  tcase_add_test(tc_core, s21_create_matrix_4);
  suite_add_tcase(s, tc_core);

  return s;
}
