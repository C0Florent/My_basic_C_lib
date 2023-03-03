/*
** EPITECH PROJECT, 2022
** my_put_conv_o
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "my_printf_internal.h"
#include "newmy.h"

static int add_octal_altform(char *final_str, int altform)
{
    if (altform == 1 && final_str[0] != '0') {
        my_shift_str(final_str, 1);
        final_str[0] = '0';
    }
    return (0);
}

int my_put_conv_o(conv_det_t *details, va_list *arguments, int fd)
{
    unsigned long long nb_to_put = redirect_unsigned(details, arguments);
    int final_conv_size = my_get_o_total_size(nb_to_put, details);
    char *final_str = malloc(sizeof(char) * final_conv_size + 1);

    if (final_str == NULL)
        return (-84);
    my_str_initialise(final_str, final_conv_size + 1);
    mega_save_nbr(final_str, nb_to_put, 8);
    add_precision(final_str, details->precision);
    add_octal_altform(final_str, details->is_alt_form);
    fill_width_uo(final_str, details);
    my_fdputs(final_str, fd);
    free(final_str);
    return (final_conv_size);
}
