/*
** EPITECH PROJECT, 2022
** my_put_conv_p
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_put_conv_p(conv_det_t *details, va_list *arguments, int *count)
{
    details->len_modifier[0] = 'v';
    details->len_modifier[1] = '*';
    details->is_alt_form = 1;
    return (my_put_conv_x(details, arguments, count));
}
