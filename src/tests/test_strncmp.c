#include "test.h"

// 1. базовый случай
START_TEST(strncmp_test_basic) {
  char custom[50] = "Hello World";
  char orig[50] = "Hel";

  int res1 = _strncmp(custom, orig, 3);
  int res2 = strncmp(custom, orig, 3);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 2. 0 совпадений
START_TEST(strncmp_test_no_equal) {
  char custom[50] = "Hello World";
  char orig[50] = "pqr";

  int res1 = _strncmp(custom, orig, 3);
  int res2 = strncmp(custom, orig, 3);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 3. Сравнение с пустой строкой
START_TEST(strncmp_test_empty_str) {
  char custom[50] = "";
  char orig[50] = "pqr";

  int res1 = _strncmp(custom, orig, 3);
  int res2 = strncmp(custom, orig, 3);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 4. Сравниваем 0 элементов
START_TEST(strncmp_test_empty_size) {
  char custom[50] = "Hell";
  char orig[50] = "pqr";

  int res1 = _strncmp(custom, orig, 0);
  int res2 = strncmp(custom, orig, 0);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 5. Проверка на приведение к unsigned char
START_TEST(strncmp_test_unsigned_char) {
  char str1[] = "\xff";
  char str2[] = "\x01";

  int res1 = _strncmp(str1, str2, 1);
  int res2 = strncmp(str1, str2, 1);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 6. n больше длины строк
START_TEST(strncmp_test_n_greater_than_len) {
  char custom[50] = "Apple";
  char orig[50] = "Apple";

  int res1 = _strncmp(custom, orig, 10);
  int res2 = strncmp(custom, orig, 10);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

// 7. Строки разной длины (одна строка - начало другой)
START_TEST(strncmp_test_different_lengths) {
  char custom[50] = "Hello";
  char orig[50] = "HelloWorld";

  int res1 = _strncmp(custom, orig, 10);
  int res2 = strncmp(custom, orig, 10);

  int sign1 = (res1 > 0) ? 1 : ((res1 < 0) ? -1 : 0);
  int sign2 = (res2 > 0) ? 1 : ((res2 < 0) ? -1 : 0);

  ck_assert_int_eq(sign1, sign2);
}
END_TEST

TCase* tcase_strncmp(void) {
  TCase* tc = tcase_create("strncmp_tc");

  tcase_add_test(tc, strncmp_test_basic);
  tcase_add_test(tc, strncmp_test_no_equal);
  tcase_add_test(tc, strncmp_test_empty_str);
  tcase_add_test(tc, strncmp_test_empty_size);
  tcase_add_test(tc, strncmp_test_unsigned_char);
  tcase_add_test(tc, strncmp_test_n_greater_than_len);
  tcase_add_test(tc, strncmp_test_different_lengths);

  return tc;
}