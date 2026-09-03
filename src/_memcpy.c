#include "_string.h"

/* Копирует n символов из src в dest. */
void* _memcpy(void* dest, const void* src, size_t n) {
  unsigned char* ptr_dest = (unsigned char*)dest;
  const unsigned char* ptr_src = (const unsigned char*)src;
  while (ptr_dest != NULL && ptr_src != NULL && n != 0) {
    *ptr_dest = *ptr_src;
    n--;
    ptr_dest++;
    ptr_src++;
  }
  return dest;