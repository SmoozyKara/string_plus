CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
TEST_DIR = tests/

FUNCTION_OBJECTS = _memchr.o _memcpy.o _memcmp.o
TEST_OBJECTS = test.o test_memchr.o test_memcmp.o test_memcpy.o
all: _string clean_

_string: $(FUNCTION_OBJECTS) $(TEST_OBJECTS)
	$(CC) $(FUNCTION_OBJECTS) $(TEST_OBJECTS) -L/opt/homebrew/lib -lcheck -o _string

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

test_memcmp.o: $(TEST_DIR)test_memcmp.c $(TEST_DIR)test.h
	$(CC) $(CFLAGS) -I/opt/homebrew/include -c $(TEST_DIR)test_memcmp.c

test_memcpy.o: $(TEST_DIR)test_memcpy.c $(TEST_DIR)test.h
	$(CC) $(CFLAGS) -I/opt/homebrew/include -c $(TEST_DIR)test_memcpy.c

clean:
	rm -rf *.o *.gcda _string 

clean_:
	rm -rf *.o *.gcda

.PHONY: all clean clean_