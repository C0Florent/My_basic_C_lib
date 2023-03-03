/*
** EPITECH PROJECT, 2022
** read_conv.c
** File description:
** function that display the parameter
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_printf_internal.h"
#include "newmy.h"
#include "my.h"

void browse_conv(char *conv, conv_det_t *details, va_list *args)
{
    unsigned int i = 0;

    while (my_char_is_in_list(conv[i], " +0-#")) {
        read_flag(details, conv[i]);
        i++;
    }
    if (my_char_isnum(conv[i]) || conv[i] == '*') {
        read_width(&details->width, &i, &conv[i], args);
    }
    if (conv[i] == '.') {
        read_precision(&details->precision, &i, &conv[i], args);
    }
    if (my_char_is_in_list(conv[i], "hl")) {
        read_len_modifier(&details->len_modifier[0], &conv[i]);
    }
}

int read_conv(char const *conv, conv_det_t *conv_details, va_list *args)
{
    unsigned int len = 1;
    char *convert;

    initialise_structure(conv_details);
    while (!my_char_is_in_list(conv[len], "iduboxXfFeEcsp%") && conv[len++]);
    convert = my_strndup(&conv[1], len);
    browse_conv(convert, conv_details, args);
    conv_details->conversion = convert[len -1];
    free(convert);
    return (len);
}
