#include "_string.h"

/* Копирует до n символов из строки, на которую указывает src, в dest. */
char* _strncpy(char* dest, const char* src, size_t n) {
  char* ptr = dest;
  size_t c = 0;
  while (*ptr != '\0' && *src != '\0' && c != n) {
    *ptr = *src;
    ptr++;
    src++;
    n++;
  }
  return dest;
}