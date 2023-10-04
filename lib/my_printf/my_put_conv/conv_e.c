/*
** EPITECH PROJECT, 2022
** my_put_conv_e
** File description:
** sub-function for my printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf_internal.h"
#include "newmy.h"

static int add_decimal_dot(char *final_str, conv_det_t *details)
{
    if (details->precision == 0 && details->is_alt_form == 0)
        return (0);
    my_shift_str(&final_str[1], 1);
    final_str[1] = '.';
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

static int add_exponent(char *final_str, int exponent)
{
    my_charcat(final_str, 'e');
    if (exponent >= 0)
        my_charcat(final_str, '+');
    else
        my_charcat(final_str, '-');
    if (ABS(exponent) < 10)
        my_charcat(final_str, '0');
    if (exponent == 0)
        my_charcat(final_str, '0');
    mega_save_nbr(final_str, ABS(exponent), 10);
    return (0);
}

static int finish_conv_e(
    char *final_str,
    double nb,
    conv_det_t *details,
    int exponent
)
{
    add_decimal_dot(final_str, details);
    add_sign_or_blank(final_str, nb, details);
    add_exponent(final_str, exponent);
    fill_width_i(final_str, details);
    if (details->conversion == 'E')
        my_strupcase(final_str);
    return (my_strlen(final_str));
}

int my_put_conv_e(conv_det_t *details, va_list *arguments, int fd)
{
    double nb = va_arg(*arguments, double);
    int size = my_get_e_total_size(nb, details);
    char *final_str = malloc(sizeof(char) * size + 1);
    int exponent = my_float_int_part_size(nb, 10) - 1;

    if (final_str == NULL)
        return (-84);
    my_str_initialise(final_str, size);
    if (exponent == -840)
        exponent = 0;
    my_save_float_digits(nb / my_compute_float_power(10.0,
            exponent), details->precision, final_str);
    if (my_strlen(final_str) > details->precision + 1) {
        exponent++;
        final_str[details->precision + 1] = '\0';
    }
    size = finish_conv_e(final_str, nb, details, exponent);
    my_fdputs(final_str, fd);
    free(final_str);
    return (size);
}
