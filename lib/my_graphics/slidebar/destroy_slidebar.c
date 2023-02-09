/*
** EPITECH PROJECT, 2023
** destroy slidebar
** File description:
** function to destroy (free) a slidebar_t structure
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_slidebar.h"

void destroy_slidebar(slidebar_t *sb)
{
    sfRectangleShape_destroy(sb->bar);
    sfRectangleShape_destroy(sb->cursor);
    free(sb);
}
