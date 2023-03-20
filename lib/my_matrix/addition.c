/*
** EPITECH PROJECT, 2023
** Addition
** File description:
** File containing the function for matrix addition
*/

#include <stdio.h>
#include "my_macros.h"
#include "my_matrix.h"

static bool check_errors(matrix_t const *m1,
    matrix_t const *m2, matrix_t const *res)
{
    if (m1 == NULL || m2 == NULL || res == NULL) {
        dprintf(2, "addition: NULL parameter\n");
        return (EXIT_FAILURE);
    }
    if (m1->height != m2->height) {
        dprintf(2, "addition: cannot add two different-sized matrices\n");
        return (EXIT_FAILURE);
    }
    if (m1->height != res->height) {
        dprintf(2, "addition: result has differant size from the operands\n");
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

void addition(matrix_t const *m1, matrix_t const *m2, matrix_t *res)
{
    if (check_errors(m1, m2, res) == EXIT_FAILURE) {
        return;
    }
    for (unsigned int i = 0 ; i < m1->height; i++) {
        for (unsigned int j = 0; j < m1->width; j++) {
            res->coords[i][j] = m1->coords[i][j] + m2->coords[i][j];
        }
    }
}
