/*
** EPITECH PROJECT, 2023
** Display button
** File description:
** Function to draw a button on the window's framebuffer
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_ui.h"

static void update_basic_button_colour(button_t const *button)
{
    switch (button->state) {
    case NONE:
        sfRectangleShape_setFillColor(button->rect, sfBlue);
        break;
    case RELEASED:
        sfRectangleShape_setFillColor(button->rect, sfWhite);
        break;
    case HOVER:
        sfRectangleShape_setFillColor(button->rect, sfGreen);
        break;
    case PRESSED:
        sfRectangleShape_setFillColor(button->rect, sfRed);
        break;
    }
}

static void update_on_off_button_colour(button_t const *button)
{
    switch (button->state) {
    case RELEASED:
        sfRectangleShape_setOutlineColor(button->rect, sfBlack);
        break;
    case HOVER:
    case PRESSED:
        sfRectangleShape_setOutlineColor(button->rect, sfYellow);
        break;
    default:
        break;
    }
    switch (button->on) {
    case true:
        sfRectangleShape_setFillColor(button->rect, sfCyan);
        break;
    case false:
        sfRectangleShape_setFillColor(button->rect, sfMagenta);
    }
}

void button_display(sfRenderWindow *wndw, button_t const *button)
{
    switch (button->type) {
    case BASIC:
        update_basic_button_colour(button);
        break;
    case ON_OFF:
        update_on_off_button_colour(button);
    }
    sfRenderWindow_drawRectangleShape(wndw, button->rect, NULL);
}
