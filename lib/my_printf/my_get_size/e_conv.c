/*
** EPITECH PROJECT, 2022
** My get e conv size
** File description:
** Returns the number of characters required to
** print a printf e conversion
*/

#include "my.h"
#include "my_printf_internal.h"

int my_get_e_total_size(double nb, conv_det_t *details)
{
    int size = details->precision + 5;

    if (details->precision != 0 || details->is_alt_form == 1)
        size++;
    if (my_float_int_part_size(nb, 10) >= 99)
        size++;
    if (nb < 0 || details->space_flag == 1 || details->plus_flag == 1)
        size++;
    if (details->width > size)
        size = details->width;
    return (size);
}
