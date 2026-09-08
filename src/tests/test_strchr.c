#include "test.h"

// 1. базовый случай
START_TEST(strchr_test_basic) {
  char str[] = "Hello World";

  ck_assert_ptr_eq(_strchr(str, 'W'), strchr(str, 'W'));
}
END_TEST

// 2. Несуществующий символ
START_TEST(strchr_test_unknown_symb) {
  char str[] = "Hello World";

  ck_assert_ptr_eq(_strchr(str, 'p'), strchr(str, 'p'));
}
END_TEST

// 3. Поисе символа конца строки
START_TEST(strchr_test_end_symb) {
  char str[] = "Hello World";

  ck_assert_ptr_eq(_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

// 4. Поиск в пустой строке
START_TEST(strchr_test_empty_string) {
  char str[] = "";

  ck_assert_ptr_eq(_strchr(str, '0'), strchr(str, '0'));
}
END_TEST

// 5. Передача большого int
START_TEST(strchr_test_big_int) {
  char str[] = "Hello world!";

  ck_assert_ptr_eq(_strchr(str, 1e9), strchr(str, 1e9));
}
END_TEST

// 6. Множественное вхождение символа
START_TEST(strchr_test_multiple_chars) {
  char str[] = "abracadabra";

  ck_assert_ptr_eq(_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

// 7. Поиск \0 в пустой строке
START_TEST(strchr_test_find_null_in_empty) {
  char str[] = "";

  ck_assert_ptr_eq(_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

// Создаем TCase для strncat и упаковываем в него все тесты
TCase* tcase_strchr(void) {
  TCase* tc = tcase_create("strncat_tc");

  tcase_add_test(tc, strchr_test_basic);
  tcase_add_test(tc, strchr_test_unknown_symb);
  tcase_add_test(tc, strchr_test_end_symb);
  tcase_add_test(tc, strchr_test_empty_string);
  tcase_add_test(tc, strchr_test_big_int);
  tcase_add_test(tc, strchr_test_multiple_chars);
  tcase_add_test(tc, strchr_test_find_null_in_empty);
  return tc;
}