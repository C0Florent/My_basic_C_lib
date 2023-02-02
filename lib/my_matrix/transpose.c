/*
** EPITECH PROJECT, 2022
** Transpose matrix
** File description:
** sets the transpose of src into dest
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include "my_matrix.h"

static void put_error_message(int error)
{
    switch (error) {
    case 1:
        dprintf(2, "matrix_transpose: src or dest is null\n");
        break;
    case 2:
        dprintf(2, "matrix_transpose: src and dest are of different size\n");
        break;
    case 3:
        dprintf(2, "matrix_transpose: not transposing a non-square matrix\n");
        break;
    }
}

static bool check_error(matrix_t const *src, matrix_t const *dest)
{
    int error = 0;

    if (src == NULL || dest == NULL) {
        error = 1;
    }
    if (error == 0) {
        if (src->height != dest->height || src->width != dest->width) {
            error = 2;
        }
        if (src->height != src->width) {
                error = 3;
        }
    }
    if (error != 0) {
        put_error_message(error);
        return (1);
    }
    return (0);
}

void transpose(matrix_t *src, matrix_t *dest)
{
    matrix_t *dup;

    if (check_error(src, dest) == 1) {
        return;
    }
    dup = matrix_dup(src);
    for (unsigned int i = 0; i < src->height; i++) {
        for (unsigned int j = 0; j < src->width; j++) {
            dest->coords[i][j] = dup->coords[j][i];
        }
    }
    free_matrix_t(dup);
}
