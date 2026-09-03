#include "_string.h"

int _memcmp(const void* str1, const void* str2, size_t n) {
  int res = 0;
  const unsigned char* ptr1 = (const unsigned char*)str1;
  const unsigned char* ptr2 = (const unsigned char*)str2;

  while (ptr1 != NULL && ptr2 != NULL && n != 0 && res == 0) {
    res = *ptr1 - *ptr2;
    ptr1++;
    ptr2++;
    n--;
  }

  return res;
}