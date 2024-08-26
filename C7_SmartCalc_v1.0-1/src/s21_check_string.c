#include "s21_smart_calc.h"

// удаление двойных пробелов и проверкана допустимые символы
int s21_remove_space(char string[MAX]);
// проверка, что функции не разделены пробелом и не встречаются 2 числа подряд,
// удаление оставшихся пробелов
int s21_check_space(char string[MAX]);
// скобочная последовательность вида ()
int s21_check_bracket(char string[MAX]);
// проверка, что знак равенства вставлен коррeктно
int s21_check_equal(char string[MAX]);
// проверка, что 2 операции или операнда не могут идти подряд + унарные операции
int s21_check_order(char string[MAX]);
// проверка корректности введеных слов
int s21_check_alpha(char string[MAX]);
// проверка, что функция написана правильно
int s21_check_function(char string[MAX]);
// проверка, что числа написаны правильно
int s21_check_digit(char string[MAX]);
// проверка, что операции расположены в корректном порядке
int s21_check_order(char string[MAX]);
// вставка x, если он есть в строчке
int s21_insert_x(char string[MAX], const char x[MAX]);

int s21_check_string(char string[MAX], const char x[MAX]) {
  int flag = OK;
  flag = s21_remove_space(string);
  if (flag == OK) flag = s21_insert_x(string, x);
  if (flag == OK) flag = s21_check_space(string);
  if (flag == OK) flag = s21_check_bracket(string);
  if (flag == OK) flag = s21_check_equal(string);
  if (flag == OK) flag = s21_check_alpha(string);
  if (flag == OK) flag = s21_check_digit(string);
  if (flag == OK) flag = s21_check_order(string);
  return flag;
}

