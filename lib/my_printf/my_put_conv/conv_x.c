/*
** EPITECH PROJECT, 2022
** my_put_conv_x
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf.h"
#include "newmy.h"

static int add_hex_altform(char *final_str, conv_det_t *details)
{
    if (details->is_alt_form == 1 && my_strlen(final_str) != 0) {
        my_shift_str(final_str, 2);
        final_str[0] = '0';
        final_str[1] = 'x';
    }
    return (0);
}

int my_put_conv_x(conv_det_t *details, va_list *arguments, int *count)
{
    unsigned long long nb_to_put = redirect_unsigned(details, arguments);
    int final_conv_size = my_get_x_total_size(nb_to_put, details);
    char *final_str = malloc(sizeof(char) * final_conv_size + 1);

    if (final_str == NULL)
        return (-84);
    my_str_initialise(final_str, final_conv_size);
    mega_save_nbr(final_str, nb_to_put, 16);
    add_precision(final_str, details->precision);
    add_hex_altform(final_str, details);
    fill_width_x(final_str, details);
    if (details->conversion == 'X')
        my_strupcase(final_str);
    my_putstr(final_str);
    free(final_str);
    *count += final_conv_size;
    return (final_conv_size);
}
