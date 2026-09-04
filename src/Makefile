CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
GCOV_FLAGS = --coverage

# Автоматически находим все исходники в текущей папке
SRC = $(wildcard _*.c)
OBJ = $(SRC:.c=.o)

TEST_SRC = $(wildcard tests/test*.c)
TEST_OBJ = $(TEST_SRC:.c=.o)

# Определение операционной системы для флагов Check
OS := $(shell uname -s)
ifeq ($(OS), Darwin)
	# Флаги для macOS (Apple Silicon / Intel)
	CHECK_FLAGS = -I$(shell brew --prefix check)/include -L$(shell brew --prefix check)/lib -lcheck -lm -lpthread
else
	# Флаги для Linux (Ubuntu, WSL, Verter)
	CHECK_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif

# Обязательные цели по заданию
all: _string.a test

# Сборка статической библиотеки
_string.a: $(OBJ)
	ar rcs _string.a $(OBJ)
	ranlib _string.a

# Компиляция объектных файлов
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка и запуск тестов
test: _string.a
	$(CC) $(CFLAGS) $(TEST_SRC) _string.a $(CHECK_FLAGS) -o test_run
	./test_run

# Формирование отчета покрытия кода (gcov_report)
gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(SRC) $(TEST_SRC) $(CHECK_FLAGS) -o test_run
	./test_run
	lcov -t "_string_tests" -o coverage.info -c -d .
	genhtml -o report coverage.info
	@echo "Отчет готов! Открой report/index.html в браузере."

# Очистка всех сгенерированных файлов
clean:
	rm -rf *.o *.a test_run
	rm -rf *.gcno *.gcda *.info report
	rm -rf tests/*.gcno tests/*.gcda

# Цели, которые не являются файлами
.PHONY: all clean test gcov_report