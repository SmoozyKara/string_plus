#include "test.h"

// 1. базовый случай
START_TEST(strchr_test_basic) {
  char str[] = "Hello World";

  ck_assert_ptr_eq(_strchr(str, 'W'), strchr(str, 'W'));
}
END_TEST

// Создаем TCase для strncat и упаковываем в него все тесты
TCase* tcase_strchr(void) {
  TCase* tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strchr_test_basic);

  return tc;
}