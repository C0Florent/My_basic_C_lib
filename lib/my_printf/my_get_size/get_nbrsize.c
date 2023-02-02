/*
** EPITECH PROJECT, 2022
** Get nbrsize
** File description:
** Returns the number of characters necessary to
** print a number in a given base
*/

#include "my.h"
#include <stdio.h>

int my_get_nbrsize(unsigned long long nb, int base)
{
    int size = 0;

    if (base < 2)
        return (-84);
    for (size = 0; nb != 0; size++)
        nb = nb / base;
    return (size);
}
