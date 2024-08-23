CC=gcc -std=c11
CFLAGS=-Wall -Werror -Wextra
GCOV_FLAGS = -fprofile-arcs -ftest-coverage -lgcov --coverage
TEST_SOURCES = $(wildcard tests/*.c)
SRCS = $(wildcard s21_*.c)
OBJS = $(SRCS:.c=.o)
LIB_NAME = s21_matrix.a

LIBS = -lcheck
OPEN = open
OS := $(shell uname -s)
ifeq ($(OS),Linux)
LIBS += -lsubunit -lm -lrt -lpthread 
OPEN = xdg-open
endif

all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJS)
	ar rcs $(LIB_NAME) $^
	ranlib $@
	rm -rf *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -lm -o $@

test: tests/*.c *.c
	$(CC) $(CFLAGS) $^ -o $@ $(GCOV_FLAGS) $(LIBS)
	./test

gcov_report: test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	$(OPEN) ./report/index.html

rebuild: clean all

clean:
	rm -fr *.o *.a test test.dSYM/ *.gcda *.gcno report/ test.info *.html gcov_test.info
