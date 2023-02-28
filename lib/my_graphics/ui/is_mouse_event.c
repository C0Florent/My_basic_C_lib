/*
** EPITECH PROJECT, 2023
** Is mouse event.c
** File description:
** Function to check if a sfEvent refers to a mouse event
** (and even of a specific mouse button for press/release events)
*/

#include <stdbool.h>
#include <SFML/Window/Event.h>

bool is_mouse_event(sfEvent const *event, sfMouseButton accepted_click)
{
    switch (event->type) {
    case sfEvtMouseButtonPressed:
    case sfEvtMouseButtonReleased:
        if (event->mouseButton.button == accepted_click) {
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
