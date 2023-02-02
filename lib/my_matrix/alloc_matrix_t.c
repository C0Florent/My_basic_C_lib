/*
** EPITECH PROJECT, 2022
** Alloc matrix_t
** File description:
** Function to allocate properly the memory space
** for a matrix_t structure
*/

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_matrix.h"

static void put_error_message(void)
{
    write(2, "in 'alloc_matrix_t': malloc failed. Perhaps you tried to allocat"
    "e too big of a matrix\nThe function will return a NULL pointer\n\n", 125);
}

void free_rows_if_failed(matrix_t *m, unsigned int nb_to_free)
{
    for (unsigned int i = 0; i < nb_to_free; i++) {
        free(m->coords[i]);
    }
}

//Returns true if a malloc error occured
bool alloc_rows(matrix_t *m)
{
    for (unsigned int i = 0; i < m->height; i++) {
        m->coords[i] = malloc(sizeof(double) * m->width);
        if (m->coords[i] == NULL) {
            put_error_message();
            free_rows_if_failed(m, i);
            free(m->coords);
            return (true);
        }
    }
    return (false);
}

matrix_t *alloc_matrix_t(unsigned int height, unsigned int width)
{
    matrix_t *m = malloc(sizeof(matrix_t));

    m->height = height;
    m->width = width;
    if (!height || !width) {
        m->coords = NULL;
        return (m);
    }
    m->coords = malloc(sizeof(double *) * height);
    if (m->coords == NULL) {
        put_error_message();
        free(m);
        return (NULL);
    }
    if (alloc_rows(m) == false) {
        set_to_id(m, true);
        return (m);
    } else
        return (NULL);
}
