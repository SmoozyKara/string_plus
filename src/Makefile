CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
TEST_DIR = tests/


all: _string

_string: _memcpy.o _memchr.o _memcmp.o test.o test_memchr.o
	$(CC) _memcpy.o _memchr.o _memcmp.o test.o test_memchr.o -L/opt/homebrew/lib -lcheck -o _string

_memchr.o: _memchr.c _string.h
	$(CC) $(CFLAGS) -c _memchr.c

_memcmp.o: _memcmp.c _string.h
	$(CC) $(CFLAGS) -c _memcmp.c

_memcpy.o: _memcpy.c _string.h
	$(CC) $(CFLAGS) -c _memcpy.c

test.o: $(TEST_DIR)test.c $(TEST_DIR)test.h
	$(CC) $(CFLAGS) -I/opt/homebrew/include -c $(TEST_DIR)test.c 

test_memchr.o: $(TEST_DIR)test_memchr.c $(TEST_DIR)test.h
	$(CC) $(CFLAGS) -I/opt/homebrew/include -c $(TEST_DIR)test_memchr.c

clean:
	rm -rf *.o *.gcda _string 

.PHONY: all clean