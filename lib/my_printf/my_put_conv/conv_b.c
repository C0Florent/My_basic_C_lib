/*
** EPITECH PROJECT, 2022
** my_put_conv_b
** File description:
** sub-function for my printf
*/

#include <stdarg.h>
#include "my.h"
#include "my_printf.h"
#include "newmy.h"

int my_put_conv_b(__attribute__((unused)) conv_det_t *details,
    va_list *arguments, int *count)
{
    unsigned long long nb_to_put = va_arg(*arguments, int);
    int size = my_get_nbrsize(nb_to_put, 2);

    mega_put_nbr(nb_to_put, 2);
    (*count) += size;
    return (size);
}
