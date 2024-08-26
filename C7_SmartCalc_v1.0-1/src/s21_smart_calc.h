#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR 1
#define MAX 3000

typedef struct s21_stack_string {
  int top;  // индекс верхнего элемента в стеке
  char items[255][MAX];
} s21_stack_string;

typedef struct s21_stack_number {
  int top;
  double items[MAX];
} s21_stack_number;

int s21_smart_calc(char string[MAX], double *result, const char x[MAX]);

void s21_create_stack_string(s21_stack_string *data);
void s21_push_stack_string(s21_stack_string *data, char newitem[MAX]);
char *s21_pop_stack_string(s21_stack_string *data);
void s21_print_stack_string(s21_stack_string *data);

void s21_create_stack_number(s21_stack_number *data);
void s21_push_stack_number(s21_stack_number *data, double newitem);
double s21_pop_stack_number(s21_stack_number *data);
void s21_print_stack_number(s21_stack_number *data);

int s21_operation_priority(char string[MAX]);
int s21_reverse_polish_notation(char string[MAX], char output_string[255][MAX],
                                int *count);
int s21_calculation_expressions(char output_string[255][MAX], int count,
                                double *result);

int s21_check_string(char string[MAX], const char x[MAX]);
int s21_is_char_in_str(char tmp_char, const char *string);

#endif