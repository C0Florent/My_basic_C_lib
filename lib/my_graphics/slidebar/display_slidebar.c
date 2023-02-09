/*
** EPITECH PROJECT, 2023
** Display slidebar
** File description:
** Function to display a slibar_t structure
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdio.h>
#include "my_slidebar.h"

void display_slidebar(sfRenderWindow *window, slidebar_t const *slidebar)
{
    sfRenderWindow_drawRectangleShape(window, slidebar->bar, NULL);
    sfRenderWindow_drawRectangleShape(window, slidebar->cursor, NULL);
}
