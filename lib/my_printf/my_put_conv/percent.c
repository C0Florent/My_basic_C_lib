/*
** EPITECH PROJECT, 2022
** percent.c
** File description:
** display the percent if is present
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf_internal.h"

int my_put_conv_percent(__attribute__((unused)) conv_det_t *details,
    __attribute__((unused)) va_list *arguments)
{
    my_putchar('%');
    return (1);
}
