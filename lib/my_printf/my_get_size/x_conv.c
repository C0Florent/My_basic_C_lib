/*
** EPITECH PROJECT, 2022
** My_get_x_conv_size
** File description:
** Returns the number of characters required to
** print a %o printf conversion
*/

#include "my.h"
#include "my_printf.h"

int my_get_x_total_size(unsigned long long nb, conv_det_t *details)
{
    int size = my_get_nbrsize(nb, 16);

    if (details->precision > size)
        size = details->precision;
    if (details->is_alt_form == 1 && size != 0)
        size += 2;
    if (details->width > size)
        size = details->width;
    return (size);
}
