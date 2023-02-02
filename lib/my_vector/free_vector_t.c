/*
** EPITECH PROJECT, 2022
** MY
** File description:
** free_vector_t
*/

#include <stdlib.h>
#include "my_vector.h"

void free_vector_t(vector_t *vector)
{
    free(vector->coords);
    free(vector);
}
