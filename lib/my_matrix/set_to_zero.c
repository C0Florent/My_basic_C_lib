/*
** EPITECH PROJECT, 2022
** Set to zero
** File description:
** sets a matrix to the zero matrixof its size
*/

#include "my_matrix.h"

void set_to_zero(matrix_t *m)
{
    for (unsigned int i = 0; i < m->height; i++) {
        for (unsigned int j = 0; j < m->width; j++) {
            m->coords[i][j] = 0.0;
        }
    }
}
