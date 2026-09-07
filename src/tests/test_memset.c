#include "test.h"

// 1. Зануление строки
START_TEST(memset_test_basic) {
  char str[] = "Hello world!";

  char custom[strlen(str)];
  char orig[strlen(str)];

  ck_assert_ptr_eq(_memset(custom, 0, strlen(str)), custom);
  memset(orig, 0, strlen(str));

  ck_assert_int_eq(memcmp(custom, orig, strlen(str)), 0);
}
END_TEST

// 2. Зануление обычного числового массива
START_TEST(memset_test_zerofication_intarr) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  int custom[sizeof(arr)];
  int orig[sizeof(arr)];

  ck_assert_ptr_eq(_memset(custom, 0, sizeof(arr)), custom);
  memset(orig, 0, sizeof(arr));

  ck_assert_int_eq(memcmp(custom, orig, sizeof(arr)), 0);
}
END_TEST

// 3. Зануление пустого массива
START_TEST(memset_test_empty_arr) {
  int arr[] = {};

  int custom[sizeof(arr)];
  int orig[sizeof(arr)];

  ck_assert_ptr_eq(_memset(custom, 0, sizeof(arr)), custom);
  memset(orig, 0, sizeof(arr));

  ck_assert_int_eq(memcmp(custom, orig, sizeof(arr)), 0);
}
END_TEST

// 4. Запробеливание строки
START_TEST(memset_test_space_str) {
  char str[] = "Hello world!";

  char custom[strlen(str)];
  char orig[strlen(str)];

  ck_assert_ptr_eq(_memset(custom, ' ', strlen(str)), custom);
  memset(orig, ' ', strlen(str));

  ck_assert_int_eq(memcmp(custom, orig, strlen(str)), 0);
}
END_TEST

// 5. Частичное заполнение (Проверка границ)
START_TEST(memset_test_partial) {
  char custom[15] = "XXXXXXXXXXXXXX";
  char orig[15] = "XXXXXXXXXXXXXX";

  // Меняем только первые 5 байт
  ck_assert_ptr_eq(_memset(custom, 'A', 5), custom);
  memset(orig, 'A', 5);

  // Сравниваем ВЕСЬ массив, чтобы убедиться, что хвосты не задеты
  ck_assert_int_eq(memcmp(custom, orig, 15), 0);
}
END_TEST

// 6. Преобразование типа (int -> unsigned char)
START_TEST(memset_test_unsigned_char_conversion) {
  char custom[10] = {0};
  char orig[10] = {0};

  // Передаем число, которое больше 1 байта (257)
  int filler = 257;

  ck_assert_ptr_eq(_memset(custom, filler, 5), custom);
  memset(orig, filler, 5);

  ck_assert_int_eq(memcmp(custom, orig, 10), 0);
}
END_TEST

// 7. Заполнение 0 байт на непустом массиве
START_TEST(memset_test_zero_bytes) {
  char custom[10] = "123456789";
  char orig[10] = "123456789";

  // Просим заменить 0 байт
  ck_assert_ptr_eq(_memset(custom, 'A', 0), custom);
  memset(orig, 'A', 0);

  ck_assert_int_eq(memcmp(custom, orig, 10), 0);
}
END_TEST

// Создаем TCase и упаковываем в него все тесты
TCase* tcase_memset(void) {
  TCase* tc = tcase_create("memset_tc");

  tcase_add_test(tc, memset_test_basic);
  tcase_add_test(tc, memset_test_zerofication_intarr);
  tcase_add_test(tc, memset_test_empty_arr);
  tcase_add_test(tc, memset_test_space_str);
  tcase_add_test(tc, memset_test_partial);
  tcase_add_test(tc, memset_test_unsigned_char_conversion);
  tcase_add_test(tc, memset_test_zero_bytes);

  return tc;
}