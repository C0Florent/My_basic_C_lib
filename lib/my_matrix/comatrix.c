/*
** EPITECH PROJECT, 2022
** Comatrix
** File description:
** comatrix
*/

#include <stddef.h>
#include <stdio.h>
#include "my_matrix.h"

static bool check_errors(matrix_t const *src, matrix_t const *dest)
{
    if (src == NULL || dest == NULL) {
        dprintf(2, "comatrix: src or dest matrix is null\n");
        return (1);
    }
    if (src->height != src->width || src->width != dest->width ||
    src->height != dest->height) {
        dprintf(2, "comatrix: invalid matrix size");
        return (1);
    }
    return (0);
}

static void fill_com_coords(matrix_t const *src, matrix_t *dest)
{
    int mod;
    matrix_t *dup = matrix_dup(src);
    matrix_t *submatrix_buff = alloc_matrix_t(dup->height - 1, dup->width - 1);

    for (unsigned int i = 0; i < dup->height; i++) {
        for (unsigned int j = 0; j < dup->width; j++) {
            submatrix(dup, i, j, submatrix_buff);
            mod = ((i + j + 1) % 2) * 2 - 1;
            dest->coords[i][j] = determinant(submatrix_buff) * mod;
        }
    }
    free_matrix_t(dup);
    free_matrix_t(submatrix_buff);
}

void comatrix(matrix_t const *src, matrix_t *dest)
{
    if (check_errors(src, dest) == 1) {
        return;
    }
    if (src->width == 0) {
        return;
    }
    fill_com_coords(src, dest);
}
