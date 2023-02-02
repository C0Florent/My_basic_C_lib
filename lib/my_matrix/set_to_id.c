/*
** EPITECH PROJECT, 2022
** Set to id
** File description:
** Sets a given to the identity matrix (if it is a square matrix)
*/

#include <unistd.h>
#include "my_matrix.h"

// Will print a warning on stderr if m is not square and silent is false
void set_to_id(matrix_t *m, bool silent)
{
    if (m->height != m->width) {
        if (!silent) {
            write(2, "set_to_id: warning: matrix is not square:"
            " it will be set to a zero matrix\n", 74);
        }
        set_to_zero(m);
        return;
    }
    for (unsigned int i = 0; i < m->height; i++) {
        for (unsigned int j = 0; j < m->width; j++) {
            m->coords[i][j] = (i == j);
        }
    }
}
