CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -c -lm
GCOV_FLAGS=--coverage -fprofile-arcs -ftest-coverage

SRC_DIR=./s21_string_functions/
OBJS_DIR=./build/
SOURCES=$(wildcard $(SRC_DIR)*.c)
OBJS=$(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SOURCES))

TARGET=s21_string.a

TESTS_SRC_DIR=./tests/
TESTS_OBJS_DIR=./build/
TESTS_SOURCES=$(wildcard $(TESTS_SRC_DIR)*.c)
TESTS_OBJS=$(patsubst $(TESTS_SRC_DIR)%.c, $(TESTS_OBJS_DIR)%.o, $(TESTS_SOURCES))

TESTS_TARGET=$(TESTS_OBJS_DIR)s21_string_tests

ifeq ($(shell uname -s),Linux)
	LIBS=-lm -lrt -lpthread -lcheck
endif

ifeq ($(shell uname -s),Darwin)
	LIBS=-lcheck
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $< -o $@

$(TESTS_TARGET): $(TESTS_OBJS) $(TARGET)
	$(CC) -o $@ $(TESTS_OBJS) $(TARGET) $(LIBS) $(GCOV_FLAG)

$(TESTS_OBJS_DIR)%.o: $(TESTS_SRC_DIR)%.c
	$(CC) $(CFLAGS) $< $(GCOV_FLAG) -o $@

test: $(TESTS_TARGET)
	./$(TESTS_TARGET)

gcov_report: clean_gcov
	$(CC) -Wall -Wextra -Werror -std=c11 $(SOURCES) $(TESTS_SOURCES) $(GCOV_FLAGS) $(LIBS) -o $(TESTS_TARGET)
	./$(TESTS_TARGET)
	lcov -o tests.info -c -d .
	genhtml -o build/report tests.info
	open build/report/index.html

clean: clean_target clean_tests clean_gcov

clean_target:
	rm -rf $(OBJS) $(TARGET)

clean_tests:
	rm -rf $(TESTS_OBJS) $(TESTS_TARGET)

clean_gcov:
	rm -rf tests.info *.gcda *.gcno build/report/

rebuild: clean all

format:
	clang-format --style=Google -i $(SOURCES) s21_string.h

check-format:
	clang-format --style=Google -n $(SOURCES) s21_string.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem $(SOURCES) $(TESTS_SOURCES)