int s21_remove_space(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  char new_string[MAX] = {0};
  int index_string = 0;
  int k = 0;
  // убираем лишние пробелы в начале
  while (string[k] == ' ' && k < len) {
    ++k;
  }
  if (k > 0) {
    --k;
  }
  for (int i = k; i < len; ++i) {
    if ((string[i] >= 'a' && string[i] <= 'z') ||
        s21_is_char_in_str(string[i], "0123456789= ()+-*/^.") == OK) {
      if ((string[i] == ' ' && string[i - 1] != ' ') || string[i] != ' ') {
        if (i + 2 < len && strncmp(&string[i], "mod", 3) == 0) {
          new_string[index_string] = '%';
          ++index_string;
          i += 2;
        } else {
          new_string[index_string] = string[i];
          ++index_string;
        }
      }
    } else {
      // printf("Используются недопустимые символы\n");
      flag = ERROR;
      break;
    }
  }
  if (flag == OK) {
    // убираем пробел после знака =
    if (new_string[index_string - 1] == ' ') {
      new_string[index_string - 1] = '\0';
    } else {
      new_string[index_string] = '\0';
    }
    memset(string, 0, MAX * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return flag;
}

int s21_insert_x(char string[MAX], const char x[MAX]) {
  int flag = OK;
  char new_string[MAX] = {0};
  int index_string = 0;
  int flag_x = 0;
  char *nstr;
  if (strtod(x, &nstr) == 0 && nstr == string) flag = ERROR;
  for (size_t i = 0; i < strlen(string) && flag == OK; ++i) {
    if (string[i] == 'x') {
      if ((i >= 1 && (isdigit(string[i - 1]) || string[i - 1] == 'x')) ||
          (i + 1 < strlen(string) &&
           (isdigit(string[i + 1]) || string[i + 1] == 'x'))) {
        flag = ERROR;
        break;
      } else {
        flag_x = 1;
        for (size_t k = 0; k < strlen(x); ++k) {
          new_string[index_string] = x[k];
          ++index_string;
        }
      }
    } else {
      new_string[index_string] = string[i];
      ++index_string;
    }
  }
  if (flag_x == 1) {
    new_string[index_string] = '\0';
    memset(string, 0, MAX * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return flag;
}

int s21_check_space(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  char new_string[MAX] = {0};
  int index_string = 0;
  for (int i = 0; i < len; ++i) {
    if (string[i] == ' ' && i - 1 >= 0 &&
        (((isdigit(string[i - 1]) || string[i - 1] == '.') && i + 1 < len &&
          (isdigit(string[i + 1]) || string[i + 1] == '.')) ||
         isalpha(string[i - 1]))) {
      // printf("Функция разделена пробелами или записаны 2 числа подряд\n");
      flag = ERROR;
      break;
    }
    if (string[i] != ' ') {
      new_string[index_string] = string[i];
      ++index_string;
    }
  }
  if (flag == OK) {
    new_string[index_string] = '\0';
    memset(string, 0, MAX * sizeof(char));
    memcpy(string, new_string, strlen(new_string));
  }
  return flag;
}

int s21_check_bracket(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  for (int i = 0; i < len - 1; ++i) {
    if (string[i] == '(' && string[i + 1] == ')') flag = ERROR;
  }
  return flag;
}

int s21_check_equal(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  int counter_equal = 0;
  for (int i = 0; i < len; ++i) {
    if (string[i] == '=') {
      ++counter_equal;
    }
    if (counter_equal > 1) {
      flag = ERROR;
      // printf("Выражение содержит большего одного знака =\n");
      break;
    }
  }
  if (string[len - 1] != '=' || counter_equal == 0) {
    flag = ERROR;
    // printf("Знак = должен находиться в конце выражения\n");
  }
  return flag;
}

int s21_check_alpha(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  char string_function[MAX] = {0};
  int index_string = 0;
  int flag_function = 0;
  for (int i = 0; i < len; ++i) {
    index_string = 0;
    while (isalpha(string[i])) {
      string_function[index_string] = string[i];
      ++index_string;
      ++i;
      flag_function = 1;
      // if (i == len)
      //     break;
    }
    if (flag_function == 1) {
      string_function[index_string] = '\0';
      if (s21_check_function(string_function) == OK && i < len &&
          string[i] == '(') {
        flag_function = 0;
        memset(string_function, 0, MAX * sizeof(char));
      } else {
        // printf("Функция написана неправильно или после нее не идет
        // открывающаяся скобка\n");
        flag = ERROR;
        break;
      }
    }
  }
  return flag;
}

int s21_check_function(char string[MAX]) {
  int flag = ERROR;
  if (strcmp(string, "sin") == 0 || strcmp(string, "cos") == 0 ||
      strcmp(string, "mod") == 0 || strcmp(string, "tan") == 0 ||
      strcmp(string, "acos") == 0 || strcmp(string, "asin") == 0 ||
      strcmp(string, "atan") == 0 || strcmp(string, "mod") == 0 ||
      strcmp(string, "sqrt") == 0 || strcmp(string, "ln") == 0 ||
      strcmp(string, "log") == 0 || strcmp(string, "atan") == 0)
    flag = OK;
  return flag;
}

int s21_check_digit(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  int flag_number = 0;
  int counter_dot = 0;
  for (int i = 0; i < len; ++i) {
    counter_dot = 0;
    flag_number = 0;
    while ((i < len) && (isdigit(string[i]) || (string[i] == '.'))) {
      flag_number = 1;
      if (string[i] == '.') ++counter_dot;
      if (counter_dot > 1 ||
          (string[i] == '.' && (i - 1 < 0 || !isdigit(string[i - 1]) ||
                                i + 1 >= len || !isdigit(string[i + 1])))) {
        // printf("Неверно введено вещественное число\n");
        flag = ERROR;
        break;
      }
      ++i;
    }
    if (flag_number == 1) {
      --i;
    }
  }
  return flag;
}

int s21_check_order(char string[MAX]) {
  int flag = OK;
  int len = strlen(string);
  int flag_prev = -1;  // 0 - число, 1 - бинарная операция, 2 - унарная
                       // операция, 3 - функция
  for (int i = 0; i < len; ++i) {
    if (isdigit(string[i]) || string[i] == '.') {
      if (flag_prev == 0) {
        flag = ERROR;
        break;
      } else {
        while (i < len && (isdigit(string[i]) || string[i] == '.')) {
          ++i;
        }
        --i;
        flag_prev = 0;
      }
    }
    if (s21_is_char_in_str(string[i], "*/^%") == OK) {
      if (flag_prev == 1 || flag_prev == -1) {
        flag = ERROR;
        break;
      } else
        flag_prev = 1;
    }
    if (string[i] == '+' || string[i] == '-') {
      if (i == 0 ||
          (i - 1 >= 0 && s21_is_char_in_str(string[i - 1], "(+-*/^%") == OK)) {
        if (flag_prev == 2) {
          flag = ERROR;
          break;
        } else
          flag_prev = 2;
      } else {
        flag_prev = 1;
      }
    }
  }
  if (flag == ERROR || flag_prev == 1 || flag_prev == 2) {
    flag = ERROR;
    // printf("Операции и операнды расположены в неправильном порядке\n");
  }
  return flag;
}