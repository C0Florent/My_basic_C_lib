/*
** EPITECH PROJECT, 2022
** my_put_conv_s
** File description:
** sub-function for my printf
*/

#include <unistd.h>
#include <stdarg.h>
#include "my.h"
#include "my_printf_internal.h"
#include "my_macros.h"

static int get_truncated_str_len(char *str, int precision)
{
    int len = my_strlen(str);

    if (precision >= 0 && precision < len) {
        return (precision);
    } else {
        return (len);
    }
}

int my_put_conv_s(conv_det_t *details, va_list *arguments, int fd)
{
    char *str = (va_arg(*arguments, char *));
    int len = get_truncated_str_len(str, details->precision);
    int spaces_to_print = MAX(details->width - len, 0);

    if (details->dash_flag) {
        write(fd, str, len);
    }
    for (int i = 0; i < spaces_to_print; i++) {
        write(fd, " ", 1);
    }
    if (!details->dash_flag) {
        write(fd, str, len);
    }
    return (spaces_to_print + len);
}
