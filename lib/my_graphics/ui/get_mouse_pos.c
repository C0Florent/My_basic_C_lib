/*
** EPITECH PROJECT, 2023
** get mouse pos
** File description:
** Function to read the mouse position
** on a renderwindow even through resizing
*/

#include <SFML/Window/Event.h>

sfVector2f get_mouse_pos(sfEvent const *event)
{
    sfVector2f ret;

    switch (event->type) {
    case sfEvtMouseButtonPressed:
    case sfEvtMouseButtonReleased:
        ret.x = event->mouseButton.x;
        ret.y = event->mouseButton.y;
        break;
    case sfEvtMouseMoved:
        ret.x = event->mouseMove.x;
        ret.y = event->mouseMove.y;
        break;
    default:
        ret.x = -84;
        ret.y = -84;
        break;
    }
    return (ret);
}

// Scale should be (initial_size / current_size) i.e. the reduction scale
sfVector2f get_scaled_mouse_pos(sfEvent const *event, sfVector2f scale)
{
    sfVector2f ret = get_mouse_pos(event);

    ret.x *= scale.x;
    ret.y *= scale.y;
    return (ret);
}
