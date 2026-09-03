#include "_string.h"

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