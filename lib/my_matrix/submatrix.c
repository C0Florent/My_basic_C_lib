/*
** EPITECH PROJECT, 2022
** Submatrix
** File description:
** Returns the submatrix (the given matrix minus the given row and col)
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include "my_matrix.h"

static bool check_errors(matrix_t const *m, unsigned int row, unsigned int col,
matrix_t *submx)
{
    if (m == NULL || submx == NULL) {
        dprintf(2, "submatrix: matrix (or submatrix) is null\n");
        return (true);
    }
    if (submx->height != m->height - 1 || submx->width != m->width - 1) {
        dprintf(2, "submatrix: provided submatrix is of incorrect size\n");
        return (true);
    }
    if (row > m->height || col > m->width) {
        dprintf(2, "submatrix: provided row and col indices are incompatible"
        "with matrix size\n");
        return (true);
    }
    return (false);
}

void submatrix(matrix_t const *m, unsigned int row, unsigned int col,
matrix_t *submatrix)
{
    unsigned int matrix_h_index = 0;
    unsigned int matrix_w_index = 0;

    if (check_errors(m, row, col, submatrix) == true) {
        return;
    }
    for (unsigned int i = 0; i < m->height; i++) {
        if (i == row) {
            continue;
        }
        for (unsigned int j = 0; j < m->width; j++) {
            if (j == col) {
                continue;
            }
            submatrix->coords[matrix_h_index][matrix_w_index] = m->coords[i][j];
            matrix_w_index++;
        }
        matrix_h_index++;
        matrix_w_index = 0;
    }
}
