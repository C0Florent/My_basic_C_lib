/*
** EPITECH PROJECT, 2022
** Matrix product
** File description:
** Contains all necessary functions for computing matrix products
*/

#include <stddef.h>
#include "my_matrix.h"

#include <stdio.h>

double calc_one_coord(matrix_t const *m1, matrix_t const *m2, int i, int j)
{
    double result = 0;

    for (unsigned int k = 0; k < m1->width; k++) {
        result += m1->coords[i][k] * m2->coords[k][j];
    }
    return (result);
}

void product(matrix_t *m1, matrix_t *m2, matrix_t *result)
{
    matrix_t *m1_cpy;
    matrix_t *m2_cpy;

    if (m1->width != m2->height) {
        dprintf(2, "product: inexistant product\n");
        return;
    }
    if (result->height != m1->height || result->width != m2->width) {
        dprintf(2, "product: incompatible result matrix\n");
        return;
    }
    m1_cpy = matrix_dup(m1);
    m2_cpy = matrix_dup(m2);
    for (unsigned int i = 0; i < m1->height; i++) {
        for (unsigned int j = 0; j < m2->width; j++) {
            result->coords[i][j] = calc_one_coord(m1_cpy, m2_cpy, i, j);
        }
    }
    free_matrix_t(m1_cpy);
    free_matrix_t(m2_cpy);
}
