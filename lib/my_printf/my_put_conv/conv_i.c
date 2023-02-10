/*
** EPITECH PROJECT, 2022
** put_conv_i
** File description:
** display function for my_printf that
** handles i and d conversions
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my_printf_internal.h"
#include "my.h"
#include "newmy.h"

static int add_sign_or_blank(char *final_str, long long nb, conv_det_t *details)
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

int my_put_conv_i(conv_det_t *details, va_list *arguments, int *count)
{
    long long nb_to_put = redirect_signed(details, arguments);
    int final_conv_size = my_get_di_total_size(nb_to_put, details);
    char *final_str = malloc(sizeof(char) * final_conv_size + 1);

    if (final_str == NULL)
        return (-84);
    my_str_initialise(final_str, final_conv_size + 1);
    mega_save_nbr(final_str, ABS(nb_to_put), 10);
    add_precision(final_str, (details->precision));
    add_sign_or_blank(final_str, nb_to_put, details);
    fill_width_i(final_str, details);
    my_putstr(final_str);
    free(final_str);
    *count += final_conv_size;
    return (final_conv_size);
}
