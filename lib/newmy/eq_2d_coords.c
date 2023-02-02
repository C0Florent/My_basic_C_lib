/*
** EPITECH PROJECT, 2022
** 2d coords eq
** File description:
** checks if 2 _2d_coords_t structures refer
** to the exact same coordinates on both axes
*/

#include <stdbool.h>
#include "newmy.h"

bool eq_2d_coords(_2d_coords_t const *c1, _2d_coords_t const *c2)
{
    if (c1->x == c2->x && c1->y == c2->y) {
        return (true);
    } else {
        return (false);
    }
}
