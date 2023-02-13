/*
** EPITECH PROJECT, 2022
** my_put_conv_c
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf_internal.h"

int my_put_conv_c(conv_det_t *details, va_list *arguments)
{
    int spaces_to_print = details->width - 1;
    char to_print = (char)(va_arg(*arguments, int));

    if (details->dash_flag) {
        my_putchar(to_print);
    }
    for (int i = 0; i < spaces_to_print - 1; i++) {
        my_putchar(' ');
    }
    if (!details->dash_flag) {
        my_putchar(to_print);
    }
    return (details->width);
}
