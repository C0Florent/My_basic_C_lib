/*
** EPITECH PROJECT, 2023
** Display button
** File description:
** Function to draw a button on the window's framebuffer
*/

#include <SFML/Graphics/RectangleShape.h>
#include <SFML/Graphics/RenderWindow.h>
#include "my_ui.h"

static void update_button_colour(button_t const *button)
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

void button_display(sfRenderWindow *wndw, button_t const *button)
{
    update_button_colour(button);
    sfRenderWindow_drawRectangleShape(wndw, button->rect, NULL);
}
