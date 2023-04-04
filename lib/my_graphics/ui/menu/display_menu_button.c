/*
** EPITECH PROJECT, 2023
** MY
** File description:
** display_menu_button
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_ui.h"

static void update_outline_colour(button_t const *button)
{
    switch (button->state) {
    case RELEASED:
        if (button->on == false) {
            sfRectangleShape_setOutlineColor(button->rect, sfWhite);
        } else {
            sfRectangleShape_setOutlineColor(button->rect, MY_LIGHTGREY);
        }
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

static void update_fill_colour(button_t const *button)
{
    switch (button->on) {
    case true:
        sfRectangleShape_setFillColor(button->rect, MY_LIGHTGREY);
        break;
    case false:
        sfRectangleShape_setFillColor(button->rect, sfWhite);
        break;
    }
}

void display_menu_button(sfRenderWindow *wndw, button_t const *button)
{
    update_outline_colour(button);
    update_fill_colour(button);
    sfRenderWindow_drawRectangleShape(wndw, button->rect, NULL);
}
