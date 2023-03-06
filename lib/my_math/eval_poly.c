/*
** EPITECH PROJECT, 2023
** Eval poly
** File description:
** evaluates a polynomial at a certain value
*/

#include <stddef.h>
#include <stdbool.h>
#include <math.h>
#include "my_vector.h"
#include "newmy.h"
#include "my.h"

// Evaluates the sum{i = 0 -> coef_count}(coefs[i] * x^i)
double poly(vector_t *coefs, double x)
{
    double result = 0;

    if (coefs == NULL) {
        my_putsterr("in: poly(): vector_t *coefs is NULL");
        return (NAN);
    }
    for (unsigned int i = 0; i < coefs->size; i++) {
        result += coefs->coords[i] * my_compute_float_power(x, i);
    }
    return (result);
}
