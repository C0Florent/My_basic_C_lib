/*
** EPITECH PROJECT, 2023
** Button destroy
** File description:
** Function to properly destroy (free) a button_t structure
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_ui.h"

void button_destroy(button_t *button)
{
    if (button == NULL) {
        return;
    }
    sfRectangleShape_destroy(button->rect);
    free(button);
}
