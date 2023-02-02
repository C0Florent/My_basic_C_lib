/*
** EPITECH PROJECT, 2022
** my_put_conv_s
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"

static int cut_the_string (conv_det_t *convert, char *str)
{
    for (int i = 0; i < convert->precision; i++) {
        my_putchar(str[i]);
    }
    return 0;
}

int without_dash (conv_det_t *conv, int nb, int num, char *str)
{
    if (conv->dash_flag == 0 && conv->width > conv->precision
        && conv->precision < nb) {
        put_char_space(num);
        cut_the_string(conv, str);
    }
    if (conv->dash_flag == 0 && conv->width > conv->precision
        && conv->precision > nb) {
        put_char_space(num);
        my_putstr(str);
    }
    if (conv->dash_flag == 0 && conv->width <= conv->precision
        && conv->precision > nb && conv->width >= nb) {
        put_char_space(conv->width - nb);
        my_putstr(str);
    }
    return 0;
}

int with_dash (conv_det_t *conv, int nb, int num, char *str)
{
    if (conv->dash_flag == 1 && conv->width > conv->precision
        && conv->precision < nb) {
            cut_the_string(conv, str);
            put_char_space(num);
    }
    if (conv->dash_flag == 1
        && conv->width > conv->precision && conv->precision > nb) {
        my_putstr(str);
        put_char_space(num);
    }
    if (conv->dash_flag == 1 && conv->width <= conv->precision
        && conv->precision > nb && conv->width >= nb) {
        my_putstr(str);
        put_char_space(conv->width - nb);
    }
    return 0;
}

int basics_test (conv_det_t *convert, char *str, int nb, int *count)
{
    if (convert->dash_flag == 0 && convert->width == 0
        && convert->precision == -1)
        (*count) += my_putstr(str);
    if (convert->dash_flag == 1 && convert->width != 0
        && convert->precision == -1) {
        (*count) += my_putstr(str);
        if (nb > 0)
            (*count) += put_char_space(nb);
    }
    if (convert->dash_flag == 0 && convert->width != 0
        && convert->precision == -1 && nb > 0) {
        (*count) += put_char_space(nb);
        (*count) += my_putstr(str);
    }
    if (convert->dash_flag == 0 && convert->width != 0
        && nb < 0 && convert->precision == -1) {
        (*count) += my_putstr(str);
    }
    return 0;
}

int my_put_conv_s(conv_det_t *details, va_list *arguments, int *count)
{
    char *str = va_arg(*arguments, char *);
    int size_str = my_strlen(str);
    int size_space = details->width - size_str;
    int space = details->width - details->precision;

    basics_test(details, str, size_space, count);
    if (details->width != 0 && details->precision != -1) {
        with_dash(details, size_str, space, str);
        without_dash(details, size_str, space, str);
    }
    if (details->width == 0 && details->precision != -1) {
        if (details->precision < size_str)
            cut_the_string(details, str);
        if (details->precision > size_str) {
            my_putstr(str);
            (*count) += my_strlen(str);
        }
    }
    return 0;
}
