/*
** EPITECH PROJECT, 2022
** My get float integer part size
** File description:
** Returns the number of digits required to put the
** integer part of a given float in a given base
*/

#include "my.h"
#include "my_printf.h"

int my_get_f_total_size(double nb, conv_det_t *details)
{
    int size = my_float_int_part_size(ABS(nb), 10);

    if (size < 1)
        size = 1;
    if (details->precision > 0)
        size += 1 + details->precision;
    if (details->precision == 0 && details->is_alt_form == 1)
        size++;
    if (nb < 0 || details->plus_flag == 1 || details->space_flag == 1)
        size++;
    if (details->width > size)
        size = details->width;
    return (size);
}
