/*
** EPITECH PROJECT, 2022
** My get i/d total size
** File description:
** Given the core size of int (i/d) conversion, and the
** field width, returns the total size of the conversion
*/

#include "my.h"
#include "my_printf.h"

int my_get_di_total_size(long long nb, conv_det_t *details)
{
    int core_size = my_get_di_core_size(nb, details);
    if (core_size > details->width)
        return (core_size);
    else
        return (details->width);
}

int my_get_di_core_size(long long int nb, conv_det_t *details)
{
    int size = my_get_nbrsize(ABS(nb), 10);
    int precision = details->precision;
    if (precision > size)
        size = precision;
    if (nb < 0)
        size++;
    else if (details->plus_flag == 1 || details->space_flag == 1)
        size++;
    return (size);
}
