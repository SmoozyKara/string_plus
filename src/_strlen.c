#include "_string.h"

/* Вычисляет длину строки str, не включая завершающий нулевой символ. */
size_t _strlen(const char* str) {
  size_t n = 0;
  while (*str != '\0') {
    str++;
    n++;
  }
  return n;
}
