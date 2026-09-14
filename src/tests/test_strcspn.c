// TODO ДОБАВИТЬ ТЕСТОВ

#include "test.h"

// 1. базовый случай
START_TEST(strcspn_test_basic) {
  char custom[50] = "Hello World";
  char orig[50] = "HelZo World";

  ck_assert_int_eq(_strcspn(custom, orig), strcspn(custom, orig));
}
END_TEST

TCase* tcase_strcspn(void) {
  TCase* tc = tcase_create("strcspn_tc");

  tcase_add_test(tc, strcspn_test_basic);
  return tc;
}