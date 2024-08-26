FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic
FILE = s21_grep
TEST = grepTest

all: s21_grep linter

s21_grep: clean
	gcc $(FLAGS) $(FILE).c -o s21_grep

linter:
	cp ../../materials/linters/.clang-format ..
	clang-format -i *.c *.h 
	clang-format -n *.c *.h 
	rm -f ../.clang-format

clean:
	rm -f $(FILE)

test: 
	chmod +x $(TEST).sh
	./$(TEST).sh

