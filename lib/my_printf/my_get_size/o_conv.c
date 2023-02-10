/*
** EPITECH PROJECT, 2022
** My get i/d total size
** File description:
** Given the core size of int (i/d) conversion, and the
** field width, returns the total size of the conversion
*/

#include "my.h"
#include "my_printf_internal.h"

int my_get_o_total_size(unsigned long long nb, conv_det_t *details)
{
    int size = my_get_nbrsize(nb, 8);
    if (details->is_alt_form == 1)
        size++;
    if (details->precision > size)
        size = details->precision;
    if (details->width > size)
        size = details->width;
    return (size);
}
