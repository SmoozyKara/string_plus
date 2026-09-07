#include "test.h"

#include <stdlib.h>

int main(void) {
  int failed_count;

  // 1. Создаем главный набор тестов для всей библиотеки
  Suite* s = suite_create("_string");

  // 2. Добавляем в него группу тестов
  suite_add_tcase(s, tcase_memchr());
  suite_add_tcase(s, tcase_memcmp());
  suite_add_tcase(s, tcase_memcpy());
  suite_add_tcase(s, tcase_memset());
  suite_add_tcase(s, tcase_strncat());
  suite_add_tcase(s, tcase_strchr());

  // 3. Создаем "запускатель" тестов
  SRunner* sr = srunner_create(s);

  // 4. Запускаем все тесты (CK_NORMAL показывает только упавшие тесты и общий
  // итог, CK_VERBOSE - вообще все)
  srunner_run_all(sr, CK_NORMAL);

  // 5. Получаем количество ошибок и освобождаем память
  failed_count = srunner_ntests_failed(sr);
  srunner_free(sr);

  // Если ошибок 0, программа возвращает 0 (успех)
  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}