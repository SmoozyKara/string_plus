#include "_string.h"

/* Добавляет строку, на которую указывает src, в конец строки, на которую
 * указывает dest, длиной до n символов. */
char* _strncat(char* dest, const char* src, size_t n) {
  char* ptr_dest = dest;
  while (*ptr_dest != '\0') ptr_dest++;

  const char* ptr_src = src;
  while (n != 0 && *src != '\0') {
    *ptr_dest = *ptr_src;
    n--;
    ptr_dest++;
    ptr_src++;
  }
  *ptr_dest = '\0';
  return dest;
}