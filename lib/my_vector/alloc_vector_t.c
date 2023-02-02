/*
** EPITECH PROJECT, 2022
** MY
** File description:
** alloc_vector_t
*/

#include <stdlib.h>
#include "newmy.h"
#include "my_vector.h"

vector_t *alloc_vector_t(unsigned int size)
{
    vector_t *vector = malloc(sizeof(vector_t));

    vector->size = size;
    vector->coords = malloc(sizeof(double) * (size));
    if (vector->coords == NULL) {
        free(vector);
        my_putsterr("alloc_vector_t: malloc failed, returning NULL\n");
        return (NULL);
    }
    for (unsigned int i = 0; i < size; i++) {
        vector->coords[i] = 0.0;
    }
    return (vector);
}
