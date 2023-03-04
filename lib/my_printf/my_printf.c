/*
** EPITECH PROJECT, 2022
** MY PRINTF
** File description:
** A homemade version of printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include "my_printf_internal.h"

int my_vdprintf(int fd, char const *format, va_list *arg)
{
    conv_det_t conv_details;
    int charcount = 0;

    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] != '%') {
            write(fd, &format[i], 1);
            charcount++;
        } else {
            i += read_conv(&format[i], &conv_details, arg);
            clean_struct(&conv_details);
            redirect_to_right_conv(&conv_details, arg, &charcount, fd);
        }
    }
    return (charcount);
}

int my_dprintf(int fd, char const *format, ...)
{
    va_list arg;
    int charcount;

    va_start(arg, *format);
    charcount = my_vdprintf(fd, format, &arg);
    va_end(arg);
    return (charcount);
}

int my_vprintf(char const *format, va_list *arg)
{   
    int charcount;

    charcount = my_vdprintf(1, format, arg);
    return (charcount);
}

int my_printf(char const *format, ...)
{
    va_list arg;
    int charcount;

    va_start(arg, *format);
    charcount = my_vprintf(format, &arg);
    va_end(arg);
    return (charcount);
}
