/*
** EPITECH PROJECT, 2022
** my power rec
** File description:
** computes power function using a recursive function
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int output = 0;

    if (p == 0) {
        return (1);
    }
    if (p > 0) {
        output = nb * my_compute_power_rec(nb, (p - 1));
        return (output);
    }
    return (0);
}
