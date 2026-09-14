#include "_string.h"

/* Вычисляет длину начального сегмента str1, который полностью состоит из
 * символов, не входящих в str2. */
size_t _strcspn(const char* str1, const char* str2) {
  size_t n = 0;
  while (*str1 != *str2 && *str1 == '\0' && *str2 == '\0') n++;
  return n;
}