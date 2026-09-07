#include "test.h"

// 1. Зануление строки
START_TEST(strncat_test_basic) {
  // Выделяем массив на 50 байт, чтобы точно хватило места
  char custom[50] = "Hello World";
  char orig[50] = "Hello World";
  const char* tmp = "ZMP";
  ck_assert_ptr_eq(_strncat(custom, tmp, 3), custom);
  strncat(orig, tmp, 3);

  ck_assert_int_eq(memcmp(custom, orig, strlen(orig)), 0);
}
END_TEST

// Создаем TCase для strncat и упаковываем в него все тесты
TCase* tcase_strncat(void) {
  TCase* tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strncat_test_basic);

  return tc;
}