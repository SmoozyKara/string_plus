#include "test.h"

// 1. Поиск символа в середине строки
START_TEST(memchr_test_basic) {
  char str[] = "Hello, School 21!";
  ck_assert_ptr_eq(s21_memchr(str, 'S', strlen(str)),
                   memchr(str, 'S', strlen(str)));
}
END_TEST

// 2. Символ не найден
START_TEST(memchr_test_not_found) {
  char str[] = "Hello, School 21!";
  ck_assert_ptr_eq(s21_memchr(str, 'z', strlen(str)),
                   memchr(str, 'z', strlen(str)));
}
END_TEST

// 3. Поиск терминального нуля (\0)
START_TEST(memchr_test_find_zero) {
  char str[] = "Hello";
  // Передаем n = 6, чтобы захватить невидимый \0 в конце
  ck_assert_ptr_eq(s21_memchr(str, '\0', 6), memchr(str, '\0', 6));
}
END_TEST

// 4. Длина поиска n = 0 (должен вернуть NULL, не заходя в память)
START_TEST(memchr_test_zero_length) {
  char str[] = "Hello";
  ck_assert_ptr_eq(s21_memchr(str, 'H', 0), memchr(str, 'H', 0));
}
END_TEST

// 5. Поиск первого символа (проверка границ)
START_TEST(memchr_test_first_char) {
  char str[] = "Hello";
  ck_assert_ptr_eq(s21_memchr(str, 'H', strlen(str)),
                   memchr(str, 'H', strlen(str)));
}
END_TEST

// 6. Поиск символа, который встречается несколько раз (должен найти первый)
START_TEST(memchr_test_multiple_occurrences) {
  char str[] = "abracadabra";
  ck_assert_ptr_eq(s21_memchr(str, 'a', strlen(str)),
                   memchr(str, 'a', strlen(str)));
}
END_TEST

// 7. Работа с "сырыми" байтами и отрицательными значениями (проверка unsigned
// char)
START_TEST(memchr_test_binary_data) {
  unsigned char data[] = {0x01, 0xFF, 0x03, 0x4A};
  // Ищем байт 255 (0xFF)
  ck_assert_ptr_eq(s21_memchr(data, 0xFF, 4), memchr(data, 0xFF, 4));
}
END_TEST

// Создаем TCase для memchr и упаковываем в него все тесты
TCase* tcase_memchr(void) {
  TCase* tc = tcase_create("memchr_tc");

  tcase_add_test(tc, memchr_test_basic);
  tcase_add_test(tc, memchr_test_not_found);
  tcase_add_test(tc, memchr_test_find_zero);
  tcase_add_test(tc, memchr_test_zero_length);
  tcase_add_test(tc, memchr_test_first_char);
  tcase_add_test(tc, memchr_test_multiple_occurrences);
  tcase_add_test(tc, memchr_test_binary_data);

  return tc;
}