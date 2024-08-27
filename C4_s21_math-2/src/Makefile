PROJECT_NAME	=s21_math
ODIR 			= ./obj
INC_PATH		= ./
LIB_SRC_DIR		= ./Functions
BUILD_LIB		= ./
UNAME_S 		:= $(shell uname -s)
TEST_NAME		= ${PROJECT_NAME}_test
TEST_SRC		= $(TEST_NAME).c
Flags 			= -Wall -Wextra -Werror -pedantic -std=c11
gcc 			= gcc $(Flags)

LIB_SOURCES		= $(wildcard $(LIB_SRC_DIR)/*.c)
REPORT_FILES	= $(wildcard *.gcno) $(wildcard *.gcda)
INC				:= $(wildcard *.h)
OBJ 			= $(patsubst %.c,$(ODIR)/%.o, $(LIB_SOURCES))


ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =

endif

$(ODIR)/%.o: %.c $(INC)
	$(gcc) $(ADD_LIB) -I${INC_PATH} $<  -c -o $@

all: clear $(PROJECT_NAME).a

clear:
	clear

clean:
	rm -rf $(ODIR)/*.o $(ODIR)/*.gc*
	rm -rf $(ODIR)/*/*.o $(ODIR)/*/*.gc*
	rm -rf ./gcov/*.o ./gcov/*.gc*
	rm -rf ./*.gc*
	rm -rf $(BUILD_LIB)/$(PROJECT_NAME).a
	rm -rf report*
	rm -f s21_math_test

obj: $(OBJ)

clang:
	clang-format --style=Google -n ./*.h ${LIB_SRC_DIR}/*.c

clang-replace:
	clang-format --style=Google -i  *.h ${LIB_SRC_DIR}/*.c


$(PROJECT_NAME).a: obj
	ar rcs $@ $(ODIR)/$(LIB_SRC_DIR)/*.o

set_debug_gcc:
	$(eval gcc += -g)
	@echo s21_math:Debug build

set_report_gcc:
	$(eval gcc += -fprofile-arcs -ftest-coverage -fPIC)
	@echo s21_math:Check build


test: $(BUILD_LIB)/$(PROJECT_NAME).a #$(TEST_SRC)
	$(gcc) s21_math_test.c $^ -o $(TEST_NAME) $(TEST_CHECK_F) $(ADD_LIB)
	./$(TEST_NAME)

gcov_report: clean set_report_gcc test
	gcov ${LIB_SRC_DIR}/*.c -o $(ODIR)/*
	mv *.gcov ./gcov
	mv ./*.gc* $(ODIR)/*/*.gc* ./gcov
	lcov -t ./gcov -o report.info -c -d ./gcov
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html


.PHONY: clean obj clear $(PROJECT_NAME) $(BUILD_LIB)/$(PROJECT_NAME).a test clang-replace all $(PROJECT_NAME).a set_debug_gcc set_report_gcc gcov_report