/*
** EPITECH PROJECT, 2022
** Scalar
** File description:
** Multiplies all the terms (?) of a matrix by
** a number (matrix × real product)
*/

#include <stdio.h>
#include "my_matrix.h"

void scalar(matrix_t *m, double scale)
{
    for (unsigned int i = 0; i < m->height; i++) {
        for (unsigned int j = 0; j < m->width; j++) {
            m->coords[i][j] = m->coords[i][j] * scale;
        }
    }
}
