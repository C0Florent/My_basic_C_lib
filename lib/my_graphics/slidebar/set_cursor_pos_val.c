/*
** EPITECH PROJECT, 2023
** slidebar_set_pos, set_val
** File description:
** Functions to move the slidebar's cursor to a position
*/

#include <SFML/Graphics/RectangleShape.h>
#include "my_graphics.h"

void slidebar_cursor_set_pos_from_mouse_pos(slidebar_t *sb,
sfMouseButtonEvent const *click_pos)
{
    slidebar_cursor_set_pos(sb, click_pos->x - sb->center.x);
}

void slidebar_cursor_set_pos(slidebar_t *sb, float pos)
{
    if (ABS(pos) > sb->bar_size.x / 2) {
        pos = (pos / ABS(pos)) * sb->bar_size.x / 2;
    }
    sb->cursor_pos = pos;
    sfRectangleShape_setPosition(sb->cursor,
        vctr2f(sb->center.x + pos, sb->center.y));
    sb->value = ((sb->max_val - sb->min_val) / sb->bar_size.x)
    * (pos + sb->bar_size.x / 2.0) + sb->min_val;
}
