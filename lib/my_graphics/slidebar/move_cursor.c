/*
** EPITECH PROJECT, 2023
** Move cursor
** File description:
** Function to move the cursor of a slidebar structure
*/

#include <stdbool.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_slidebar.h"


#include <stdio.h>

static bool is_click_on_cursor(slidebar_t *sb,
sfMouseButtonEvent const *mouse_pos)
{
    if (mouse_pos->x >= sb->center.x - sb->bar_size.x / 2
    && mouse_pos->x <= sb->center.x + sb->bar_size.x / 2
    && mouse_pos->y >= sb->center.y - sb->bar_size.y / 2
    && mouse_pos->y <= sb->center.y + sb->bar_size.y / 2) {
        return (true);
    } else {
        return (false);
    }
}

static bool is_able_to_move_cursor(slidebar_t *sb, sfEvent const *event)
{
    if (event->type == sfEvtMouseButtonReleased) {
        sb->is_grabbed = false;
        return (false);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        sb->is_grabbed = is_click_on_cursor(sb, &event->mouseButton);
        if (sb->is_grabbed) {
            slidebar_cursor_set_pos_from_mouse_pos(sb, &event->mouseButton);
        }
        return (false);
    }
    if (event->type == sfEvtMouseMoved) {
        return (sb->is_grabbed);
    }
    return (false);
}

static bool is_mouse_event(sfEvent const *event)
{
    switch (event->type) {
    case sfEvtMouseButtonPressed:
    case sfEvtMouseButtonReleased:
        if (event->mouseButton.button == sfMouseLeft) {
            return (true);
        } else {
            return (false);
        }
        break;
    case sfEvtMouseMoved:
        return (true);
    default:
        return (false);
    }
}

// This function needs to be called for each frame of rendered image,
// in order to properly update the sb's cursor position
void move_cursor(slidebar_t *sb, sfEvent const *event)
{
    if (is_mouse_event(event) == false) {
        return;
    }
    if (is_able_to_move_cursor(sb, event) == false) {
        return;
    }
    slidebar_cursor_set_pos(sb, event->mouseMove.x - sb->center.x);
}
