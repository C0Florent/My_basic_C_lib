/*
** EPITECH PROJECT, 2023
** Create slidebar
** File description:
** Function to properly create (allocate) a slidebar_t structure
*/

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_graphics.h"
#include "my_slidebar.h"

slidebar_t *allocate_slidebar(void)
{
    slidebar_t *ret = malloc(sizeof(slidebar_t));

    if (ret == NULL) {
        return (NULL);
    }
    ret->bar = sfRectangleShape_create();
    ret->cursor = sfRectangleShape_create();
    return (ret);
}

void init_slidebar(slidebar_t *sb, sfVector2f sb_pos,
sfVector2f bar_size, sfVector2f cursor_size)
{
    sb->center = sb_pos;
    sb->bar_size = bar_size;
    sb->value = 50;
    slidebar_set_bound_values(sb, 0, 100, RESET_NONE);
    sfRectangleShape_setOrigin(sb->bar, scalar_v2f(bar_size, 0.5));
    sfRectangleShape_setOrigin(sb->cursor, scalar_v2f(cursor_size, 0.5));
    sfRectangleShape_setPosition(sb->bar, sb_pos);
    sfRectangleShape_setPosition(sb->cursor, sb_pos);
    sfRectangleShape_setSize(sb->bar, bar_size);
    sfRectangleShape_setSize(sb->cursor, cursor_size);
    sfRectangleShape_setOutlineColor(sb->bar, sfBlack);
    sfRectangleShape_setOutlineColor(sb->cursor, sfBlack);
    sfRectangleShape_setOutlineThickness(sb->bar, 2);
    sfRectangleShape_setOutlineThickness(sb->cursor, 2);
    sfRectangleShape_setFillColor(sb->bar, sfColor_fromInteger(0x444444BB));
    sb->is_grabbed = false;
}

slidebar_t *create_slidebar(sfVector2f pos, sfVector2f bar_size)
{
    slidebar_t *ret = allocate_slidebar();
    sfVector2f cursor_size = vctr2f(bar_size.x / 10, bar_size.y * 1.2);

    if (ret == NULL) {
        return (NULL);
    }
    init_slidebar(ret, pos, bar_size, cursor_size);
    return (ret);
}
