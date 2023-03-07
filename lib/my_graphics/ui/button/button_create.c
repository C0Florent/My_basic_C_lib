/*
** EPITECH PROJECT, 2023
** Init button
** File description:
** Function to properly initialise a button_t structure
*/

#include <unistd.h>
#include <stdlib.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics/RectangleShape.h>
#include "my_ui.h"

static bool init_button(button_t *button, sfVector2f pos, sfVector2f size)
{
    button->rect = sfRectangleShape_create();

    if (button->rect == NULL) {
        write(2, "init_button: could not create rectangle\n", 40);
        free(button);
        return (EXIT_FAILURE);
    }
    button->state = NONE;
    button->size = size;
    button->pos = pos;
    button->clicked = false;
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineColor(button->rect, sfBlack);
    sfRectangleShape_setOutlineThickness(button->rect, 2.2);
    return (EXIT_SUCCESS);
}

button_t *button_create(sfVector2f position, sfVector2f size)
{
    button_t *ret = malloc(sizeof(button_t));
    bool init_ret;

    if (ret == NULL) {
        write(2, "create_button: malloc error\n", 27);
        return (NULL);
    }
    init_ret = init_button(ret, position, size);
    if (init_ret == EXIT_FAILURE) {
        return (NULL);
    }
    return (ret);
}
