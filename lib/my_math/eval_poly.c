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

// Evaluates the polynomial whose coefficients are
// given in coefs, in ascending power order
double poly(vector_t *coefs, double x)
{
    double result;

    if (coefs == NULL || coefs->coords == NULL || coefs->size == 0) {
        my_putsterr("in: poly(): cannot compute because of input vector\n");
        return (NAN);
    }
    result = coefs->coords[coefs->size - 1];
    for (int i = coefs->size - 2; i >= 0; i--) {
        result *= x;
        result += coefs->coords[i];
    }
    return (result);
}
