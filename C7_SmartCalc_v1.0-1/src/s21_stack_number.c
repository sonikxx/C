#include "s21_smart_calc.h"

void s21_create_stack_number(s21_stack_number *data) { data->top = -1; }

void s21_push_stack_number(s21_stack_number *data, double newitem) {
    if (data->top < MAX - 1) {
        data->top += 1;
        data->items[data->top] = newitem;
    }
    // else {
    //     printf("Стек переполнен\n");
    // }
}

double s21_pop_stack_number(s21_stack_number *data) {
    if (data->top >= 0) {
        double res = data->items[data->top];
        data->top -= 1;
        return res;
    } else {
        // printf("Стек пустой\n");
        return 12121;
    }
}

void s21_print_stack_number(s21_stack_number *data) {
    for (int i = 0; i <= data->top; ++i) {
        printf("%f ", data->items[i]);
    }
    printf("\n");
}