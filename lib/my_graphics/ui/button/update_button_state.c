/*
** EPITECH PROJECT, 2023
** Update button state
** File description:
** Function to be called during the sfRenderWindow_pollEvent loop,
** to update the button's internal state depending on mouse actions
*/

#include <SFML/System/Vector2.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_ui.h"

bool is_mouse_on_button(float mouse_x, float mouse_y,
button_t const *button)
{
    sfFloatRect button_rect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_rect, mouse_x, mouse_y)) {
        return (true);
    } else {
        return (false);
    }
}

static void get_mouse_pos(float *x, float *y, sfEvent const *event)
{
    switch (event->type) {
    case sfEvtMouseButtonPressed:
    case sfEvtMouseButtonReleased:
        *x = event->mouseButton.x;
        *y = event->mouseButton.y;
        break;
    case sfEvtMouseMoved:
        *x = event->mouseMove.x;
        *y = event->mouseMove.y;
        break;
    default:
        break;
    }
}

static void read_mouse_event(button_t *button, sfEvent const *event,
    float mouse_x, float mouse_y)
{
    static bool click_on = false;
    bool is_mouse_in = is_mouse_on_button(mouse_x, mouse_y, button);

    if (event->type == sfEvtMouseButtonReleased) {
        click_on = false;
    }
    if (event->type == sfEvtMouseButtonPressed && is_mouse_in) {
        click_on = true;
    }
    switch (is_mouse_in) {
    case true:
        button->state = (click_on ? PRESSED : HOVER);
        break;
    case false:
        button->state = RELEASED;
    }
}

void update_button_state(button_t *button, sfEvent const *event)
{
    float mouse_x;
    float mouse_y;

    if (is_mouse_event(event, sfMouseLeft) == false) {
        return;
    }
    get_mouse_pos(&mouse_x, &mouse_y, event);
    read_mouse_event(button, event, mouse_x, mouse_y);
}
