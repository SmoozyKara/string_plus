#include "test.h"

// 1. базовый случай
START_TEST(strncat_test_basic) {
  char custom[50] = "Hello World";
  char orig[50] = "Hello World";
  const char* tmp = "ZMP";
  ck_assert_ptr_eq(_strncat(custom, tmp, 3), custom);
  strncat(orig, tmp, 3);

  ck_assert_str_eq(custom, orig);
}
END_TEST

// 2. добавление в пустые строки
START_TEST(strncat_test_empty_strings) {
  char custom[50] = "";
  char orig[50] = "";
  const char* tmp = "ZMP";
  ck_assert_ptr_eq(_strncat(custom, tmp, 3), custom);
  strncat(orig, tmp, 3);

  ck_assert_str_eq(custom, orig);
}
END_TEST

// 3. добавление пустой строки
START_TEST(strncat_test_add_empty_str) {
  char custom[50] = "Hello World!";
  char orig[50] = "Hello World!";
  const char* tmp = "";
  ck_assert_ptr_eq(_strncat(custom, tmp, 5), custom);
  strncat(orig, tmp, 5);

  ck_assert_str_eq(custom, orig);
}
END_TEST

// 4. добавление пустой строки
START_TEST(strncat_test_add_end_of_str) {
  char custom[50] = "Hello World!";
  char orig[50] = "Hello World!";
  const char* tmp = "\0\0\0\0\0";
  ck_assert_ptr_eq(_strncat(custom, tmp, 5), custom);
  strncat(orig, tmp, 5);

  ck_assert_str_eq(custom, orig);
}
END_TEST

// 5. n больше длины копируемой строки
START_TEST(strncat_test_n_greater_than_src) {
  char custom[50] = "Hello ";
  char orig[50] = "Hello ";
  const char* tmp = "World";

  ck_assert_ptr_eq(_strncat(custom, tmp, 10), custom);
  strncat(orig, tmp, 10);

  ck_assert_str_eq(custom, orig);
}
END_TEST

// 6. Игнор символов после первого \0
START_TEST(strncat_test_ignore_data_after_null) {
  char custom[50] = "Hello\0XXXXXXXXX";
  char orig[50] = "Hello\0XXXXXXXXX";
  const char* tmp = " World";

  ck_assert_ptr_eq(_strncat(custom, tmp, 6), custom);
  strncat(orig, tmp, 6);

  ck_assert_str_eq(custom, orig);
}
END_TEST
// Создаем TCase для strncat и упаковываем в него все тесты
TCase* tcase_strncat(void) {
  TCase* tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strncat_test_basic);
  tcase_add_test(tc, strncat_test_empty_strings);
  tcase_add_test(tc, strncat_test_add_empty_str);
  tcase_add_test(tc, strncat_test_add_end_of_str);
  tcase_add_test(tc, strncat_test_n_greater_than_src);
  tcase_add_test(tc, strncat_test_ignore_data_after_null);

  return tc;
}