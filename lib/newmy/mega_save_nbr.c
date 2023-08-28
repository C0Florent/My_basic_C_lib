/*
** EPITECH PROJECT, 2022
** Display functions
** File description:
** Little bank of functions for mini-mini-printf
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"

void my_save_nbr_rec(char *buf, unsigned long long nb,
unsigned char base, int *count)
{
    const char digits[16] = {'0', '1', '2', '3', '4',
    '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned long long rec_param = nb / base;

    if (rec_param != 0) {
        my_save_nbr_rec(buf, rec_param, base, count);
    }
    my_charcat(buf, digits[nb % base]);
    (*count)++;
}

int mega_save_nbr(char *buf, unsigned long long nb, unsigned char base)
{
    int count = 0;

    if (nb == 0) {
        return (0);
    }
    if (base > 16 || base < 2) {
        return (-84);
    }
    my_save_nbr_rec(buf, nb, base, &count);
    return (count);
}
