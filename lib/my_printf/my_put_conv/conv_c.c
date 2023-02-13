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
    unsigned int count = 0;

    if (details->width > 1 && details->dash_flag != 0) {
        my_putchar(va_arg(*arguments, int));
        count++;
            for (int i = 0; i < details->width; i++) {
                my_putchar(' ');
                count++;
            }
        return (count);
    } else {
        my_putchar(va_arg(*arguments, int));
        count++;
    }
    return (count);
}
