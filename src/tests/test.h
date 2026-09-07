#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <string.h>

#include "../_string.h"

// Объявляем функцию из test_memchr.c
TCase* tcase_memchr(void);
TCase* tcase_memcmp(void);
TCase* tcase_memcpy(void);
TCase* tcase_memset(void);
TCase* tcase_strncat(void);

#endif  // TEST_H