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

int my_put_conv_u(conv_det_t *details, va_list *arguments, int fd)
{
    unsigned long long nb_to_put = redirect_unsigned(details, arguments);
    int final_conv_size = my_get_u_total_size(nb_to_put, details);
    char *final_str = malloc(sizeof(char) * final_conv_size + 1);

    if (final_str == NULL)
        return (-84);
    my_str_initialise(final_str, final_conv_size);
    mega_save_nbr(final_str, nb_to_put, 10);
    add_precision(final_str, (details->precision));
    fill_width_uo(final_str, details);
    my_fdputs(final_str, fd);
    free(final_str);
    return (final_conv_size);
}
