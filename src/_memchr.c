#include "_string.h"

/* Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
 * байтах строки, на которую указывает аргумент str.*/
void* _memchr(const void* str, int c, size_t n) {
  const unsigned char* ptr = (const unsigned char*)str;

  unsigned char target = (unsigned char)c;
  void* res = NULL;
  while (n != 0 && res == NULL) {
    if (*ptr == target) {
      res = (void*)ptr;
    }
    ptr++;
    n--;
  }

  return res;
}