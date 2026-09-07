#include "test.h"

// 1. Одинаковые строки
START_TEST(memcmp_test_basic) {
  char str[] = "Hello!";
  ck_assert_int_eq(_memcmp(str, str, strlen(str)),
                   memcmp(str, str, strlen(str)));
}
END_TEST

// 2. Пустые строки
START_TEST(memcmp_test_empty_strings) {
  char str[] = "";
  ck_assert_int_eq(_memcmp(str, str, strlen(str)),
                   memcmp(str, str, strlen(str)));
}
END_TEST

// 3. Сравнение разных строк
START_TEST(memcmp_test_diff_strings) {
  char str1[] = "Hello!";
  char str2[] = "World!";
  ck_assert_int_eq(_memcmp(str1, str2, strlen(str1)),
                   memcmp(str1, str2, strlen(str1)));
}
END_TEST

// 4. Кол-во элементов больше чем размер строк
START_TEST(memcmp_test_out_of_range) {
  char str1[] = "Hello!";
  char str2[] = "World!";
  ck_assert_int_eq(_memcmp(str1, str2, 10), memcmp(str1, str2, 10));
}
END_TEST

// 5. Одна строка пустая, вторая нет
START_TEST(memcmp_test_compare_full_empty_str) {
  char str1[] = "Hello!";
  char str2[] = "";
  ck_assert_int_eq(_memcmp(str1, str2, strlen(str2)),
                   memcmp(str1, str2, strlen(str2)));
}
END_TEST

// 6. Не символьные массивы
START_TEST(memcmp_test_arrays) {
  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3, 4, 5};
  int arr3[] = {1, 2, 3, 9, 5};

  // Одинаковые массивы
  ck_assert_int_eq(_memcmp(arr1, arr2, sizeof(arr1)),
                   memcmp(arr1, arr2, sizeof(arr1)));

  // Разные массивы
  ck_assert_int_eq(_memcmp(arr1, arr3, sizeof(arr1)),
                   memcmp(arr1, arr3, sizeof(arr1)));
}
END_TEST

// 7. Нуль-символ посредине
START_TEST(memcmp_test_null_byte_in_middle) {
  char str1[] = "Hel\0lo";
  char str2[] = "Hel\0World";

  // До нулевого байта и сам нулевой байт (первые 4 байта) — равны
  ck_assert_int_eq(_memcmp(str1, str2, 4), memcmp(str1, str2, 4));

  // Больше 4 байт — уже есть отличия ('l' и 'W')
  ck_assert_int_eq(_memcmp(str1, str2, 6), memcmp(str1, str2, 6));
}
END_TEST

// 8. Проверка на приведение к uchar
START_TEST(memcmp_test_unsigned_char) {
  char str1[] = "\xff";  // 255 в unsigned char, -1 в signed char
  char str2[] = "\x7f";  // 127 в unsigned char, 127 в signed char

  // Если _memcmp использует signed char, она решит, что \xff < \x7f
  // Если использует unsigned char (правильно), то \xff > \x7f

  int res1 = _memcmp(str1, str2, 1);
  int res2 = memcmp(str1, str2, 1);

  // Нормализуем результат для проверки знака (т.к. точные числа могут
  // отличаться)
  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 9. Одинаковые до опр. момента
START_TEST(memcmp_test_partial_match) {
  char str1[] = "abcdefg";
  char str2[] = "abcdxyz";

  // Первые 4 байта одинаковые (abcd)
  ck_assert_int_eq(_memcmp(str1, str2, 4), memcmp(str1, str2, 4));

  // На 5-м байте уже разница
  ck_assert_int_eq(_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
}
END_TEST

// Создаем TCase и упаковываем в него все тесты
TCase* tcase_memcmp(void) {
  TCase* tc = tcase_create("memcmp_tc");

  tcase_add_test(tc, memcmp_test_basic);
  tcase_add_test(tc, memcmp_test_empty_strings);
  tcase_add_test(tc, memcmp_test_diff_strings);
  tcase_add_test(tc, memcmp_test_out_of_range);
  tcase_add_test(tc, memcmp_test_compare_full_empty_str);
  tcase_add_test(tc, memcmp_test_arrays);
  tcase_add_test(tc, memcmp_test_null_byte_in_middle);
  tcase_add_test(tc, memcmp_test_unsigned_char);
  tcase_add_test(tc, memcmp_test_partial_match);

  return tc;
}