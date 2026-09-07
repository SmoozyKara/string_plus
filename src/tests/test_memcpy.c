#include "test.h"

// 1. Одинаковые строки
START_TEST(memcpy_test_basic) {
  const char src[] = "Hello!";
  size_t n = strlen(src) + 1;  // +1 для '\0'

  char dst_custom[10] = {0};
  char dst_original[10] = {0};

  // 1. Кастом. функция возвращает оригинальный указатель
  ck_assert_ptr_eq(_memcpy(dst_custom, src, n), dst_custom);

  memcpy(dst_original, src, n);

  // 2. Сравниваем: действительно ли байты скопировались?
  ck_assert_int_eq(memcmp(dst_custom, dst_original, n), 0);
}
END_TEST

// 2. Числовой массив
START_TEST(memcpy_test_int_arr) {
  const int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  size_t N = sizeof(src);

  int dst_custom[10] = {0};
  int dst_original[10] = {0};

  ck_assert_ptr_eq(_memcpy(dst_custom, src, N), dst_custom);

  memcpy(dst_original, src, N);

  ck_assert_int_eq(memcmp(dst_custom, dst_original, N), 0);
}
END_TEST

// 3. Пустой размер
START_TEST(memcpy_test_empty_size) {
  const int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  size_t N = 0;

  int dst_custom[10] = {0};
  int dst_original[10] = {0};

  ck_assert_ptr_eq(_memcpy(dst_custom, src, N), dst_custom);

  memcpy(dst_original, src, N);

  ck_assert_int_eq(memcmp(dst_custom, dst_original, N), 0);
}
END_TEST

// 4. Перезапишем уже существующий массив
START_TEST(memcpy_test_overwrite) {
  const char src[] = {"Hello"};

  char dst_custom[] = {"ABCDEFGH"};
  char dst_original[] = {"ABCDEFGH"};

  ck_assert_ptr_eq(_memcpy(dst_custom, src, sizeof(src)), dst_custom);

  memcpy(dst_original, src, sizeof(src));

  ck_assert_int_eq(memcmp(dst_custom, dst_original, sizeof(src)), 0);
}
END_TEST

// Создаем TCase и упаковываем в него все тесты
TCase* tcase_memcpy(void) {
  TCase* tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_test_basic);
  tcase_add_test(tc, memcpy_test_int_arr);
  tcase_add_test(tc, memcpy_test_empty_size);
  tcase_add_test(tc, memcpy_test_overwrite);

  return tc;
}