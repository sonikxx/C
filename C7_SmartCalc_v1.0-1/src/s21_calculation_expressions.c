#include "s21_smart_calc.h"

int s21_calculation_expressions(char output_string[255][MAX], int count,
                                double *result) {
    s21_stack_number *my_stack_number =
        (s21_stack_number *)calloc(1, sizeof(s21_stack_number));
    s21_create_stack_number(my_stack_number);
    int flag = OK;
    double left_number = 0;
    double right_number = 0;
    double number = 0;
    for (int i = 0; i < count; ++i) {
        printf("result: %lf\n", *result);
        printf("output[i]: %s\n", output_string[i]);
        // std::cout << "output[i]:" << output_[i] << "\n";
        printf("STACK:\n");
        s21_print_stack_number(my_stack_number);
        if (isdigit(output_string[i][0])) {
            char *nstr = output_string[i];
            s21_push_stack_number(my_stack_number, strtod(output_string[i], &nstr));
        } else {
            if (s21_operation_priority(output_string[i]) <= 3 ||
                strcmp(output_string[i], "^") == 0 ||
                strcmp(output_string[i], "%") == 0) {
                left_number = s21_pop_stack_number(my_stack_number);
                right_number = s21_pop_stack_number(my_stack_number);
                if (strcmp(output_string[i], "-") == 0)
                    *result = right_number - left_number;
                else if (strcmp(output_string[i], "+") == 0)
                    *result = right_number + left_number;
                else if (strcmp(output_string[i], "*") == 0)
                    *result = right_number * left_number;
                else if (strcmp(output_string[i], "/") == 0) {
                    if (left_number == 0)
                        *result = NAN;
                    else
                        *result = right_number / left_number;
                } else if (strcmp(output_string[i], "%") == 0)
                    *result = fmod(right_number, left_number);
                else if (strcmp(output_string[i], "^") == 0)
                    *result = pow(right_number, left_number);
            } else { // унарные операции
                number = s21_pop_stack_number(my_stack_number);
                if (strcmp(output_string[i], "o-") == 0)
                    *result = (-1) * number;
                else if (strcmp(output_string[i], "o+") == 0)
                    *result = number;
                else if (strcmp(output_string[i], "sin") == 0)
                    *result = sin(number);
                else if (strcmp(output_string[i], "cos") == 0)
                    *result = cos(number);
                else if (strcmp(output_string[i], "tan") == 0)
                    *result = tan(number);
                else if (strcmp(output_string[i], "acos") == 0)
                    *result = acos(number);
                else if (strcmp(output_string[i], "asin") == 0)
                    *result = asin(number);
                else if (strcmp(output_string[i], "atan") == 0)
                    *result = atan(number);
                else if (strcmp(output_string[i], "sqrt") == 0)
                    *result = sqrt(number);
                else if (strcmp(output_string[i], "ln") == 0)
                    *result = log(number);
                else if (strcmp(output_string[i], "log") == 0)
                    *result = log10(number);
            }
            s21_push_stack_number(my_stack_number, *result);
            if (isnan(*result)) {
                flag = ERROR;
                break;
            }
        }
    }
    *result = s21_pop_stack_number(my_stack_number);
    free(my_stack_number);
    return flag;
}