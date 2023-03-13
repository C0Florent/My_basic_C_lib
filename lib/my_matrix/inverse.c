/*
** EPITECH PROJECT, 2022
** Matrix inverse
** File description:
** Computes the inverse of a matrix
*/

#include <stdio.h>
#include "my_matrix.h"

static bool are_args_valid(matrix_t const *src, matrix_t const *dest)
{
    if (src == NULL || dest == NULL) {
        dprintf(2, "inverse: either src or dest is null\n");
        return (false);
    }
    if (src->height != src->width || src->width != dest->width ||
    src->height != dest->height) {
        dprintf(2, "inverse: invalid matrix size\n");
        return (false);
    }
    return (true);
}

int inverse(matrix_t const *src, matrix_t *dest)
{
    matrix_t *dup;
    double det;

    if (are_args_valid(src, dest) == false) {
        return (84);
    }
    dup = matrix_dup(src);
    det = determinant(dup);
    if (det == 0) {
        dprintf(2, "inverse: inexistant inverse (det = 0)\n");
        return (1);
    }
    comatrix(dup, dup);
    transpose(dup, dup);
    scalar(dup, 1 / det);
    matrix_copy(dup, dest);
    free_matrix_t(dup);
    return (0);
}
