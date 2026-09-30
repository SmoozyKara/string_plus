#include "test.h"

#include <stdlib.h>

int main(void) {
  int failed_count;

  // 1. Создание набора тестов для всей библы
  Suite* s = suite_create("_string");

  // 2. Добавление каждого теста
  suite_add_tcase(s, tcase_memchr());
  suite_add_tcase(s, tcase_memcmp());
  suite_add_tcase(s, tcase_memcpy());
  suite_add_tcase(s, tcase_memset());
  suite_add_tcase(s, tcase_strncat());
  suite_add_tcase(s, tcase_strchr());
  suite_add_tcase(s, tcase_strncmp());
  suite_add_tcase(s, tcase_strncpy());
  suite_add_tcase(s, tcase_strcspn());
  suite_add_tcase(s, tcase_strlen());

  // 3. Создание ранера тестов
  SRunner* sr = srunner_create(s);

  // 4. Запуск самого ранера
  srunner_run_all(sr, CK_NORMAL);

  // 5. Получаем количество ошибок и освобождаем память
  failed_count = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}