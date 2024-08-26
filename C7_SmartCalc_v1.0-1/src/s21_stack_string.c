#include "s21_smart_calc.h"

void s21_create_stack_string(s21_stack_string *data) { data->top = -1; }

void s21_push_stack_string(s21_stack_string *data, char newitem[MAX]) {
  if (data->top < MAX - 1) {
    data->top += 1;
    strcpy(data->items[data->top], newitem);
  }
  // else {
  //     printf("Стек переполнен\n");
  // }
}

char *s21_pop_stack_string(s21_stack_string *data) {
  // if (data->top >= 0) {
  data->top -= 1;
  return data->items[data->top + 1];
  // } else {
  // printf("Стек пустой\n");
  //     return 0;
  // }
}

// void s21_print_stack_string(s21_stack_string *data) {
//     for (int i = 0; i <= data->top; ++i) {
//         printf("%s ", data->items[i]);
//     }
//     printf("\n");
// }