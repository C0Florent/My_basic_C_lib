/*
** EPITECH PROJECT, 2022
** Fill width
** File description:
** sub-function for my_printf that fills (if necessary)
** the field of given width for a printf conversion
*/

#include <stdlib.h>
#include "my_printf_internal.h"
#include "my.h"

int fill_width_x(char *final_str, conv_det_t *det)
{
    int len = my_strlen(final_str);
    int chars_to_add = det->width - len;
    char filler = ' ';
    int shift_start = 0;

    if (chars_to_add <= 0)
        return (0);
    if (det->zero_flag == 1) {
        filler = '0';
        if (final_str[1] == 'x') {
            shift_start = 2;
        }
    }
    if (det->dash_flag == 0)
        my_shift_str(&final_str[shift_start], chars_to_add);
    else
        shift_start = len;
    for (int i = 0; i < chars_to_add; i++)
        final_str[shift_start + i] = filler;
    return (0);
}
