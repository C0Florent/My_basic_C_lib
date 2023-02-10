/*
** EPITECH PROJECT, 2022
** My get u total size
** File description:
** Returns the total number of chars required to print a
** given unsigned number with conv u (using my_printf)
*/

#include "my.h"
#include "my_printf_internal.h"

int my_get_u_total_size(unsigned long long nb, conv_det_t *details)
{
    int size = my_get_nbrsize(nb, 10);

    if (details->precision > size)
        size = details->precision;
    if (details->width > size)
        size = details->precision;
    return (size);
}
