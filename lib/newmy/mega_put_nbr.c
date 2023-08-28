/*
** EPITECH PROJECT, 2022
** Display functions
** File description:
** Little bank of functions for mini-mini-printf
*/

#include <unistd.h>
#include "my.h"

static void my_print_nbr_rec(long long nb, unsigned char base, int *count)
{
    const char digits[16] = {'0', '1', '2', '3', '4',
    '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    long long rec_param = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        (*count)++;
    }
    rec_param = nb / base;
    if (nb == -9223372036854775807 - 1) {
        rec_param = -rec_param;
    }
    if (rec_param != 0) {
        my_print_nbr_rec(rec_param, base, count);
    }
    my_putchar(digits[ABS(nb % base)]);
    (*count)++;
}

int mega_put_nbr(long long nb, unsigned char base)
{
    int count = 0;

    if (base > 16 || base < 2)
        return (84);
    my_print_nbr_rec(nb, base, &count);

    return (count);
}
