// TODO ДОБАВИТЬ ТЕСТОВ

#include "test.h"

// 1. базовый случай
START_TEST(strncpy_test_basic) {
  char custom[50] = "Hello World";
  char orig[50] = "Hello World";
  char word[50] = "TMP";

  ck_assert_ptr_eq(custom, _strncpy(custom, word, 3));
  strncpy(orig, word, 3);
  ck_assert_str_eq(custom, orig);
}
END_TEST

TCase* tcase_strncpy(void) {
  TCase* tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_test_basic);
  return tc;
}