FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -o $(FILE)
FILE = s21_cat
TEST = catTest

all: s21_cat linter

s21_cat: clean
	gcc $(FLAGS) $(FILE).c 

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
