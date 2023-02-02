/*
** EPITECH PROJECT, 2022
** Fill width
** File description:
** sub-function for my_printf that fills (if necessary)
** the field of given width for a printf conversion
*/

#include <stdlib.h>
#include "my_printf.h"
#include "my.h"

int fill_width_u(char *final_str, conv_det_t *det)
{
    int len = my_strlen(final_str);
    int chars_to_add = det->width - len;
    char filler = ' ';

    if (chars_to_add <= 0) {
        return (0);
    }
    if (det->zero_flag == 1) {
        filler = '0';
    }
    if (det->dash_flag == 0) {
        my_shift_str(final_str, chars_to_add);
    }
    len = my_strlen(final_str);
    for (int i = 0; i < chars_to_add; i++)
        final_str[len + i] = filler;
    return (0);
}
