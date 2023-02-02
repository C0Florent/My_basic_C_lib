/*
** EPITECH PROJECT, 2022
** Matrix determinant
** File description:
** Computes and returns as a double the determinant of a matrix
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_matrix.h"

static bool check_errors(matrix_t const *m)
{
    if (m == NULL) {
        dprintf(2, "determinant: matrix is null\n");
        return (true);
    }
    if (m->height != m->width) {
        dprintf(2, "determinant: matrix is not square\n");
        return (true);
    }
    return (false);
}

double compute_determinant_rec(matrix_t const *m)
{
    matrix_t *iterated_m;
    double determinant = 0;
    double new_term = 0;
    int new_mod = 0;
    double new_det = 0;

    if (m->width == 0) {
        return (1.0);
    }
    iterated_m = alloc_matrix_t(m->height - 1, m->width - 1);
    for (unsigned int i = 0; i < m->width; i++) {
        submatrix(m, 0, i, iterated_m);
        new_det = compute_determinant_rec(iterated_m);
        new_mod = (((i + 1) % 2) * 2 - 1);
        new_term = (new_mod * m->coords[0][i] * new_det);
        determinant += new_term;
    }
    free_matrix_t(iterated_m);
    return (determinant);
}

double determinant(matrix_t const *m)
{
    if (check_errors(m)) {
        return (-84.0);
    }
    return (compute_determinant_rec(m));
}
