/*
** EPITECH PROJECT, 2022
** my_put_conv_c
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_put_conv_c(conv_det_t *details, va_list *arguments, int *count)
{
    if (details->width > 1 && details->dash_flag != 0) {
        my_putchar(va_arg(*arguments, int));
        (*count)++;
        int a = details->width;
            for (int i = 0; i < a; i++) {
                my_putchar(' ');
                (*count)++;
            }
        return (0);
    } else {
        my_putchar(va_arg(*arguments, int));
        (*count)++;
    }
    return 0;
}
