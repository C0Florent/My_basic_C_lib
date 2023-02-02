/*
** EPITECH PROJECT, 2022
** my_put_conv_f
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

static int add_decimal_dot(char *final_str, conv_det_t *details)
{
    int shift_start = my_strlen(final_str) - details->precision;

    if (details->precision == 0 && details->is_alt_form == 0)
        return (0);
    my_shift_str(&final_str[shift_start], 1);
    final_str[shift_start] = '.';
    return (0);
}

static int add_sign_or_blank(char *final_str, double nb, conv_det_t *details)
{
    if (nb < 0 || details->space_flag == 1 || details->plus_flag == 1)
        my_shift_str(final_str, 1);
    else
        return (0);
    if (nb < 0)
        final_str[0] = '-';
    else {
        if (details->space_flag == 1)
            final_str[0] = ' ';
        if (details->plus_flag == 1)
            final_str[0] = '+';
    }
    return (0);
}

int my_put_conv_f(conv_det_t *details, va_list *arguments, int *count)
{
    double nb = va_arg(*arguments, double);
    int total_size = my_get_f_total_size(nb, details);
    char *final_str = malloc(sizeof(char) * total_size + 2);
    int len = 0;

    my_str_initialise(final_str, total_size + 2);
    my_save_float_digits(nb, details->precision, final_str);
    add_decimal_dot(final_str, details);
    add_sign_or_blank(final_str, nb, details);
    fill_width_i(final_str, details);
    my_putstr(final_str);
    len = my_strlen(final_str);
    free(final_str);
    *count += len;
    return (len);
}
