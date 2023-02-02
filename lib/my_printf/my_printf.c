/*
** EPITECH PROJECT, 2022
** MY PRINTF
** File description:
** A homemade version of printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

int my_printf(char *format, ...)
{
    va_list arg;
    conv_det_t conv_details;
    int charcount = 0;

    va_start (arg, *format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
            charcount++;
        } else {
            i += read_conv(&format[i], &conv_details, &arg);
            clean_struct(&conv_details);
            redirect_to_right_conv(&conv_details, &arg, &charcount);
        }
    }
    va_end(arg);
    return 0;
}
