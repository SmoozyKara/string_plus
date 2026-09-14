// TODO ДОБАВИТЬ ТЕСТОВ

#include "test.h"

// 1. базовый случай
START_TEST(strlen_test_basic) {
  char custom[50] = "Hello World";

  ck_assert_int_eq(_strlen(custom), strlen(custom));
}
END_TEST

TCase* tcase_strlen(void) {
  TCase* tc = tcase_create("strlen_tc");

  tcase_add_test(tc, strlen_test_basic);
  return tc;
}