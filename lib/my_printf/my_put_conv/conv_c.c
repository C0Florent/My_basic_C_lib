/*
** EPITECH PROJECT, 2022
** my_put_conv_c
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include "my_printf_internal.h"

int my_put_conv_c(conv_det_t *details, va_list *arguments, int fd)
{
    int spaces_to_print = details->width - 1;
    char to_print = (char)(va_arg(*arguments, int));

    if (details->dash_flag) {
        write(fd, &to_print, 1);
    }
    for (int i = 0; i < spaces_to_print - 1; i++) {
        write(fd, " ", 1);
    }
    if (!details->dash_flag) {
        write(fd, &to_print, 1);
    }
    return (details->width);
}
