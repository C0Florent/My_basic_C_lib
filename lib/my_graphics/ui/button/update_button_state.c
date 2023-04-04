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

static void read_mouse_event(button_t *button, sfEvent const *event,
    float mouse_x, float mouse_y)
{
    bool is_mouse_in = is_mouse_on_button(mouse_x, mouse_y, button);

    if (event->type == sfEvtMouseButtonReleased) {
        if (button->clicked) {
            button->falling_egde = true;
        }
        button->clicked = false;
    }
    if (event->type == sfEvtMouseButtonPressed && is_mouse_in) {
        button->rising_edge = true;
        button->clicked = true;
    }
    switch (is_mouse_in) {
    case true:
        button->state = (button->clicked ? PRESSED : HOVER);
        break;
    case false:
        button->state = RELEASED;
    }
}

static void handle_on_off_switch(button_t *button,
    float mouse_x, float mouse_y)
{
    if (button->falling_egde && is_mouse_on_button(mouse_x, mouse_y, button)) {
        button->on = !(button->on);
        if (button->on_ptr != NULL) {
            *button->on_ptr = !(*button->on_ptr);
        }
    }
}

void update_button_state(button_t *button, sfEvent const *event,
sfVector2f window_scale)
{
    sfVector2f mouse_pos;

    if (is_mouse_event(event, sfMouseLeft) == false) {
        return;
    }
    mouse_pos = get_scaled_mouse_pos(event, window_scale);
    read_mouse_event(button, event, mouse_pos.x, mouse_pos.y);
    handle_on_off_switch(button, mouse_pos.x, mouse_pos.y);
}
