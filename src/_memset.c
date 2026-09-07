#include "_string.h"

/* Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
 * указывает аргумент str. */
void* _memset(void* str, int c, size_t n) {
  unsigned char* ptr_str = (unsigned char*)str;
  while (ptr_str != NULL && n != 0) {
    *ptr_str = c;
    n--;
    ptr_str++;
  }
  return str;
}