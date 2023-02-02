/*
** EPITECH PROJECT, 2022
** Matrix copy
** File description:
** copies a newly allocated matrix that is a copy of
** the one given as parameter
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_matrix.h"

void matrix_copy(matrix_t const *src, matrix_t *dest)
{
    if (src == NULL || dest == NULL) {
        dprintf(2, "matrix_copy: one of the two given is null\n");
        return;
    }
    if (src->height != dest->height || src->width != dest->width) {
        dprintf(2, "matrix_copy: could not proceed the copy: matrices have"
        "different sizes (%i;%i != %i;%i)\n", src->height, src->width,
        dest->height, dest->width);
        return;
    }
    for (unsigned int i = 0; i < src->height; i++) {
        for (unsigned int j = 0; j < src->width; j++) {
            dest->coords[i][j] = src->coords[i][j];
        }
    }
}

matrix_t *matrix_dup(matrix_t const *src)
{
    matrix_t *cpy = alloc_matrix_t(src->height, src->width);

    matrix_copy(src, cpy);
    return (cpy);
}
