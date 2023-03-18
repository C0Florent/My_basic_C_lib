/*
** EPITECH PROJECT, 2023
** Display option button
** File description:
** Display function for the option buttons in a dropdown menu
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_ui.h"

static void update_outline_colour(button_t const *button)
{
    switch (button->state) {
    case RELEASED:
        sfRectangleShape_setOutlineColor(button->rect, sfWhite);
        break;
    case HOVER:
        sfRectangleShape_setOutlineColor(button->rect, MY_BLUE);
        break;
    case PRESSED:
        sfRectangleShape_setOutlineColor(button->rect, MY_SKYBLUE);
        break;
    default:
    }
}

void display_option_button(sfRenderWindow *wndw, button_t const *button)
{
    update_outline_colour(button);
    sfRenderWindow_drawRectangleShape(wndw, button->rect, NULL);
}
