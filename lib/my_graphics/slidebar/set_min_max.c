/*
** EPITECH PROJECT, 2023
** slidebar_set_min_max
** File description:
** Function to set the minimum and maximum values for a slidebar
*/

#include "my_graphics.h"

void slidebar_set_min_max_values(slidebar_t *sb, float min, float max)
{
    sb->min_val = min;
    sb->max_val = max;
}
