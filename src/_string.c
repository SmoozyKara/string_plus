#include "_string.h"

#include <string.h>

int main() {
  char* str1 = "Hello";
  char* str2 = "Worhd";
  size_t n = 3;
  int c = 'e';

  printf("memchr: %p %p\n", _memchr(str1, c, n), memchr(str1, c, n));
  printf("memcmp: %d %d ", _memcmp(str1, str2, n), memcmp(str1, str2, n));

  return 0;
}

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

// void* _memcpy(void* dest, const void* src, size_t n) {}
// void* _memset(void* str, int c, size_t n) {}
// char* _strncat(char* dest, const char* src, size_t n) {}
// char* _strchr(const char* str, int c) {}
// int _strncmp(const char* str1, const char* str2, size_t n) {}
// char* _strncpy(char* dest, const char* src, size_t n) {}
// size_t _strcspn(const char* str1, const char* str2) {}
// char* _strerror(int errnum) {}
// size_t _strlen(const char* str) {}
// char* _strpbrk(const char* str1, const char* str2) {}
// char* _strrchr(const char* str, int c) {}
// char* _strstr(const char* haystack, const char* needle) {}
// char* _strtok(char* str, const char* delim) {}