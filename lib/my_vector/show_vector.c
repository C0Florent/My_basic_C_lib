/*
** EPITECH PROJECT, 2022
** MY
** File description:
** show_vector
*/

#include <stdio.h>
#include "my_vector.h"

void show_vector(vector_t *vector)
{
    for (unsigned int i = 0; i < vector->size - 1; i++) {
        printf("%.2f\t", vector->coords[i]);
    }
    printf("%.2f\n", vector->coords[vector->size - 1]);
}
