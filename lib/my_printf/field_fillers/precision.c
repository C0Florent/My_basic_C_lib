/*
** EPITECH PROJECT, 2022
** Precision
** File description:
** sub-sub-function for my_printf that adds extra
** zeros if asked by the conversion details
*/

#include "my.h"

int add_precision(char *final_str, int precision)
{
    int lendiff = precision - my_strlen(final_str);

    if (lendiff <= 0)
        return (0);
    my_shift_str(final_str, lendiff);
    for (int i = 0; i < lendiff; i++)
        final_str[i] = '0';
    return (0);
}
