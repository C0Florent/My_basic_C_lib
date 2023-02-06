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

void init_slidebar(slidebar_t *sb, sfVector2f bar_pos,
sfVector2f bar_size, sfVector2f cursor_size)
{
    sfVector2f cursor_pos = bar_pos;

    cursor_pos.x += bar_size.x / 2 - cursor_size.x / 2;
    cursor_pos.y += bar_size.y / 2 - cursor_size.y / 2;
    sfRectangleShape_setPosition(sb->bar, bar_pos);
    sfRectangleShape_setSize(sb->bar, bar_size);
    sfRectangleShape_setOutlineColor(sb->bar, sfBlack);
    sfRectangleShape_setOutlineThickness(sb->bar, 2);
    sfRectangleShape_setFillColor(sb->bar, sfColor_fromInteger(0x444444BB));
    sfRectangleShape_setOutlineColor(sb->cursor, sfBlack);
    sfRectangleShape_setOutlineThickness(sb->cursor, 2);
    sfRectangleShape_setPosition(sb->cursor, cursor_pos);
    sfRectangleShape_setSize(sb->cursor, cursor_size);
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
