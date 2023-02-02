/*
** EPITECH PROJECT, 2022
** my power rec
** File description:
** computes power function using a recursive function
*/

#include "my.h"

double my_compute_float_power(double nb, int p)
{
    double output = 0;

    if (p == 0) {
        return (1);
    }
    if (p > 0) {
        output = nb * my_compute_float_power(nb, (p - 1));
        return (output);
    }
    if (p < 0)
        return (1 / my_compute_float_power(nb, ABS(p)));
    return (0.0);
}
