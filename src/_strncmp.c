#include "_string.h"
/* Сравнивает не более первых n байтов str1 и str2. */
int _strncmp(const char* str1, const char* str2, size_t n) {
  int result = 0;

  if (n > 0) {
    while (n > 1 && *str1 != '\0' && *str1 == *str2) {
      str1++;
      str2++;
      n--;
    }
    result = *(unsigned char*)str1 - *(unsigned char*)str2;
  }

  return result;
}