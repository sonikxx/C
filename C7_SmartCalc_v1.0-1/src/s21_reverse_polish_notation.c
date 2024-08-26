#include "s21_smart_calc.h"

int s21_reverse_polish_notation(char string[MAX], char output_string[255][MAX],
                                int *count) {
    s21_stack_string *my_stack =
        (s21_stack_string *)calloc(1, sizeof(s21_stack_string));
    s21_create_stack_string(my_stack);
    char tmp_string[MAX] = {0};
    char tmp_number[MAX] = {0};
    char tmp_operation[MAX] = {0};
    int flag = OK;
    int flag_number = 0;    // было ли считано число
    int flag_operation = 0; // была ли считана операция
    int index_for_tmp_number = 0;
    int index_operation = 0;
    int len = strlen(string);
    for (int i = 0; i < len; ++i) {
        printf("OUTPUT:\n");
        for (int n = 0; n < *count; ++n) {
            for (size_t l = 0; l < strlen(output_string[n]); ++l) {
                printf("%c", output_string[n][l]);
            }
            printf(" ");
        }
        printf("\n");
        flag_number = 0;
        flag_operation = 0;
        index_for_tmp_number = 0;
        memset(tmp_number, 0, MAX * sizeof(char));
        while ((i < len) && (isdigit(string[i]) || (string[i] == '.'))) {
            flag_number = 1;
            tmp_number[index_for_tmp_number] = string[i];
            ++index_for_tmp_number;
            ++i;
        }
        if (flag_number == 1) {
            tmp_number[index_for_tmp_number] = '\0';
            strcpy(output_string[*count], tmp_number);
            *count += 1;
            --i;
        }
        if (string[i] == '(') {
            memset(tmp_string, 0, MAX * sizeof(char));
            tmp_string[0] = string[i];
            tmp_string[1] = '\0';
            s21_push_stack_string(my_stack, tmp_string);
        }
        if (string[i] == ')') {
            char *string_in_stack = s21_pop_stack_string(my_stack);
            memset(tmp_string, 0, MAX * sizeof(char));
            strcpy(tmp_string, string_in_stack);
            while (strcmp(tmp_string, "(") != 0 && my_stack->top >= 0) {
                strcpy(output_string[*count], tmp_string);
                *count += 1;
                string_in_stack = s21_pop_stack_string(my_stack);
                memset(tmp_string, 0, MAX * sizeof(char));
                strcpy(tmp_string, string_in_stack);
            }
            // проверка на правильную скобочную последовательность
            if (strcmp(tmp_string, "(") != 0) {
                flag = ERROR;
                break;
            }
        }
        memset(tmp_operation, 0, MAX * sizeof(char));
        // перед унарной операцией всегда стоит либо другая операция, либо
        // открывающая скобка, либо вообще ничего
        if ((string[i] == '+' || string[i] == '-') &&
            (i == 0 ||
             (i - 1 > 0 && s21_is_char_in_str(string[i - 1], "(+-*/^%") == OK))) {
            tmp_operation[0] = 'o';
            tmp_operation[1] = string[i];
            tmp_operation[2] = '\0';
            flag_operation = 1;
            printf("OPERATION: %s\n", tmp_operation);
        } else if (s21_is_char_in_str(string[i], "+-*/^%") == OK) {
            tmp_operation[0] = string[i];
            tmp_operation[1] = '\0';
            flag_operation = 1;
            printf("OPERATION: %s\n", tmp_operation);
        }
        // считываем операцию
        index_operation = 0;
        if (isalpha(string[i])) {
            while (isalpha(string[i]) && i < len) {
                tmp_operation[index_operation] = string[i];
                ++index_operation;
                ++i;
            }
            --i;
            tmp_operation[index_operation] = '\0';
            flag_operation = 1;
        }
        if (flag_operation == 1) {
            printf("OPERATION: %s\n", tmp_operation);
            int priority_tmp_operation = s21_operation_priority(tmp_operation);
            int priority_stack = -1;
            if (my_stack->top >= 0)
                priority_stack = s21_operation_priority(my_stack->items[my_stack->top]);
            while (my_stack->top >= 0 && (priority_stack > priority_tmp_operation ||
                                          (priority_stack == priority_tmp_operation &&
                                           strcmp(tmp_operation, "^") != 0))) {
                char *string_in_stack = s21_pop_stack_string(my_stack);
                memset(tmp_string, 0, MAX * sizeof(char));
                strcpy(tmp_string, string_in_stack);
                strcpy(output_string[*count], tmp_string);
                *count += 1;
                if (my_stack->top >= 0)
                    priority_stack =
                        s21_operation_priority(my_stack->items[my_stack->top]);
                else
                    priority_stack = -1;
            }
            s21_push_stack_string(my_stack, tmp_operation);
        }
        if (string[i] == '=')
            break;
    }
    while (my_stack->top != -1) {
        char *string_in_stack = s21_pop_stack_string(my_stack);
        memset(tmp_string, 0, MAX * sizeof(char));
        strcpy(tmp_string, string_in_stack);
        // проверка на правильную скобочную последовательность
        if (strcmp(tmp_string, "(") == 0) {
            flag = ERROR;
            break;
        }
        strcpy(output_string[*count], tmp_string);
        *count += 1;
    }
    printf("OUTPUT_END:\n");
    for (int n = 0; n < *count; ++n) {
        for (size_t l = 0; l < strlen(output_string[n]); ++l) {
            printf("%c", output_string[n][l]);
        }
        printf(" ");
    }
    printf("\n");
    free(my_stack);
    return flag;
}