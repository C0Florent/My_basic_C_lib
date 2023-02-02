/*
** EPITECH PROJECT, 2022
** Matrix_t free
** File description:
** function that frees properly a matrix_t struct
*/

#include <stdlib.h>
#include "my_matrix.h"

void free_matrix_t(matrix_t *m)
{
    for (unsigned int i = 0; i < m->height; i++) {
        free(m->coords[i]);
    }
    free(m->coords);
    free(m);
}
