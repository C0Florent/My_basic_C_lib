/*
** EPITECH PROJECT, 2022
** My GetNbr
** File description:
** A function that reads a string containing (or not) a number and
** returns the numerical value of the number entered
*/

#include "my.h"
#include <stddef.h>

int my_getnbr(char const *str)
{
    int sign = 1;
    int i = 0;
    int return_val = 0;

    i = sign_counter(str, &sign);
    return_val = read_nbr(str, i, sign);
    return (return_val * sign);
}

int sign_counter(char const *str, int *sign)
{
    int len = my_strlen(str);
    int i;

    for (i = 0; my_char_isnum(str[i]) == 0 && i < len; i++) {
        if (str[i] == '-')
            *sign = *sign * -1;
    }
    return (i);
}

int read_nbr(char const *str, int first_digit_index, int sign)
{
    int return_val = 0;

    for (int i = first_digit_index; my_char_isnum(str[i]) == 1; i++) {
        if (add_if_possib(&return_val, (int)(str[i] - '0'), sign) == 84)
            return (0);
    }
    return (return_val);
}

int add_if_possib(int *current_value, int new_term, int sign)
{
    if (*current_value > 214748364 ||
        (*current_value >= 214748364 && new_term > 7 - (sign - 1) / 2)) {
        return (84);
    }
    *current_value = *current_value * 10 + new_term;
    return (0);
}
