#include "_string.h"

/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str. */
char* _strchr(const char* str, int c) {
  char* result = NULL;

  while (*str != '\0' && result == NULL) {
    if (*str == (char)c) result = (char*)str;
    str++;
  }

  if (result == NULL && c == '\0') {
    result = (char*)str;
  }

  return result;
}