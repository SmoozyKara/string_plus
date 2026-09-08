#include "_string.h"

/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
 * которую указывает аргумент str. */
char* _strchr(const char* str, int c) {
  char* result = NULL;

  char search_char = (char)c;

  while (*str != '\0' && result == NULL) {
    if (*str == search_char) result = (char*)str;
    str++;
  }

  if (result == NULL && search_char == '\0') {
    result = (char*)str;
  }

  return result;
}