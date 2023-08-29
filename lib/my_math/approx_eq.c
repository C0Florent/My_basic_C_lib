/*
** EPITECH PROJECT, 2022
** MY
** File description:
** approx_eq
*/

#include "my.h"

bool approx_eq(double a, double b, int precision)
{
    double diff = a - b;
    double prec = my_compute_float_power(10, -precision);

    if (ABS(diff) < prec) {
        return (true);
    } else {
        return (false);
    }
}
