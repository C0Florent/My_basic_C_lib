/*
** EPITECH PROJECT, 2022
** My save float digits
** File description:
** Saves the digits of the integer part of
** a floating point number in a given string
*/

#include "my_printf_internal.h"
#include "my.h"

static int save_one_digit(double *nb, char *buf, int exponent)
{
    double power = my_compute_float_power(10.0, exponent);
    int i = 0;

    while (my_float_int_part_size(*nb, 10) - 1 >= exponent && i < 9) {
        *nb -= power;
        i++;
    }
    my_charcat(buf, (char)(i + '0'));
    return (0);
}

static int do_roundup(char *digits, int len)
{
    if (digits[len] < '9') {
        digits[len]++;
        return (0);
    }
    if (digits[len] == '9') {
        digits[len] = '0';
        if (len >= 1) {
            do_roundup(digits, len - 1);
            return (0);
        } else {
            my_shift_str(digits, 1);
            digits[0] = '1';
        }
    }
    return (0);
}

int my_save_float_digits(double nb, int precision, char *buf)
{
    int size;
    char last_digit[2] = {'\0'};
    int i = 0;

    nb = ABS(nb);
    size = my_float_int_part_size(nb, 10);
    if (size <= 0) {
        my_charcat(buf, '0');
        size = 0;
    }
    for (i = size - 1; i >= - precision; i--) {
        save_one_digit(&nb, buf, i);
    }
    save_one_digit(&nb, last_digit, i);
    if (last_digit[0] >= '5') {
        do_roundup(buf, my_strlen(buf) - 1);
    }
    return (0);
}
